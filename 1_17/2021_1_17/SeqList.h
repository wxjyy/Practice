#include "Sysutil.h"
//����˳����ʵ��

#define ELEMTYPE int
#define SEQLIST_DEFAULT_SIZE 8

typedef struct SeqList
{
	ELEMTYPE *base;
	size_t capacity;
	size_t size;
}SeqList;

bool IsFull(SeqList *pst);
bool IsEmpty(SeqList *pst);
void SeqListInit(SeqList *pst);
void SeqListPushBack(SeqList *pst, ELEMTYPE x);
void SeqListShow(SeqList *pst);
void SeqListPushFront(SeqList *pst, ELEMTYPE x);
void SeqListPopBack(SeqList *pst);
void SeqListPopFront(SeqList *pst);
size_t SeqListLength(SeqList *pst);
size_t SeqListCapacity(SeqList *pst);
void SeqListClear(SeqList *pst);
void SeqListDestroy(SeqList *pst);
int SeqListFind(SeqList *pst,ELEMTYPE x);
void SeqListSort(SeqList *pst);
void SeqListDeleteByVal(SeqList *pst,ELEMTYPE x);
void SeqListDeleteByPos(SeqList *pst, int pos);


///////////////////////////////////////////////////////
bool IsFull(SeqList* pst)//bool���ͣ��桢��
{
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList* pst)
{
	return pst->size == 0;
}

void SeqListInit(SeqList *pst)
{
	assert(pst);
	pst->base = (ELEMTYPE*)malloc(sizeof(ELEMTYPE) * SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);//���ٿռ�ɹ�
	memset(pst->base, 0, sizeof(ELEMTYPE)*SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}

void SeqListPushBack(SeqList *pst, ELEMTYPE x)
{
	assert(pst);
	if (IsFull(pst))//����
	{
		printf("˳���������%d����β������\n",x);
		return;
	}
	pst->base[pst->size++] = x;//˳����У����һ��Ԫ�ص��±�Ϊsize-1���±�Ϊsize��Ԫ�����������һ��Ԫ�صĺ��λ��
	//β���size��1
}

void SeqListShow(SeqList *pst)
{
	assert(pst);
	int i;
	for (i = 0; i < pst->size; i++)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void SeqListPushFront(SeqList *pst, ELEMTYPE x)
{
	if (IsFull(pst))//����
	{
		printf("˳���������%d����ͷ������\n",x);
		return;
	}
	for (int i = pst->size - 1; i >= 0; i--)
	{
		pst->base[i + 1] = pst->base[i];
	}
	pst->base[0] = x;//Ҫͷ���Ԫ�ط��ڵ�һ��������Ԫ�غ���
	pst->size++;
}

void SeqListPopBack(SeqList *pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ�����β��ɾ��\n");
		return;
	}
	pst->size--;
}

void SeqListPopFront(SeqList *pst)
{
	assert(pst);
	if (IsEmpty(pst))//or: assert(!IsEmpty(pst));
	{
		printf("˳����ѿգ�����ͷ��ɾ��\n");
		return;
	}
	for (int i = 1; i <= pst->size - 1; i++)
	{
		pst->base[i - 1] = pst->base[i];
	}
	pst->size--;
}

size_t SeqListLength(SeqList *pst)
{
	return pst->size;
}

size_t SeqListCapacity(SeqList *pst)
{
	return pst->capacity;
}

void SeqListClear(SeqList *pst)
{
	pst->size = 0;
}

void SeqListDestroy(SeqList *pst)
{
	free(pst->base);//�ͷŵ�base��ָ��Ŀռ䣨��malloc���ٵĶ�̬�ռ䣩
	pst->base = NULL;//Ԥ��Ұָ��
	pst->capacity = 0;
	pst->size = 0;
}

int SeqListFind(SeqList *pst, ELEMTYPE x)
{
	for (int i = 0; i < pst->size; i++)
	{
		if (x == pst->base[i])
			return i;
	}
	return -1;
}

void SeqListSort(SeqList *pst)
{
	for (int i = 0; i < pst->size - 1; i++)//size-1��
	{
		for (int j = 0; j < pst->size - 1 - i; j++)
		{
			if (pst->base[j]>pst->base[j + 1])
			{
				ELEMTYPE tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
			
		}
	}
}

//��ǰ
//void SeqListDeleteByVal(SeqList *pst, ELEMTYPE x)
//{
//	int index = SeqListFind(pst, x);
//	assert(index >= 0 && index < pst->size);
//	assert(pst);
//	if (index == -1)
//	{
//		printf("Ҫɾ����Ԫ��%d������\n",x);
//		return;
//	}
//	else
//	{
//		for (int i = index; i < pst->size-1; i++)
//		{
//			pst->base[i] = pst->base[i + 1];
//		}
//		pst->size--;
//	}
//}
//�򻯺�
void SeqListDeleteByVal(SeqList *pst, ELEMTYPE x)
{
	int index = SeqListFind(pst, x);
	if (index == -1)
	{
		printf("Ҫɾ����Ԫ��%d������\n", x);
		return;
	}
	else
	{
		SeqListDeleteByPos(pst, index);
	}
}

void SeqListDeleteByPos(SeqList *pst, int pos)
{
	//�ж�λ�õĺϷ���
	assert(pos >= 0 && pos < pst->size);
	assert(pst);
	for (int i = pos; i < pst->size - 1; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}