#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"Sysutil.h"

#define ELEMTYPE int
#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 4

typedef struct SeqList
{
	ELEMTYPE* base;//ָ��˳����ָ��
	int capacity;//˳��������
	int size;//˳����Ԫ�ظ���
}SeqList;

void SeqListInit(SeqList* pst);
bool IsFull(SeqList* pst);
bool IsEmpty(SeqList* pst);
void SeqListPushBack(SeqList* pst, ELEMTYPE x);
void SeqListPushFront(SeqList* pst, ELEMTYPE x);
void SeqListShow(SeqList* pst);
void SeqListPopBack(SeqList* pst);
void SeqListPopFront(SeqList* pst);
size_t SeqListLength(SeqList* pst);
size_t SeqListCapacity(SeqList* pst);
void SeqListInsertByVal(SeqList* pst, ELEMTYPE* x);
void SeqListInsertByPos(SeqList* pst, int pos, ELEMTYPE x);
void SeqListDeleteByVal(SeqList* pst, ELEMTYPE x);
void SeqListDeleteByPos(SeqList* pst, int pos);
int SeqListFind(SeqList* pst, ELEMTYPE x);
void SeqListSort(SeqList* pst);
void SeqListReverse(SeqList* pst);
void SeqListRemoveAll(SeqList* pst, ELEMTYPE x);
void SeqListClear(SeqList* pst);
int SeqListFindBinary(SeqList* pst, ELEMTYPE x);
void SeqListDestroy(SeqList* pst);

///////////////////////////////////////////////////////////////

void SeqListInit(SeqList* pst)//��ʼ��˳���
{
	assert(pst);
	pst->base = (ELEMTYPE*)malloc(sizeof(ELEMTYPE)*SEQLIST_DEFAULT_SIZE);//����8�����͵Ŀռ�
	assert(pst->base != NULL);//���ٳɹ�
	memset(pst->base, 0, sizeof(ELEMTYPE)*SEQLIST_DEFAULT_SIZE);//�����ٵĿռ���Ԫ�س�ʼ��Ϊ0
	pst->capacity = SEQLIST_DEFAULT_SIZE;//˳��������Ϊ8
	pst->size = 0;//�տ�ʼ��˳�����û��Ԫ��
}

bool IsFull(SeqList* pst)//����
{
	return pst->size >= pst->capacity;//��˳���Ԫ�ظ������ڵ��������������棻���򣬷��ؼ�
}

bool IsEmpty(SeqList* pst)//�п�
{
	return pst->size == 0;//˳���Ԫ�ظ���Ϊ0�������棻���򣬷��ؼ�
}

/*
bool _Inc(SeqList* pst)//����
{
	ELEMTYPE* new_base = (ELEMTYPE*)realloc(pst->base, sizeof(ELEMTYPE)*(pst->capacity + SEQLIST_INC_SIZE));
	if (new_base == NULL)
	{
		printf("����ʧ��.\n");
		return false;
	}
	pst->base = new_base;
	pst->capacity += SEQLIST_DEFAULT_SIZE;
	return true;
}
*/
bool _Inc(SeqList* pst)
{
	//1.����ռ�
	ELEMTYPE* new_base = (ELEMTYPE*)malloc(sizeof(ELEMTYPE)*(pst->capacity + SEQLIST_INC_SIZE));
	if (new_base == NULL)
	{
		printf("����ʧ��.\n");
		return false;
	}
	//2.����ԭʼ����
	memcpy(new_base, pst->base, sizeof(ELEMTYPE)*pst->capacity);
	//3.�ͷžɿռ�
	free(pst->base);
	//4.�ı�baseָ��
	pst->base = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}

void SeqListPushBack(SeqList* pst, ELEMTYPE x)//β��
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))//˳���������������ʧ��
	{
		printf("˳�������������β������Ԫ��.\n");
		return;
	}
	pst->base[pst->size++] = x;//˳�������size������β����������������±�Ϊsize��λ��
	//��������size+1
}

void SeqListPushFront(SeqList* pst, ELEMTYPE x)
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))//˳���������������ʧ��
	{
		printf("˳�������������β������Ԫ��.\n");
		return;
	}
	for (int i = pst->size; i > 0; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[0] = x;
	pst->size++;
}

void SeqListShow(SeqList* pst)
{
	assert(pst);
	for (int i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void SeqListPopBack(SeqList* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ�����β��ɾ��.\n");
		return;
	}
	pst->size--;
}

void SeqListPopFront(SeqList* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ�����ͷ��ɾ��.\n");
		return;
	}
	for (int i = 1; i <= pst->size - 1; ++i)
	{
		pst->base[i - 1] = pst->base[i];
	}
	pst->size--;
}

