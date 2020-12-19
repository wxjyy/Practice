#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//ð����������
# if 0
void bubble_sort(int* arr, int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)//����
	{
		//ÿ���ڲ�
		for (j = 0; j < sz - 1 - i; j++)//ÿ�˱ȽϵĶ���
		{
			if (arr[j]>arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}

	}
}

void print(int*arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 9, 8, 7, 5, 4, 6, 2, 3, 1, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	bubble_sort(arr, sz);
	print(arr, sz);
	return 0;
}
# endif

//��ģ��ʵ��qsort����������ð������
//void qsort (void* base, Ҫ������������������Ԫ�ص�ַ
//			size_t num,  Ҫ����������Ԫ�ظ���
//			size_t size, Ҫ����������ÿ��Ԫ�ص��ֽ���
//			int(*comp)(const void* e1, const void* e2) ����Ԫ�صıȽϷ�����e1>e2����>0�����֣�e1<e2����<0�����֣�e1=e2����0
//			);
# if 0
# include <string.h>
int cmp_int(const void* e1, const void* e2)//cmp�����ķ������͡����������Ѿ��̶����ܸ��ģ�������ʹ�������cmp�����ľ��幦��
{
	return *(int*)e1 - *(int*)e2;
}
void swap(char* buf1, char* buf2, int width)//�ַ���ָ�������ֻ�ܷ���1���ֽڣ��������Ҫ����width���ֽ�
{
	int i = 0;//iҪ��width�Ƚϣ�����Ҫһ��
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;//����1���ֽں�ָ��������1���ֽ�
		buf2++;
	}
}
void bubble_sort(void* arr, size_t sz, size_t width, int(*cmp)(const void* e1,const void* e2))
{
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < sz - 1; i++)//����
	{
		//ÿ���ڲ�
		for (j = 0; j < sz - 1 - i; j++)//ÿ�˱ȽϵĶ���
		{
			if (cmp((char*)arr + j*width, (char*)arr + (j + 1)*width)>0)
			{  
			   //��cmp������Ҫ�Ƚϵ�����Ԫ�صĵ�ַ
			   //��swap������Ҫ�Ƚϵ�����Ԫ�صĵ�ַ
				swap((char*)arr + j*width, (char*)arr + (j + 1)*width, width);
			}
		}

	}
}

void print(int*arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test1()
{
	//��������
	int arr[] = { 9, 8, 7, 5, 4, 6, 2, 3, 1, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	bubble_sort(arr, sz, 4, cmp_int);
	print(arr, sz);
}
struct stu
{
	char name[20];
	int age;
};

int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}

int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

void test2()
{
	//�ṹ������
	struct stu s[3] = { { "zhangsan", 15 }, { "lisi", 20 }, { "wangwu", 18 } };
	//bubble_sort(s, 3, sizeof(struct stu), cmp_stu_by_name);
	bubble_sort(s, 3, sizeof(struct stu), cmp_stu_by_age);
}
int main()
{
	test2();
	return 0;
}
# endif

//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;//��cmp_int����������arr[j]��arr[j+1]�ĵ�ַ
//}
//
//void swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)//��Ȼbuf1��buf2ָ��arr[j]��arr[j+1]����������Ϊchar*�ʽ�����ֻ�ܷ���1���ֽ�
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp; 
//		buf1++;
//		buf2++;
//	}
//
//}
//
//void bubble_sort(void* arr, size_t sz, size_t width, int (*cmp)(const void* e1, const void* e2))
//{
//	size_t i = 0;
//	size_t j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//�Ƚ�*(arr+j)��*(arr+j+1),��base��void*����ֱ�����㣬Ҫǿת����Ϊchar*������size�õ�����
//			if (cmp((char*)arr + j*width, (char*)arr + (j + 1)*width)>0)
//			{
//				swap((char*)arr + j*width, (char*)arr + (j + 1)*width, width);
//			}	
//		}
//	}
//}
//
//void test1()
//{
//	int arr[] = { 3, 2, 4, 7, 6, 5, 1, 9, 7, 8, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, 4, cmp_int);
//
//}
//
//
//int main()
//{
//	test1();
//	test2();
//	return 0;
//}