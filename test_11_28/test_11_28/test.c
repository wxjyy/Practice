#define _CRT_SECURE_NO_WARNINGS
//1、实现一个函数，判断一个数是不是素数。利用上面实现的函数打印100到200之间的素数。
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i < n; i++)
//	{
//		if (n%i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int ret = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		ret = is_prime(i);
//		if (ret == 1)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//2、实现函数判断year是不是润年。
//int is_leap_year(int y)
//{
//	if ((y % 4 == 0) && (y % 100 != 0))
//	{
//		return 1;
//	}
//	else if (y % 400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 0;
//	printf("请输入年份：>");
//	scanf("%d", &year);
//	if (is_leap_year(year) == 1)
//	{
//		printf("是闰年\n");
//	}
//	else
//	{
//		printf("是平年\n");
//	}
//	return 0;
//}

//3、实现一个函数来交换两个整数的内容。
//void swap(int *lx, int *ly)
//{
//	int z = 0;
//	z = *lx;
//	*lx = *ly;
//	*ly = z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前：a=%d b=%d\n", a, b);
//	swap(&a, &b);
//	printf("交换后：a=%d b=%d\n", a, b);
//	return 0;
//}

//4、实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
//void mcl_table(int n)
//{
//	int i = 0;
//	int j = 0;
//	int m = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			m = i*j;
//			printf("%d*%d=%d ", j, i, m);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int num = 0;
//	printf("请输入行/（列）数：");
//	scanf("%d", &num);
//	mcl_table(num);
//	return 0;
//}

//关机程序
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//goto语句实现
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//	again:
//	printf("您的电脑将在2min后关机，输入：'我是猪'就取消关机\n");
//	scanf("%s", input);
//	if (strcmp("我是猪", input) == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}
//while实现
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//	while (1)
//	{
//		printf("您的电脑将在2min后关机，输入：'我是猪'就取消关机\n");
//		scanf("%s", input);
//		if (strcmp("我是猪", input) == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
	//char arr1[] = "abcdef";
	//char arr2[20] = "xxxxxxx";
	//strcpy(arr2, arr1);//char* strcpy ( char* destination, const char* source)
	//printf("%s\n", arr2);

	//char arr[] = "hello world";
	//memset(arr, 'x', 5);
	//printf("%s\n", arr);
	//return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	char * p = arr;//指针p里存的是数组arr首元素‘a’的地址
//	*p = 'w';//将‘a’换成了‘w’
//	printf("%s\n", arr);
//	return 0;
//}

//int get_max(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//
//int main()
//{
//	int a = 30;
//	int b = 20;
//	int max = 0;
//	max = get_max(a, b);
//	printf("%d\n", max);
//	return 0;
//}

//#include <stdio.h>

//void swap1(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//void swap2(int* px, int* py)
//{
//	int z = 0;
//	z = *px;
//	*px = *py;
//	*py = z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前：a=%d b=%d\n", a, b);
//	swap2(&a,&b);
//	printf("交换后：a=%d b=%d\n", a, b);
//	return 0;
//}


//写一个函数，实现一个整形有序数组的二分查找
//#include <stdio.h>
//int binary_search(int arr[], int input, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < input)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid]>input)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//	
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	int input = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0;
//	printf("请输入要查找的数：>");
//	scanf("%d", &input);
//	ret = binary_search(arr, input, sz);
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标为：%d\n", ret);
//	}
//	return 0;
//}

//写一个函数，每调用一次这个函数，就会将num的值加1
//#include <stdio.h>
//void Add(int* pn)
//{
//	(*pn)++;
//	//*pn++; ++的优先级大于* 所以这个语句的意思是：
//	//先解引用pn（即num），然后指针pn加加
//	//最终结果是：num还是没变，地址pn变了
//}
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("%d\n", num);
//	return 0;
//}

//函数的链式访问
#include <stdio.h>
int main()
{
	printf("%d\n", printf("%d", printf("%d", 43)));
	//printf函数的返回值是：被打印字符的个数
	return 0;
}