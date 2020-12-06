#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////求两个数二进制中不同位的个数
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int i = 0;
//	int count = 0;
//	printf("请输入两个要比较的两个整数：>");
//	scanf("%d %d", &a, &b);
//	c = a^b;
//	for (i = 0; i < 32; i++)
//	{
//		if (((c >> i)&1) == 1)
//		{
//			count++;
//		}
//	}
//	printf("不同位有%d位\n", count);
//	return 0;
//}

//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	printf("偶数位:");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	printf("奇数位:");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	return 0;
//}

//写一个函数返回参数二进制中 1 的个数。比如： 15    0000 1111    4 个 1
//int Count(int num)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((num >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	printf("%d\n",Count(num));
//	return 0;
//}

//交换两个变量（不创建临时变量）
//int main()
//{
//	int a = 10;
//	int b = 20;
//	a = a^b;
//	b = a^b;
//	a = a^b;
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}

//不使用累计乘法的基础上，通过移位运算（<<）实现2的n次方的计算。 
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("2的n次方=%d\n", (1 << n));
//	return 0;
//}
int main()
{
	int n;
	while (scanf("%d", &n) == 1) 
	{
		printf("%d\n", 1 << n);
	}
}