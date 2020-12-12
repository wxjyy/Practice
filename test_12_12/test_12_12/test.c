#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1.打印杨辉三角
# if 0
int main()
{
	int arr[20][20] = { 0 };
	printf("请输入层数：>");
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)//两条斜边上的元素全为1
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for (i = 2; i < n; i++)//其他数字都是其肩膀上两个数字的和
	{
		for (j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)//打印二维数组
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
# endif

//2.日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//  以下为4个嫌疑犯的供词:
//  A说：不是我。
//  B说：是C。
//  C说：是D。
//  D说：C在胡说
//  已知3个人说了真话，1个人说的是假话。现在请根据这些信息，写一个程序来确定到底谁是凶手。
# if 0
int main()
{
	char m = 0;
	for (m = 'A'; m <= 'D'; m++)
	{
		if ((m != 'A') + (m == 'C') + (m == 'D') + (m != 'D') == 3)//if的括号里表达式是真则为1，假则为0
		{
			printf("the murderer is %c\n", m);
		}
	}
	return 0;
}
# endif

//3.五位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//  A选手说：B第二，我第三；
//  B选手说：我第二，E第四；
//  C选手说：我第一，D第二；
//  D选手说：C最后，我第三；
//  E选手说：我第四，A第一；
//  比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
# if 0
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((a == 3) + (b == 2) == 1 &&
							(b == 2) + (e == 4) == 1 && 
							(c == 1) + (d == 2) == 1 && 
							(c == 5) + (d == 3) == 1 && 
							(a == 1) + (e == 4) == 1 &&
							(a*b*c*d*e==120))//a、b、c、d、e各不相等，它们分别为1~5，故它们的乘积必为120
						{
							printf("a=%d, b=%d, c=%d, d=%d, e=%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
	return 0;
}
# endif
