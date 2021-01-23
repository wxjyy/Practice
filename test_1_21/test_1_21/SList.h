#ifndef _SLIST_H_
#define _SLIST_H_

#include"Sysutil.h"

#define ELEMTYPE int

//��ͷ������
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

	//���������β��
	SListNode* p = plist->head;
	//����Ϊ��ʱ��headΪ�գ�����ִ�У�head->next
	if (p == NULL)//����Ľ���ǵ�һ�����
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
		printf("����Ϊ�գ�����β��ɾ��.\n");
		return;
	}
	else
	{
		if (p->next == NULL)//����ֻ��һ�����
		{
			plist->head = NULL;
		}
		else
		{
			while (p->next != NULL)//Ѱ��ĩβ���
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
		printf("����Ϊ�գ�����ͷ��ɾ��.\n");
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
	while (p != NULL && p->data != x)//p��Ϊ�գ����ܲ���p->data,����p��=NULL�������p->data��=xǰ��
//  while(p->data !=x && p != NULL)�Ǵ��
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
		printf("Ҫɾ����%d������.\n", x);
		return;
	}
	else
	{
		if (pre == NULL)//ɾ�����ǵ�һ�����
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
	if (plist->head == NULL)//������Ϊ��ʱ��ֱ�Ӳ���
		plist->head = s;
	else
	{
		while (p != NULL && p->data < x)
		{
			pre = p;
			p = p->next;
		}
		if (pre == NULL)//������ͷ������
		{
			plist->head = s;
			s->next = p;
		 }
		else//�������м䡢β������
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

	//ֻ��һ����������Ϊ�գ�������ת��
	if (plist->head == NULL || plist->head->next == NULL)
		return;

	else
	{
		//1.�и��һ�����
		p = plist->head->next;
		plist->head->next = NULL;

		//2.ͷ��ʣ����
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

	//�Ͽ�����
	p = plist->head->next;
	plist->head->next = NULL;

	//��ʣ�½�㰴ֵ���루�൱������
	q = p;
	while (p != NULL)
	{
		q = p->next;

		SListNode* t = plist->head;
		SListNode* pre = NULL;
		while (t != NULL && p->data > t->data)//�ҵ�Ҫ�����λ��
		{
			pre = t;
			t = t->next;
		}
		if (pre == NULL)//��ͷ������
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
		printf("����Ϊ�գ�����ɾ��.\n");
		return;
	}
	while (p != NULL)
	{
			while (p != NULL && p->data != x)//�ҵ�Ҫɾ����λ��
			{
				pre = p;
				p = p->next;
			}
			if (pre == NULL)//Ҫɾ�����ǵ�һ�����
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
				else//ֻʣһ������ˣ��Ҹý�㲻��Ҫɾ����
					return;
			}

	}

}


#endif/*_SLIST_H_*/