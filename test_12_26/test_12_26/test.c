#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�жϵ�ǰ������Ĵ�С�˴洢
# if 0
int check_sys(void)
{
	union U
	{
		int a ;
		char ret;
	}u;
	u.a = 1;
	//��� 00 00 00 01
	//С�� 01 00 00 00
	return u.ret;
	//ret��a����һ���ڴ�ռ䣬ret��λ�þ���a�ĵ�һ���ֽڵ�λ��
}
int main()
{
	int ret = check_sys();
	if (1 == ret)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}
# endif

//void* malloc(size_t size);
# if 0
int main()
{
	int* p = (int*)malloc(40);
	//����40���ֽڵĶ�̬�ڴ�ռ䣬�����ظÿռ����ʼ��ַ����ַ����Ϊvoid*
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
	//�ټ�10������
	int* ptr = (int*)realloc(p, 80);
	//���������һ��ָ����գ���һ����ʧ�ܣ�����ԭ�����ٵĿռ仹���ҵ�
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