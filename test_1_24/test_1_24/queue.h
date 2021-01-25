#ifndef _QUEUE_H_
#define _QUEUE_H_

#include"Sysutil.h"

#define QueueElemType int

//链队列
typedef struct LinkQueueNode
{
	QueueElemType data;
	struct LinkQueueNode* next;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode* head;
	LinkQueueNode* tail;//指向队尾结点
}LinkQueue;

void LinkQueueInit(LinkQueue* pq);
void LinkQueueEn(LinkQueue* pq, QueueElemType x);
void LinkQueueDe(LinkQueue* pq);
void LinkQueueShow(LinkQueue* pq);
QueueElemType LinkQueueBack(LinkQueue* pq);
QueueElemType LinkQueueFront(LinkQueue* pq);
void LinkQueueDestroy(LinkQueue* pq);

////////////////////////////////////////////

void LinkQueueInit(LinkQueue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void LinkQueueEn(LinkQueue* pq, QueueElemType x)
{
	assert(pq);
	LinkQueueNode* s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = s;
	}
	else
	{
		pq->tail->next = s;
		pq->tail = s;
	}
}

void LinkQueueDe(LinkQueue* pq)
{
	assert(pq);
	if (pq->head != NULL)
	{
		LinkQueueNode* p = pq->head;
		pq->head = pq->head->next;
		if (pq->head == NULL)
		{
			pq->tail = NULL;//当链队中只有一个结点时，结点出栈后，尾部结点指针也要置空
		}
		free(p);
	}
}

void LinkQueueShow(LinkQueue* pq)
{
	assert(pq);
	LinkQueueNode* p = pq->head;
	while (p != NULL)
	{
		printf("%d<--", p->data);
		p = p->next;
	}
	printf("Nil.\n");
}

QueueElemType LinkQueueBack(LinkQueue* pq)
{
	assert(pq && pq->head);
	return pq->tail->data;
}

QueueElemType LinkQueueFront(LinkQueue* pq)
{
	assert(pq && pq->head);
	return pq->head->data;
}

void LinkQueueDestroy(LinkQueue* pq)
{
	assert(pq);
	LinkQueueNode* p = pq->head;
	while (p != NULL)
	{
		p = pq->head;
		pq->head = p->next;
		free(p);
	}
	pq->head = pq->tail = NULL;
}


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#define QUEUE_DEFAULT_SIZE 8

//顺序队列-->循环队列
typedef struct SeqQueue
{
	QueueElemType* base;
	size_t capacity;
	int front;
	int rear;
}SeqQueue;

void SeqQueueInit(SeqQueue* pq, int sz);
void SeqQueueDestroy(SeqQueue* pq);
void SeqQueueEn(SeqQueue* pq, QueueElemType x);
void SeqQueueDe(SeqQueue* pq);
void SeqQueueShow(SeqQueue* pq);
QueueElemType SeqQueueBack(SeqQueue* pq);
QueueElemType SeqQueueFront(SeqQueue* pq);

///////////////////////////////////////////////

void SeqQueueInit(SeqQueue* pq, int sz)
{
	assert(pq);
	pq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE;
	//pq->base = (QueueElemType*)malloc(sizeof(QueueElemType) * pq->capacity);
	pq->base = (QueueElemType*)malloc(sizeof(QueueElemType)* (pq->capacity + 1));
	//申请9个空间，只能用8个空间
	assert(pq->base != NULL);
	pq->front = pq->rear = 0;
}

void SeqQueueDestroy(SeqQueue* pq)
{
	assert(pq);
	free(pq->base);
	pq->base = NULL;
	pq->capacity = 0;
	pq->front = pq->rear = 0;
}

void SeqQueueEn(SeqQueue* pq, QueueElemType x)
{
	assert(pq);
	//if (pq->rear                    >= pq->capacity)
	if ((pq->rear+1)%(pq->capacity+1) == pq->front)//对capacity+1取模，得到0~capacity（如：x%10=0~9）
	{
		printf("队列已满，%d不能入队.\n", x);
		return;
	}

	//pq->base[pq->rear++] = x;
	pq->base[pq->rear] = x;
	pq->rear = (pq->rear + 1) % (pq->capacity + 1);
}

void SeqQueueDe(SeqQueue* pq)
{
	assert(pq);
	if (pq->front == pq->rear)
	{
		printf("队列已空，不能出队.\n");
		return;
	}
	//pq->front++;
	pq->front = (pq->front + 1) % (pq->capacity + 1);
}

void SeqQueueShow(SeqQueue* pq)
{
	assert(pq);
	//for (int i = pq->front; i < pq->rear; ++i)
	//{
	//	printf("%d<--", pq->base[i]);
	//}
	//printf("Nil.\n");
	for (int i = pq->front; i != pq->rear; )
	{
		printf("%d<--", pq->base[i]);
		i = (i + 1) % (pq->capacity + 1);
	}
	printf("Nil.\n");
}

QueueElemType SeqQueueBack(SeqQueue* pq)
{
	assert(pq && pq->front != pq->rear);//pq不空，且 队列不为空
	//return pq->base[pq->rear - 1];
	return pq->base[((pq->rear - 1) + (pq->capacity + 1)) % (pq->capacity + 1)];
}

QueueElemType SeqQueueFront(SeqQueue* pq)
{
	assert(pq && pq->front != pq->rear);
	return pq->base[pq->front];
}



#endif/*_QUEUE_H_*/