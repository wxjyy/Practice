#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////���������������в�ͬλ�ĸ���
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int i = 0;
//	int count = 0;
//	printf("����������Ҫ�Ƚϵ�����������>");
//	scanf("%d %d", &a, &b);
//	c = a^b;
//	for (i = 0; i < 32; i++)
//	{
//		if (((c >> i)&1) == 1)
//		{
//			count++;
//		}
//	}
//	printf("��ͬλ��%dλ\n", count);
//	return 0;
//}

//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	printf("ż��λ:");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	printf("����λ:");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	return 0;
//}

//дһ���������ز����������� 1 �ĸ��������磺 15    0000 1111    4 �� 1
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

//����������������������ʱ������
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

//��ʹ���ۼƳ˷��Ļ����ϣ�ͨ����λ���㣨<<��ʵ��2��n�η��ļ��㡣 
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("2��n�η�=%d\n", (1 << n));
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