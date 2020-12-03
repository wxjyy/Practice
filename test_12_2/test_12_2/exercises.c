#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//
//void Print(int n)
//{
//	if (n  > 9)
//	{
//		Print(n / 10);
//		printf("%d ", n % 10);
//	}
//	else
//	{
//		printf("%d ", n);
//	}
//
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个整数：>");
//	scanf("%d", &n);
//	Print(n);
//	return 0;
//}

////递归
//int factorial(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n*factorial(n - 1);
//	}
//}
////非递归
//int factorial(int n)
//{
//	int ret = 1;
//	while (n > 1)
//	{
//		ret *= n;
//		n--;
//	}
//	return ret;
//}

//int main()
//{
//	int ret = 0;
//	int n = 0;
//	scanf("%d", &n);
//	ret = factorial(n);
//	printf("%d\n", ret);
//	return 0;
//}

//非递归
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
////递归
//int my_strlen(char* str)
//{
//	if (str[0] != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	char str[] = "abc";
//	scanf("%s", str);
//	printf("%d\n", my_strlen(str));
//	return 0;
//}

//编写一个函数 reverse_string(char * string)（递归实现）实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//void reverse_string(char * string)
//{
//	if (*(string++)!='\0')
//	{
//		reverse_string(string);
//	}
//	printf("%c ", *(string - 1));
//}
//
//int main()
//{
//	char* str = "abcdef";
//	reverse_string(str);
//	printf("\n");
//	return 0;
//}

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19,输入：1729，输出：19
//int DigitSum(unsigned int n)
//{
//	if (n > 9)
//	{
//		return DigitSum(n / 10) + (n % 10);
//	}
//	else
//	{
//		return n;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", DigitSum(n));
//	return 0;
//}

//编写一个函数实现n的k次方，使用递归实现。
//long long Power(int n, int k)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		if (k == 1)
//		{
//			return n;
//		}
//		else
//		{
//			return Power(n, k - 1) * n;
//		}
//	}
//
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	printf("%d的%d次方为：%lld\n", n, k, Power(n, k));
//	return 0;
//}

//递归和非递归分别实现求第n个斐波那契数
////递归
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//非递归
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fib(n));
//	return 0;
//}



