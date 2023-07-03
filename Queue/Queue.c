#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("mallco fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->phead == NULL)
	{
		assert(pq->ptail);
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->phead->next == NULL)
	{
		//一个节点 头尾置空
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//多个节点 头删
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->phead->data;

}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->ptail->data;
}
int QueueSize(Queue* pq)
{
	return pq->size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL
		&& pq->ptail == NULL;
}