#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//������&ָ��

//1��дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣arr��һ������һά���顣
# if 0
void print(int *p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr,sz);
	return 0;
}
# endif

//��2��дһ����������������һ���ַ��������ݡ�
# if 0
#include <string.h>
void reverse(char* str,int len)
{
	int i = 0;
	char tmp = 0;
	for (i = 0; i < (len/2); i++)
	{
		tmp = *(str + i);
		*(str + i) = *(str + len -1 - i);
		*(str + len -1 - i) = tmp;
	}

}
int main()
{
	char str[20];
	gets(str);//�ո��\n����scanf�ķָ�����%s���������ո�ͽ�����
	//char str[] = "m jbrwbmamzlz bkjokxancguvcoc";
	int len = strlen(str);
	reverse(str,len);
	printf("%s\n", str);
	return 0;
}
# endif

//3����Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣����磺2 + 22 + 222 + 2222 + 22222
# if 0
int main()
{
	int a = 0;
	scanf("%d", &a);
	int i = 0;
	int j = 0;
	int sum = 0;
	for (i = 1; i <= 5; i++)
	{
		int an = a;
		int sn = a;
		for (j = 1; j < i; j++)
		{
			an *= 10;
			sn += an;
		}
		sum += sn;
	}
	printf("%d\n", sum);
	return 0;
}
# endif

//4�����0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ���������:153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������
# if 0
#include <math.h>
int digits(int num)
{
	int n = 0;
	while (num)
	{
		num /= 10;
		n++;
	}
	return n;
}
int Sum(int num,int n)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += (int)pow(num % 10, n);
		num /= 10;
	}
	return sum;
}
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		int n = digits(i);
		if (i == Sum(i, n))
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
# endif

//5����ӡͼ��
# if 0
void print(int count, char set)
{
	int i = 0;
	for (i = 0; i < count; i++)
	{
		printf("%c ", set);
	}
}
int main()
{
	int row = 13/2;
	int i = 0;
	for (i = 0; i <= row; i++)
	{
		print(row  - i, ' ');
		print(2*i+1,'*');
		print(row - i, ' ');
		printf("\n\n");
	}
	for (i = row - 1; i >= 0; i--)
	{
		print(row - i, ' ');
		print(2 * i + 1, '*');
		print(row - i, ' ');
		printf("\n\n");
	}
	return 0;
}
# endif