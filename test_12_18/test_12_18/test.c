#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
# if 0
void Left_str(char* str, int len, int k)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < k; i++) //左旋k次
	{
		char tmp = *str; //每左旋一次，字符串首字符都会改变，因此要放在循环里面
		for (j = 0; j < len - 1; j++)
		{
			*(str + j) = *(str + j + 1);
		}
		*(str + len - 1) = tmp;
	}
}
int main()
{
	char str[] = "ABCD";
	int len = strlen(str);
	int k = 2;
	scanf("%d", &k);
	Left_str(str, len, k);
	printf("%s\n", str);
	return 0;
}
# endif

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
//void right(char* s1, int len1, int k)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < k; i++) 
//	{
//		char tmp = *(s1 + len1 - 1); 
//		for (j = len1 - 1; j > 0; j--)
//		{
//			*(s1 + j) = *(s1 + j - 1);
//		}
//		*(s1) = tmp;
//	}
//}
void left(char* s1, int len1, int k)//左旋k个字符
{
	int i = 0;
	int j = 0;
	for (i = 0; i < k; i++)
	{
		char tmp = *s1;
		for (j = 0; j < len1 - 1; j++)
		{
			*(s1 + j) = *(s1 + j + 1);
		}
		*(s1 + len1 - 1) = tmp;
	}
}

int is_revolve(char* s1, char* s2, int len1, int len2)//判断s2是否为s1旋转之后的字符串
{
	int tag = 0; //判断标志，0为不是，1为是
	if (len1 != len2)//两个字符串长度不同，肯定不是
	{
		tag = 0;
	}
	else
	{
		int i = 0;
		for (i = 0; i < len1; i++) //s1左旋0~len1-1个字符
		{
			left(s1, len1, 1); 
			if (strcmp(s1, s2) == 0) //判断s1旋转后是否与s2相同
			{
				tag = 1;
				break;
			}
		}
		return tag;
	}
}
int main()
{
	char arr1[] = "AABCD";
	char arr2[] = "BCDAA";
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (is_revolve(arr1, arr2, len1, len2) == 1)
	{
		printf("是\n");
	}
	else
		printf("否\n");
	return 0;
}