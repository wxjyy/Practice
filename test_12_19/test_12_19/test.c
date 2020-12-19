#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//冒泡排序（升序）
# if 0
void bubble_sort(int* arr, int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)//趟数
	{
		//每趟内部
		for (j = 0; j < sz - 1 - i; j++)//每趟比较的对数
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

//▲模拟实现qsort（采用升序冒泡排序）
//void qsort (void* base, 要被排序的数组的数组首元素地址
//			size_t num,  要排序的数组的元素个数
//			size_t size, 要排序的数组的每个元素的字节数
//			int(*comp)(const void* e1, const void* e2) 两个元素的比较方法，e1>e2返回>0的数字，e1<e2返回<0的数字，e1=e2返回0
//			);
# if 0
# include <string.h>
int cmp_int(const void* e1, const void* e2)//cmp函数的返回类型、参数类型已经固定不能更改，其他由使用者完成cmp函数的具体功能
{
	return *(int*)e1 - *(int*)e2;
}
void swap(char* buf1, char* buf2, int width)//字符型指针解引用只能访问1个字节，因此我们要交换width对字节
{
	int i = 0;//i要与width比较，类型要一致
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;//交换1对字节后，指针往后移1个字节
		buf2++;
	}
}
void bubble_sort(void* arr, size_t sz, size_t width, int(*cmp)(const void* e1,const void* e2))
{
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < sz - 1; i++)//趟数
	{
		//每趟内部
		for (j = 0; j < sz - 1 - i; j++)//每趟比较的对数
		{
			if (cmp((char*)arr + j*width, (char*)arr + (j + 1)*width)>0)
			{  
			   //给cmp（）传要比较的两个元素的地址
			   //给swap（）传要比较的两个元素的地址
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
	//整形排序
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
	//结构体排序
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
//	return *(int*)e1 - *(int*)e2;//给cmp_int函数传的是arr[j]和arr[j+1]的地址
//}
//
//void swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)//虽然buf1、buf2指向arr[j]、arr[j+1]但由于类型为char*故解引用只能访问1个字节
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
//			//比较*(arr+j)和*(arr+j+1),但base是void*不能直接运算，要强转类型为char*，根据size得到步长
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