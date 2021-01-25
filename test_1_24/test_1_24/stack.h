#ifndef _STACK_H_
#define _STACK_H_

#include"Sysutil.h"

#define StackElemType int
#define SEQSTACK_DEFAULT_SIZE 8

//˳��ջ
typedef struct SeqStack
{
	StackElemType* base; //ָ��ջ�ռ��ָ��
	size_t capacity; //ջ������
	int top; //ջ��ָ�루�±꣩
}SeqStack;

void SeqStackInit(SeqStack* pst, int sz);
bool IsFull(SeqStack* pst);
bool IsEmpty(SeqStack* pst);
void SeqStackPush(SeqStack* pst, StackElemType x);
void SeqStackShow(SeqStack* pst);
void SeqStackPop(SeqStack* pst);
StackElemType SeqStackTop(SeqStack* pst);
void SeqStackDestroy(SeqStack* pst);

//////////////////////////////////////////////////////

void SeqStackInit(SeqStack* pst, int sz)
{
	assert(pst);
	pst->capacity = sz > SEQSTACK_DEFAULT_SIZE ? sz : SEQSTACK_DEFAULT_SIZE;
	pst->base = (StackElemType*)malloc(sizeof(StackElemType) * pst->capacity);
	assert(pst->base);
	pst->top = 0;
}

bool IsFull(SeqStack* pst)
{
	assert(pst);
	return pst->top >= pst->capacity;
}

bool IsEmpty(SeqStack* pst)
{
	assert(pst);
	return pst->top == 0;
}

void SeqStackPush(SeqStack* pst, StackElemType x)
{
	assert(pst);
	if (IsFull(pst))
	{
		printf("ջ�ռ�������%d������ջ.\n", x);
		return;
	}
	pst->base[pst->top++] = x;//�Ƚ�x����top��ָ��Ŀռ䣬Ȼ��top++
}

void SeqStackShow(SeqStack* pst)
{
	assert(pst);
	for (int i = pst->top - 1; i >= 0; --i)
	{
		printf("%d\n", pst->base[i]);
	}
}

void SeqStackPop(SeqStack* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("ջ�ռ�Ϊ�գ����ܳ�ջ.\n");
		return;
	}
	pst->top--;
}

StackElemType SeqStackTop(SeqStack* pst)
{
	assert(pst && !IsEmpty(pst));
	return pst->base[pst->top - 1];//����дpst->top--������ջ��Ԫ�ؾͳ�ջ�ˡ�pst->top���ܸı�
}

void SeqStackDestroy(SeqStack* pst)
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

typedef struct LinkStackNode
{
	StackElemType data;
	struct LinkStackNode* next;
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode* head;
}LinkStack;

void LinkStackInit(LinkStack* pst);
void LinkStackPush(LinkStack* pst, StackElemType x);
void LinkStackPop(LinkStack* pst);
StackElemType LinkStackTop(LinkStack* pst);
void LinkStackShow(LinkStack* pst);
void LinkStackDestroy(LinkStack* pst);

/////////////////////////////////////////////////

void LinkStackInit(LinkStack* pst)
{
	assert(pst);
	pst->head = NULL;
}

void LinkStackPush(LinkStack* pst, StackElemType x)
{
	assert(pst);
	LinkStackNode* s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(s != NULL);
	s->data = x;

	s->next = pst->head;
	pst->head = s;
}

void LinkStackPop(LinkStack* pst)
{
	assert(pst);
	if (pst->head != NULL)
	{
		LinkStackNode* p = pst->head;
		pst->head = pst->head->next;
		free(p);
	}
}

void LinkStackShow(LinkStack* pst)
{
	assert(pst);
	LinkStackNode* p = pst->head;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

StackElemType LinkStackTop(LinkStack* pst)
{
	assert(pst && pst->head != NULL);
	return pst->head->data;
}

void LinkStackDestroy(LinkStack* pst)
{
	assert(pst);
	while (pst->head != NULL)
	{
		LinkStackNode* p = pst->head;
		pst->head = pst->head->next;
		free(p);
	}
}

#endif /*_STACK_H_*/