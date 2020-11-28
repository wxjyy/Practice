#define _CRT_SECURE_NO_WARNINGS

//1、给定两个数，求这两个数的最大公约数
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int min = 0;
//	printf("请输入两个数字：\n");
//	scanf("%d %d", &a, &b);
//	min = (a < b) ? a : b;
//	while (a%min != 0 || b%min != 0)
//	{
//		min--;
//	}
//	printf("最大公约数为：%d\n", min);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int min = 0;
//	int i = 0;
//	int ret = 0;
//	printf("请输入两个数字：\n");
//	scanf("%d %d", &a, &b);
//	min = (a > b) ? b : a;
//	for (i = 1; i <= min; i++)
//	{
//		if (a%i == 0 && b%i == 0)
//		{
//			ret = i;
//		}
//	}
//	printf("最大公约数为：%d\n", ret);
//
//
//	return 0;
//}

//2、打印1000年到2000年之间的闰年
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

//3、打印100~200之间的素数
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

//4、编写程序数一下 1到 100 的所有整数中出现多少个数字9
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
//	printf("出现了%d个数字9\n", tag);
//	return 0;
//}

//5、计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果
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

//6、求10 个整数中最大值
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

//7、在屏幕上输出9 * 9乘法口诀表
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

//8、猜数字(1~100)游戏
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
//		printf("猜数字：>");//在循环内
//		scanf("%d", &guess);//别忘了&
//		if (guess < ret)
//		{
//			printf("猜小了！\n");
//		}
//		else if (guess>ret)
//		{
//			printf("猜大了！\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了！\n");
//			break;//注意！
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
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("输入错误，请重新选择：\n>");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//9、在一个整形有序数组中查找具体的某个数。要求：找到了就打印数字所在的下标，找不到则输出：找不到。
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//	int num = 0;
//	printf("请输入要查找的数：>");
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
//			printf("找到了！下标为%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
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
