/* ***********************************************************************

  > File Name: pthread_rwlock.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 19 Jan 2018 02:36:40 PM CST

 ********************************************************************** */

#include <pthread.h>

#include "../apue.h"

/*
 *使用读写锁实现一个作业队列：
 *由主线程向队列增加任务，工作线程并发的搜素队列
 *任务的删除可以由工作线程执行，也可以统一由主线程执行
 *在线程搜素业务的频率远远高于增加或删除作业时，使用读写锁才能改善性能
 *工作线程取出与线程匹配的作业后，执行作业不需要加锁
*/
struct jobs
{
	struct jobs * next;
	struct jobs * prev;
	pthread_t     j_id; //谁做这个任务
	int           a;
};

struct queue
{
	struct jobs      *q_head;
	struct jobs      *q_tail;
	pthread_rwlock_t  q_lock;
};


int queue_init(struct queue *qp)
{
	int err ;

	qp->q_head = NULL;
	qp->q_tail = NULL;

	err = pthread_rwlock_init(&qp->q_lock, NULL );
	if (err != 0)
		return err;
	return 0;
}


void jobs_insert(struct queue *qp, struct jobs * jp)
{
	pthread_rwlock_rwlock(&qp->q_lock);
	// 头插
	jp->next = qp->q_head;
	jp->prev = NULL;
	if(qp->q_head != NULL)
		qp->q_head->prev = jp;
	else
		qp->tail = jp;
	qp->q_head = jp;

	pthread_rwlock_unlock(&qp->q_lock);
}

void jobs_apped(struct queue* qp, struct jobs *jp)
{
	pthread_rwlock_rwlock(&qp->q_lock);
	//append 尾插
	jp->next = NULL;
	jp->prev = qp->tail;
	if(qp->q_tail != NULL){
		qp->q_tail->next = jp;
	} else
		qp->head = jp;
	qp->q_tail = jp;

	pthread_rwlock_unlock(&qp->q_lock);
}


void jobs_remove(struct queue * qp, struct jobs *jp)
{
	pthread_rwlock_rwlock(&qp->q_lock);
	if (jp == qp->q_head){//剁头
		qp->q_head = jp->next;
		if (qp->tail == jp){
			qp->tail = NULL;
		}
	} else if(jp == qp->tail) {//去尾
		qp->tail = jp->prev;
		jp->prev->next  = NULL;
	} else {
		jp->prev->next = jp->next;
		jp->next->prev = jp->prev;
	}
	pthread_rwlock_unlock(&qp->q_lock);
}

jobs * find_job(struct queue* qp,  pthread_t id)
{
	if(qp == NULL)
		return NULL;
	if(pthread_rwlock_rdlock(&qp->q_lock) != 0)
		return NULL;
	struct jobs * jp;
	for(jp = qp->q_head, jp != NULL; jp = jp->next){
		if (pthread_equal (jp->j_id, id) )
			break;
	}
	pthread_rwlock_unlock(&qp->q_lock);
	return jp;
}





















