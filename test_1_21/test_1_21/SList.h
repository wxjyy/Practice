#ifndef _SLIST_H_
#define _SLIST_H_

#include"Sysutil.h"

#define ELEMTYPE int

//无头单链表
typedef struct SListNode
{
	ELEMTYPE data;
	struct SListNode* next;
}SListNode;

typedef struct SList
{
	SListNode* head;
}SList;

void SListInit(SList* plist);
void SListPushBack(SList* plist, ELEMTYPE x);
void SListShow(SList* plist);
void SListPopBack(SList* plist);
void SListPopFront(SList* plist);
int SListLength(SList* plist);
SListNode* SListFind(SList* plist, ELEMTYPE x);
void SListClear(SList* plist);
void SListDestroy(SList* plist);
void SListDeleteByVal(SList* plist, ELEMTYPE x);
void SListInsertByVal(SList* plist, ELEMTYPE x);
void SListReverse(SList* plist);
void SListSort(SList* plist);
void SListRemoveAll(SList* plist, ELEMTYPE x);

//////////////////////////////////////////////////////////////////
SListNode* _Buynode()
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = 0;
	s->next = NULL;
	return s;
}

void SListInit(SList* plist)
{
	plist->head = NULL;
}

void SListPushBack(SList* plist, ELEMTYPE x)
{
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;

	//查找链表的尾部
	SListNode* p = plist->head;
	//链表为空时，head为空，不能执行：head->next
	if (p == NULL)//插入的结点是第一个结点
		plist->head = s;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = s;
	}
}

void SListPushFront(SList* plist, ELEMTYPE x)
{
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;
	s->next = plist->head;
	plist->head = s;
}

void SListShow(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over.\n");
}

void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	SListNode* pre = NULL;
	if (plist->head == NULL)
	{
		printf("链表为空，不能尾部删除.\n");
		return;
	}
	else
	{
		if (p->next == NULL)//链表只有一个结点
		{
			plist->head = NULL;
		}
		else
		{
			while (p->next != NULL)//寻找末尾结点
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;
		}
		free(p);
	}
}

void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	if (p == NULL)
	{
		printf("链表为空，不能头部删除.\n");
		return;
	}
	else
	{
		plist->head = p->next;
		free(p);
	}
}

int SListLength(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

SListNode* SListFind(SList* plist, ELEMTYPE x)
{
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL && p->data != x)//p不为空，才能操作p->data,所以p！=NULL必须放在p->data！=x前面
//  while(p->data !=x && p != NULL)是错的
		p = p->next;
	return p;
}

void SListClear(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
}

void SListDestroy(SList* plist)
{
	SListClear(plist);
}

void SListDeleteByVal(SList* plist, ELEMTYPE x)
{
	assert(plist);
	SListNode* p = plist->head;
	SListNode* pre = NULL;
	while (p != NULL && p->data != x)
	{
		pre = p;
		p = p->next;
	}
	if (p == NULL)
	{
		printf("要删除的%d不存在.\n", x);
		return;
	}
	else
	{
		if (pre == NULL)//删除的是第一个结点
			plist->head = p->next;
		else
			pre->next = p->next;
		free(p);
	}
}

void SListInsertByVal(SList* plist, ELEMTYPE x)
{
	assert(plist);
	SListNode* p = plist->head;
	SListNode* pre = NULL;
	SListNode* s = _Buynode();
	s->data = x;
	if (plist->head == NULL)//当链表为空时，直接插入
		plist->head = s;
	else
	{
		while (p != NULL && p->data < x)
		{
			pre = p;
			p = p->next;
		}
		if (pre == NULL)//在链表头部插入
		{
			plist->head = s;
			s->next = p;
		 }
		else//在链表中间、尾部插入
		{
			s->next = pre->next;
			pre->next = s;
		}
	}
}

void SListReverse(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	SListNode* q = NULL;

	//只有一个结点或链表为空，则无需转置
	if (plist->head == NULL || plist->head->next == NULL)
		return;

	else
	{
		//1.切割第一个结点
		p = plist->head->next;
		plist->head->next = NULL;

		//2.头插剩余结点
		while (p != NULL)
		{
			q = p->next;
			p->next = plist->head;
			plist->head = p;
			p = q;
		}
	}
}

void SListSort(SList* plist)
{
	assert(plist);
	SListNode *p, *q;

	if (plist->head == NULL || plist->head->next == NULL)
		return;

	//断开链表
	p = plist->head->next;
	plist->head->next = NULL;

	//将剩下结点按值插入（相当于排序）
	q = p;
	while (p != NULL)
	{
		q = p->next;

		SListNode* t = plist->head;
		SListNode* pre = NULL;
		while (t != NULL && p->data > t->data)//找到要插入的位置
		{
			pre = t;
			t = t->next;
		}
		if (pre == NULL)//在头部插入
		{
			p->next = plist->head;
			plist->head = p;
		}
		else
		{
			p->next = pre->next;
			pre->next = p;
		}

		p = q;
	}
}

void SListRemoveAll(SList* plist, ELEMTYPE x)
{
	assert(plist);
	SListNode *p, *pre;
	p = plist->head;
	pre = NULL;
	if (plist->head == NULL)
	{
		printf("链表为空，不能删除.\n");
		return;
	}
	while (p != NULL)
	{
			while (p != NULL && p->data != x)//找到要删除的位置
			{
				pre = p;
				p = p->next;
			}
			if (pre == NULL)//要删除的是第一个结点
			{
				plist->head = p->next;
				free(p);
				p = plist->head;
			}
			else
			{
				if (p != NULL)
				{
					pre->next = p->next;
					free(p);
					p = pre->next;
				}
				else//只剩一个结点了，且该结点不是要删除的
					return;
			}

	}

}


#endif/*_SLIST_H_*/