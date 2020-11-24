#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//	{
//		printf("未成年\n");
//	}
//	else
//	{
//		printf("成年\n");
//	}
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int age = 0;
//	printf("请输入年龄：\n");
//	scanf("%d", &age);
//	if (age < 18)
//	{
//		printf("少年\n");
//	}
//	else if (age >= 18 && age < 30)
//	{
//		printf("青年\n");
//	}
//	else if (age >= 30 && age < 50)
//	{
//		printf("中年\n");
//	}
//	else
//	{
//		printf("老年\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}

//1、判断一个数是否为奇数
//#include <stdio.h>
//
//int main()
//{
//	int num = 0;
//	printf("请输入一个数：>");
//	scanf("%d", &num);
//	if (num % 2 == 1)
//	{
//		printf("该数为奇数\n");
//	}
//	else
//	{
//		printf("该数为偶数\n");
//	}
//	return 0;
//}

//2、输出1-100之间的奇数
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day) //括号里必须是整形表达式
//	{
//		case 1:
//			printf("Monday\n");
//			break;
//		case 2:
//			printf("Tuesday\n");
//			break;
//		case 3:
//			printf("Wendnesday\n");
//			break;
//		case 4:
//			printf("Thursday\n");
//			break;
//		case 5:
//			printf("Friday\n");
//			break;
//		case 6:
//			printf("Saturday\n");
//			break;
//		case 7:
//			printf("Sunday\n");
//			break;
//		default:
//			printf("输入不合理\n");
//			break;
//
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;
//	}
//	return 0;
//}

//#include <stdio.h>
//int Add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int a = 10;
//	int b = 20;
//	int sum = 0;
//	scanf("%d%d", &x, &y);
//	sum = Add(x, y);
//	printf("sum=%d\n", sum);
//	sum = Add(a, b);
//	printf("sum=%d\n", sum);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;
//	case 2:
//		n++;
//	case 3:
//		switch (n)
//		{
//		case 1:
//			n++;
//		case 2:
//			m++;
//			n++;
//			break;
//		}
//	case 4:
//		m++;
//		break;
//	default:
//		break;
//	}
//	printf("m = %d, n = %d\n", m, n);
//	return 0;
//}

//打印1-10
//

//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			break; //遇到break就停止后期的所有循环，直接终止循环
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i++;
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int ch = getchar();//int ch = 0;
//					   //scanf("%c",&ch);
//	putchar(ch);//printf("%c\n", ch);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
	//打印输入的字符
	//int ch = 0;
	//while ((ch = getchar()) != EOF)//CTRL+Z就是EOF(end of file）跳出循环
	//{
	//	putchar(ch);
	//}
	
	//只打印数字字符
	/*int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch > '9')
			continue;
		putchar(ch);
	}*/


// ***
//	char password[20] = { 0 };
//	printf("请输入密码：>");
//	scanf("%s", password);//数组名就是地址
//	//gets(password);//gets能把空格和\n都取走
//	printf("请确认(Y/N):");//scanf在输入缓冲区中把字符串读取后，还剩\n留在输入缓冲区
//						   //getchar会把\n读取，因此ret=='Y'直接为假，
//						   //我们还没输入Y/N就直接打印了“放弃确认”
//						   //因此要清空缓存区,getchar没读取到字符就会显示闪烁，等待输入
//						   //但是若输入"123 ad"由于%d是字符串的输入，scanf读到空格就不读了，
//						   //一个getchar()只能读取一个字符，缓冲区依然没有清空，因此要写循环
//	//清空缓存区：
//	/*while (getchar() != '\n')
//	{
//		;
//	}*/
//	int ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("放弃确认\n");
//	}
//
//
//	return 0;
//}
//***


//#include <stdio.h>
//int main()
//{
//	
//	int i = 0;
//
	////while中的continue会跳过调整部分直接去判断部分
	//while (i <= 10)
	//{
	//	if (i == 5)
	//		continue;
	//	printf("%d ", i);
	//	i++;
	//}

	////if中的continue直接跳到调整部分
	//for (i = 1; i <= 10; i++)
	//{
	//	if (i == 5)
	//		continue;
	//	printf("%d ", i);
	//}

//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//}//越界后，arr[12]占据了i的位置

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (; i < 10; i++)
//	{
//		for (; j < 10; j++)
//		{
//			printf("hehe\n");
//		}
//	}
//	return 0;
//}//只有i=0进入循环，j才循环了10次，剩下的i进入循环，j都不循环

//#include <stdio.h>
//int main()
//{
//	/*int x, y;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
//	{
//		printf("hehe\n");
//	}*/
//
//	int i = 1;
//	do
//	{
//		if (5 == i)
//			continue;
//		printf("%d\n", i);
//		i++;
//	} while (i <= 10);
//	return 0;
//}

//1、计算n的阶乘
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	printf("请输入一个数：>");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	printf("n的阶乘为：%d\n", ret);
//	return 0;
//}

//2、计算1！+2！+3！+....+10！
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		ret = ret * i;
//		sum = sum + ret;
//
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//3、在一个有序数组中查找具体的某个数字n。
//#include <stdio.h>
//int main()
//{
//	printf("请输入要找的数字：>");
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 2;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while(left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
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

//4、演示多个字符从两端移动，向中间汇聚
//#include <stdio.h>
//#include <Windows.h>//Sleep()
//int main()
//{
//	char arr1[] = "welcome to bit!";
//	char arr2[] = "###############";
	//用while实现
	//int left = 0;
	//int right = strlen(arr1) - 1;//sizeof算\0，strlen不算\0
	//while (left<=right)
	//{
	//	arr2[left] = arr1[left];
	//	left++;
	//	arr2[right] = arr1[right];
	//	right--;
	//	printf("%s\n", arr2);
	//	Sleep(1000);//1000ms=1s
	//	system("cls");//执行系统命令，cls：清空屏幕
	//}
	//用for实现
	/*int left = 0;
	int right = 0;
	for (left = 0, right = strlen(arr1)-1; left <= right; left++, right--)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);
		system("cls");
	}
	printf("%s\n", arr2);

	return 0;
}*/

//模拟用户登录情景：只允许输入三次密码，正确则提示成功；错误则退出程序
//假设正确密码是123456
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("密码正确！\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误！\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次均错误，退出程序\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>//rand  srand
//#include <time.h>//time
//void menu()
//{
//	printf("*****************************\n");
//	printf("****  1.play   0.exit  ******\n");
//	printf("*****************************\n");
//}
//RAND_MAX = 32767
//void game()
//{
//	int ret = rand()%100+1;//int rand(void); 返回一个0~32767之间的随机数
//					 //调用rand之前要用srand设置随机数生成器
//	//printf("%d\n", ret);随机数不让看见
//	int guess = 0;
//	while (1)
//	{
//		printf("猜数字：>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n！");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了！\n");
//			break;
//		}
//	}
//
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//void srand(unsigned int seed)设置随机数的起点
//									//time_t time(time_t*timer);
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
//			printf("选择错误，请重新输入");
//			break;
//
//		}
//	} while (input);//只要input不为0就继续循环，为0则跳出结束11
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("##########################\n");
	printf("###   1.play  0.exit   ###\n");
	printf("##########################\n");
}
void game()
{
	int guess = 0;
	int ret = rand()%100+1;//要在循环外，不然每猜一次都会重新产生一个随机数，永远猜不到
	while (1)
	{
		printf("猜数字：>");//要在循环内，不然第一次猜输入的数会一直在循环里死循环
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
	}

	
}
int main()
{
	srand((unsigned int)time(NULL));//没有=
	int input = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}

	} while (input);
	return 0;
}