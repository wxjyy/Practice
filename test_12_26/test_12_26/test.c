#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//判断当前计算机的大小端存储
# if 0
int check_sys(void)
{
	union U
	{
		int a ;
		char ret;
	}u;
	u.a = 1;
	//大端 00 00 00 01
	//小端 01 00 00 00
	return u.ret;
	//ret与a共用一块内存空间，ret的位置就是a的第一个字节的位置
}
int main()
{
	int ret = check_sys();
	if (1 == ret)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
# endif

//void* malloc(size_t size);
# if 0
int main()
{
	int* p = (int*)malloc(40);
	//开辟40个字节的动态内存空间，并返回该空间的起始地址，地址类型为void*
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	free(p);
	p = NULL;
	return 0;
}
# endif

//void* calloc(size_t num, size_t size);
# if 0
int main()
{
	int* p = (int*)calloc(10, 4);
	if (p == NULL)
	{
		perror("calloc");
		return 1;
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	free(p);
	p = NULL;
	return 0;
}
# endif

//void* realloc(void* memblock, size_t size)
int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	//再加10个整型
	int* ptr = (int*)realloc(p, 80);
	//最好重新用一个指针接收，万一扩容失败，起码原来开辟的空间还能找到
	if (ptr != NULL)
	{
		p = ptr;
	}
	else
	{
		perror("realloc");
		return 1;
	}
	for (i = 10; i < 20; i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 20; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p = NULL;
	return 0;
}