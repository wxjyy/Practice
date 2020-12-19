#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//练习使用库函数，qsort排序各种类型的数据
# if 0
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void test_int()
{
	int arr[5] = { 3, 5, 2, 4, 1 };
	qsort(arr, 5, 4, cmp_int);
}


struct stu
{
	char name[20];
	int age;
};
void cmp_struct_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
void test_struct()
{
	struct stu s[3] = { { "zhangsan", 18 }, { "lisi", 20 }, { "wangwu", 12 } };
	qsort(s, 3, sizeof(struct stu), cmp_struct_by_name);
}

int cmp_char(const void* e1, const void* e2)
{
	return *(char*)e1 - *(char*)e2;
}
void test_char()
{
	char arr[] = "cdfaeb";
	qsort(arr, strlen(arr), 1, cmp_char);
}

int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 < *(float*)e2)
	{
		return -1;
	}
	else if (*(float*)e1 == *(float*)e2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void test_float()
{
	float arr[5] = { 0.3, 3.1, 2.8, 0.7, 3.2 };
	qsort(arr, 5, 4, cmp_float);
}
int main()
{
	test_float();
	test_int();
	test_struct();
	test_char();
	
	return 0;
}
# endif

//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
#define ROW 3
#define COL 4
int Find(int arr[ROW][COL],int num)
{
	int i = 0;
	int j = COL - 1;
	int tmp = arr[i][j];
	while (i < ROW && j >= 0)
	{
		if (num < tmp)
		{
			tmp = arr[i][--j];
		}
		else if(num > tmp)
		{
			tmp = arr[++i][j];
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int num = 0;
	scanf("%d", &num);
	int ret = Find(arr, num);
	if (ret == 1)
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
	return 0;
}
