#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"Sysutil.h"

#define ELEMTYPE int
#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 4

typedef struct SeqList
{
	ELEMTYPE* base;//指向顺序表的指针
	int capacity;//顺序表的容量
	int size;//顺序表的元素个数
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

void SeqListInit(SeqList* pst)//初始化顺序表
{
	assert(pst);
	pst->base = (ELEMTYPE*)malloc(sizeof(ELEMTYPE)*SEQLIST_DEFAULT_SIZE);//开辟8个整型的空间
	assert(pst->base != NULL);//开辟成功
	memset(pst->base, 0, sizeof(ELEMTYPE)*SEQLIST_DEFAULT_SIZE);//将开辟的空间内元素初始化为0
	pst->capacity = SEQLIST_DEFAULT_SIZE;//顺序表的容量为8
	pst->size = 0;//刚开始，顺序表内没有元素
}

bool IsFull(SeqList* pst)//判满
{
	return pst->size >= pst->capacity;//若顺序表元素个数大于等于容量，返回真；否则，返回假
}

bool IsEmpty(SeqList* pst)//判空
{
	return pst->size == 0;//顺序表元素个数为0，返回真；否则，返回假
}

/*
bool _Inc(SeqList* pst)//扩容
{
	ELEMTYPE* new_base = (ELEMTYPE*)realloc(pst->base, sizeof(ELEMTYPE)*(pst->capacity + SEQLIST_INC_SIZE));
	if (new_base == NULL)
	{
		printf("扩容失败.\n");
		return false;
	}
	pst->base = new_base;
	pst->capacity += SEQLIST_DEFAULT_SIZE;
	return true;
}
*/
bool _Inc(SeqList* pst)
{
	//1.申请空间
	ELEMTYPE* new_base = (ELEMTYPE*)malloc(sizeof(ELEMTYPE)*(pst->capacity + SEQLIST_INC_SIZE));
	if (new_base == NULL)
	{
		printf("扩容失败.\n");
		return false;
	}
	//2.拷贝原始数据
	memcpy(new_base, pst->base, sizeof(ELEMTYPE)*pst->capacity);
	//3.释放旧空间
	free(pst->base);
	//4.改变base指向
	pst->base = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}

void SeqListPushBack(SeqList* pst, ELEMTYPE x)//尾插
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))//顺序表已满，且扩容失败
	{
		printf("顺序表已满，不能尾部插入元素.\n");
		return;
	}
	pst->base[pst->size++] = x;//顺序表中有size个数，尾插进来的数正好在下标为size的位置
	//插入数后，size+1
}

void SeqListPushFront(SeqList* pst, ELEMTYPE x)
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))//顺序表已满，且扩容失败
	{
		printf("顺序表已满，不能尾部插入元素.\n");
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
		printf("顺序表已空，不能尾部删除.\n");
		return;
	}
	pst->size--;
}

void SeqListPopFront(SeqList* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，不能头部删除.\n");
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
		printf("顺序表已满，无法按值插入.\n");
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
		printf("顺序表已满，无法按值插入.\n");
		return;
	}
	while (pos < 0 || pos > pst->size)
	{
		printf("输入的位置%d非法,%d无法按位置插入.\n", pos, x);
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
		printf("顺序表已空，不能按值删除.\n");
		return;
	}
	int pos = 0;
	while (pos < pst->size && pst->base[pos] != x)
	{
		pos++;
	}
	if (pos >= pst->size)
	{
		printf("要删除的数不存在.\n");
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
		printf("顺序表已空，不能按位置删除.\n");
		return;
	}
	if (pos < 0 || pos >= pst->size)
	{
		printf("要删除的位置非法，无法删除.\n");
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

void SeqListSort(SeqList* pst)//冒泡排序
{
	assert(pst);
	for (int i = 0; i < pst->size - 1; ++i)//size-1趟
	{
		for (int j = 0; j < pst->size - 1 - i; ++j)//每趟排size-1-i次
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
		printf("顺序表已空，不能删除.\n");
		return;
	}
	int pos = 0;
	while (pos <= pst->size-1)//要写<=，若写<,那么当顺序表中只有一个数时，就删不掉了
	{
		while (pos < pst->size && pst->base[pos] != x)
		{
			pos++;
		}
		if (pos >= pst->size)
		{
			printf("要删除的数字不存在.\n");
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
	SeqListSort(pst);//二分查找的前提：有序
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