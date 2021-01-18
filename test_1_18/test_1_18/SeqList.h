#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "Sysutil.h"
//整个顺序表的实现

#define ELEMTYPE int
#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 4

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
int SeqListFind(SeqList *pst, ELEMTYPE x);
void SeqListSort(SeqList *pst);
void SeqListDeleteByVal(SeqList *pst, ELEMTYPE x);
void SeqListDeleteByPos(SeqList *pst, int pos);
void SeqListReverse(SeqList *pst);
void SeqListInsertByVal(SeqList *pst, ELEMTYPE x);
void SeqListInsertByPos(SeqList *pst, int pos, ELEMTYPE x);
int  SeqListFindBinary(SeqList *pst, ELEMTYPE x);
void SeqListRemoveAll(SeqList *pst, ELEMTYPE x);

///////////////////////////////////////////////////////
bool IsFull(SeqList* pst)//bool类型：真、假
{
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList* pst)
{
	return pst->size == 0;
}

//下划线表示这个函数只能是内部函数（只能在函数在的地方调用，不能在test.c里调用）
//1.用realloc扩容
//bool _Inc(SeqList *pst)
//{
//	assert(pst);
//	ELEMTYPE* new_base = (ELEMTYPE*)realloc(pst->base, sizeof(ELEMTYPE)*(pst->capacity + SEQLIST_DEFAULT_SIZE));
//	if (new_base == NULL)
//	{
//		printf("扩容失败\n");
//		return false;
//	}
//	pst->base = new_base;
//	pst->capacity += SEQLIST_INC_SIZE;
//	return true;
//}

//2.用malloc扩容
bool _Inc(SeqList *pst)
{
	//申请新空间
	ELEMTYPE* new_base = (ELEMTYPE*)malloc(sizeof(ELEMTYPE)*(pst->capacity + SEQLIST_INC_SIZE));
	if (new_base == NULL)
	{
		printf("扩容失败.\n");
		return false;
	}
	//拷贝数据
	memcpy(new_base, pst->base, sizeof(ELEMTYPE)*pst->capacity);
	//释放旧空间
	free(pst->base);
	//更改base指向
	pst->base = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}

void SeqListInit(SeqList *pst)
{
	assert(pst);
	pst->base = (ELEMTYPE*)malloc(sizeof(ELEMTYPE)* SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);//开辟空间成功
	memset(pst->base, 0, sizeof(ELEMTYPE)*SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}

void SeqListPushBack(SeqList *pst, ELEMTYPE x)
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))//判满   a&&b:当a为假时，不用看b了，结果就是假   因此IsFull要放在_Inc前（满了才扩容）
	{
		printf("顺序表已满，%d不能尾部插入\n", x);
		return;
	}
	pst->base[pst->size++] = x;//顺序表中，最后一个元素的下标为size-1，下标为size的元素正好是最后一个元素的后继位置
	//尾插后，size加1
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
	if (IsFull(pst) && !_Inc(pst))//判满
	{
		printf("顺序表已满，%d不能头部插入\n", x);
		return;
	}
	for (int i = pst->size - 1; i >= 0; i--)
	{
		pst->base[i + 1] = pst->base[i];
	}
	pst->base[0] = x;//要头插的元素放在第一个，其他元素后移
	pst->size++;
}

void SeqListPopBack(SeqList *pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，不能尾部删除\n");
		return;
	}
	pst->size--;
}

void SeqListPopFront(SeqList *pst)
{
	assert(pst);
	if (IsEmpty(pst))//or: assert(!IsEmpty(pst));
	{
		printf("顺序表已空，不能头部删除\n");
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
	free(pst->base);//释放掉base所指向的空间（由malloc开辟的动态空间）
	pst->base = NULL;//预防野指针
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
	for (int i = 0; i < pst->size - 1; i++)//size-1趟
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

//简化前
//void SeqListDeleteByVal(SeqList *pst, ELEMTYPE x)
//{
//	int index = SeqListFind(pst, x);
//	assert(index >= 0 && index < pst->size);
//	assert(pst);
//	if (index == -1)
//	{
//		printf("要删除的元素%d不存在\n",x);
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
//简化后
void SeqListDeleteByVal(SeqList *pst, ELEMTYPE x)
{
	int index = SeqListFind(pst, x);
	if (index == -1)
	{
		printf("要删除的元素%d不存在\n", x);
		return;
	}
	else
	{
		SeqListDeleteByPos(pst, index);
	}
}

void SeqListDeleteByPos(SeqList *pst, int pos)
{
	//判断位置的合法性
	assert(pos >= 0 && pos < pst->size);
	assert(pst);
	for (int i = pos; i < pst->size - 1; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

void SeqListReverse(SeqList *pst)
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

void SeqListInsertByVal(SeqList *pst, ELEMTYPE x)
{
	//插入前一定要有序
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，不能按值插入\n");
		return;
	}
	int pos = 0;
	while (pos < pst->size && x > pst->base[pos])
	{
		pos++;
	}
	for (int i = pst->size; i > pos; i--)//i>pos，不能是>=   当要插入的值比所有的值都大，就会插在尾部，此时pos=size，不会进入
										 //该循环，没有元素要移动
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}

void SeqListInsertByPos(SeqList *pst, int pos, ELEMTYPE x)
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，不能按位置插入\n");
		return;
	}
	if (pos<0 || pos>pst->size)
	{
		printf("插入的位置非法，%d不能按位置插入.\n");
		return;
	}
	for (int i = pst->size; i > pos; i--)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}

int  SeqListFindBinary(SeqList *pst, ELEMTYPE x)
{
	assert(pst);
	SeqListSort(pst);//二分查找一定要有序
	int left = 0;
	int right = pst->size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (pst->base[mid] == x)
		{
			return mid;
		}
		else if (pst->base[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList *pst, ELEMTYPE x)
{
	assert(pst);
	int p = 0;
	while (p < pst->size-1)
	{
		while (pst->base[p] != x && p < pst->size)
			{
				p++;
			}
		for (int i = p; i < pst->size; i++)
		{
			pst->base[i] = pst->base[i + 1];
		}
		pst->size--;
	}
	

}

#endif /* _SEQLIST_H_ */