#define _CRT_SECURE_NO_WARNINGS

//1�����������������������������Լ��
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int min = 0;
//	printf("�������������֣�\n");
//	scanf("%d %d", &a, &b);
//	min = (a < b) ? a : b;
//	while (a%min != 0 || b%min != 0)
//	{
//		min--;
//	}
//	printf("���Լ��Ϊ��%d\n", min);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int min = 0;
//	int i = 0;
//	int ret = 0;
//	printf("�������������֣�\n");
//	scanf("%d %d", &a, &b);
//	min = (a > b) ? b : a;
//	for (i = 1; i <= min; i++)
//	{
//		if (a%i == 0 && b%i == 0)
//		{
//			ret = i;
//		}
//	}
//	printf("���Լ��Ϊ��%d\n", ret);
//
//
//	return 0;
//}

//2����ӡ1000�굽2000��֮�������
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (i % 100 == 0)
//		{
//			if (i % 400 == 0)
//			{
//				printf("%d\n", i);
//			}
//		}
//		else
//		{
//			if (i % 4 == 0)
//			{
//				printf("%d\n", i);
//			}	
//		}
//	}
//	
//	return 0;
//}

//3����ӡ100~200֮�������
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int tag = 1;
//		for (j = 2; j < i; j++)
//		{
//			if (i%j == 0)
//			{
//				tag = 0;
//				break;
//			}
//		}
//		if (tag == 1)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//4����д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
//#include <stdio.h>
//int main()
//{
//	int tag = 0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i < 10)
//		{
//			tag = 1;
//		}
//		else
//		{
//			if (i % 10 == 9)
//			{
//				tag++;
//			}
//		}
//	}
//	printf("������%d������9\n", tag);
//	return 0;
//}

//5������1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ����ӡ�����
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	double sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			sum += (1.0 / i);
//		}
//		if (i % 2 == 0)
//		{
//			sum -= (1.0 / i);
//		}
//	}
//	printf("%lf\n", sum);
//	return 0;
//}

//6����10 �����������ֵ
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,60,7,8,9 };
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	for (i = 1; i < 10; i++)
//	{
//		if (arr[0] < arr[i])
//		{
//			tmp = arr[0];
//			arr[0] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//	printf("The max is %d\n", arr[0]);
//	return 0;
//}

//7������Ļ�����9 * 9�˷��ھ���
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int s = 0;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			s = i*j;
//			printf("%d*%d=%d  ", j, i, s);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//8��������(1~100)��Ϸ
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void menu()
//{
//	printf("######################\n");
//	printf("####1.play 0.exit#####\n");
//	printf("######################\n");
//}
//void game()
//{
//	int guess = 0;
//	int ret = rand() % 100 + 1;
//	while (1)
//	{
//		printf("�����֣�>");//��ѭ����
//		scanf("%d", &guess);//������&
//		if (guess < ret)
//		{
//			printf("��С�ˣ�\n");
//		}
//		else if (guess>ret)
//		{
//			printf("�´��ˣ�\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶��ˣ�\n");
//			break;//ע�⣡
//		}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("�������������ѡ��\n>");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//9����һ���������������в��Ҿ����ĳ������Ҫ���ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//	int num = 0;
//	printf("������Ҫ���ҵ�����>");
//	scanf("%d", &num);
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] < num)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > num)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±�Ϊ%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}

#if 0
#include <stdio.h>
int main()
{
	printf("%d\n",strlen("c:\code\test.c\n"));
	printf("c:\code\test.c\n");
	return 0;
}
#end if