size_t SeqListLength(SeqList* pst)
{
	assert(pst);
	return pst->size;
}

size_t SeqListCapacity(SeqList* pst)
{
	assert(pst);
	return pst->capacity;
}

void SeqListInsertByVal(SeqList* pst, ELEMTYPE* x)
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳����������޷���ֵ����.\n");
		return;
	}
	int pos = 0;
	/*
	for (int i = 0; i < pst->size; i++)
	{
		if (x >= pst->base[i])
		{
			pos++;
		}
		else
			break;
	}
	*/
	while (pos<pst->size && x > pst->base[pos])
	{
		pos++;
	}
	for (int i = pst->size - 1; i >= pos; --i)
	{
		pst->base[i + 1] = pst->base[i];
	}
	pst->base[pos] = x;
	pst->size++;
}

void SeqListInsertByPos(SeqList* pst, int pos, ELEMTYPE x)
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳����������޷���ֵ����.\n");
		return;
	}
	while (pos < 0 || pos > pst->size)
	{
		printf("�����λ��%d�Ƿ�,%d�޷���λ�ò���.\n", pos, x);
		return;
	}
	for (int i = pst->size - 1; i >= pos; --i)
		{
			pst->base[i + 1] = pst->base[i];
		}
	pst->base[pos] = x;
	pst->size++;
}

void SeqListDeleteByVal(SeqList* pst, ELEMTYPE x)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ����ܰ�ֵɾ��.\n");
		return;
	}
	int pos = 0;
	while (pos < pst->size && pst->base[pos] != x)
	{
		pos++;
	}
	if (pos >= pst->size)
	{
		printf("Ҫɾ������������.\n");
		return;
	}
	for (int i = pos+1; i < pst->size; ++i)
	{
		pst->base[i - 1] = pst->base[i];
	}
	pst->size--;
}

void SeqListDeleteByPos(SeqList* pst, int pos)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ����ܰ�λ��ɾ��.\n");
		return;
	}
	if (pos < 0 || pos >= pst->size)
	{
		printf("Ҫɾ����λ�÷Ƿ����޷�ɾ��.\n");
		return;
	}
	for (int i = pos + 1; i < pst->size; ++i)
	{
		pst->base[i - 1] = pst->base[i];
	}
	pst->size--;
}

int SeqListFind(SeqList* pst, ELEMTYPE x)
{
	assert(pst);
	/*int pos = 0;
	while (pos < pst->size && pst->base[pos] != x)
	{
		pos++;
	}
	if (pos >= pst->size)
		return -1;
	return pos;*/
	for (int i = 0; i < pst->size; ++i)
	{
		if (x == pst->base[i])
		{
			return i;
		}
	}
	return -1;
}

void SeqListSort(SeqList* pst)//ð������
{
	assert(pst);
	for (int i = 0; i < pst->size - 1; ++i)//size-1��
	{
		for (int j = 0; j < pst->size - 1 - i; ++j)//ÿ����size-1-i��
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

void SeqListReverse(SeqList* pst)
{
	assert(pst);
	int start = 0;
	int end = pst->size - 1;
	while (start < end)
	{
		ELEMTYPE tmp = pst->base[start];
		pst->base[start] = pst->base[end];
		pst->base[end] = tmp;
		start++;
		end--;
	}
}

void SeqListRemoveAll(SeqList* pst, ELEMTYPE x)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ�����ɾ��.\n");
		return;
	}
	int pos = 0;
	while (pos <= pst->size-1)//Ҫд<=����д<,��ô��˳�����ֻ��һ����ʱ����ɾ������
	{
		while (pos < pst->size && pst->base[pos] != x)
		{
			pos++;
		}
		if (pos >= pst->size)
		{
			printf("Ҫɾ�������ֲ�����.\n");
			return;
		}
		for (int i = pos; i < pst->size-1; ++i)
		{
			pst->base[i] = pst->base[i+1];
		}
		pst->size--;
	}
}

void SeqListClear(SeqList* pst)
{
	pst->size = 0;
}

int SeqListFindBinary(SeqList* pst, ELEMTYPE x)
{
	assert(pst);
	SeqListSort(pst);//���ֲ��ҵ�ǰ�᣺����
	int left = 0;
	int right = pst->size - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (x > pst->base[mid])
		{
			left = mid + 1;
		}
		else if (x < pst->base[mid])
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return -1;
}

void SeqListDestroy(SeqList* pst)
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = 0;
	pst->size = 0;
}

#endif