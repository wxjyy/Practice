#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
# if 0
void Left_str(char* str, int len, int k)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < k; i++) //����k��
	{
		char tmp = *str; //ÿ����һ�Σ��ַ������ַ�����ı䣬���Ҫ����ѭ������
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

//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
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
void left(char* s1, int len1, int k)//����k���ַ�
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

int is_revolve(char* s1, char* s2, int len1, int len2)//�ж�s2�Ƿ�Ϊs1��ת֮����ַ���
{
	int tag = 0; //�жϱ�־��0Ϊ���ǣ�1Ϊ��
	if (len1 != len2)//�����ַ������Ȳ�ͬ���϶�����
	{
		tag = 0;
	}
	else
	{
		int i = 0;
		for (i = 0; i < len1; i++) //s1����0~len1-1���ַ�
		{
			left(s1, len1, 1); 
			if (strcmp(s1, s2) == 0) //�ж�s1��ת���Ƿ���s2��ͬ
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
		printf("��\n");
	}
	else
		printf("��\n");
	return 0;
}