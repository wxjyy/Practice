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
//	printf("������һ��������>");
//	scanf("%d", &n);
//	Print(n);
//	return 0;
//}

////�ݹ�
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
////�ǵݹ�
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

//�ǵݹ�
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
////�ݹ�
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

//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
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

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19,���룺1729�������19
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

//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
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
//	printf("%d��%d�η�Ϊ��%lld\n", n, k, Power(n, k));
//	return 0;
//}

//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
////�ݹ�
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//�ǵݹ�
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



