#define _CRT_SECURE_NO_WARNINGS

//1������һ���޷�������ֵ������˳���ӡ����ÿһλ��
//#include <stdio.h>
//void print(int n)
//{
//	if (n > 9)//��������
//	{
//		print(n / 10);//�ӽ���������
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}

//2������������ʱ���������ַ�������
#include <stdio.h>
//��������ʱ����
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//��������ʱ����
//int my_strlen(char* str)
//{
//	if(*str != 0)
//	{
//		return 1 + my_strlen(str+1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	char* p = "abcdef";
//	int len = my_strlen(p);
//	printf("%d\n", len);
//	return 0;
//}

//3����n�Ľ׳ˣ������������
//#include <stdio.h>
//�ݹ�
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

//����
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
//
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = factorial(n);
//	printf("%d\n", ret);
//	return 0;
//}

//4�����n��쳲��������������������1 1 2 3 5 8 13 21...)
//#include <stdio.h>
//�ݹ�
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}

//����
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
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}

//5����ŵ�����⣨�ݹ飩
//#include <stdio.h>
//void Hanoi(int n, char a, char b, char c)
//{
//	if (n == 1)
//	{
//		printf("NO.%d:%c->%c\n", n, a, c);
//	}
//	else
//	{
//		Hanoi(n - 1, a, c, b);
//		printf("NO.%d:%c->%c\n", n, a, c);
//		Hanoi(n - 1, b, a, c);
//	}
//}
//
//int main()
//{
//	char a='A';
//	char b = 'B';
//	char c = 'C';
//	int n = 0;
//	scanf("%d", &n);
//	Hanoi(n, a, b, c);
//	return 0;
//}

//6��������̨������:���ܿ���һ����һ��̨�׻�һ��������̨�ף�������n��̨���м�������
//����쳲�������һ����
//�ݹ�
//#include <stdio.h>

//int Step(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Step(n - 1) + Step(n - 2);
//	}
//}
//����
int Step(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int m = Step(n);
	printf("%d\n", m);
	return 0;
}