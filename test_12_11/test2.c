#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�ṹ�塢const��assert������

//��1.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
# if 0
int main()
{
	int num = 20;//�����ˮ����
	int sum = 20;
	while (num>1)//ע��ѭ������
	{
		sum += num / 2;//�õ�����ˮ����
		num = num / 2 + num % 2;//�µĿ�ƿ��
	}
	printf("%d bottles\n", sum);
	return 0;
}
# endif

//2.ģ��ʵ�ֿ⺯��strlen
# if 0
#include <assert.h>
int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);//����
	while (*str)
	{
		str++;
		count++;
	}
	return count;
}
int main()
{
	char arr[] = "abcde";
	printf("%d\n", my_strlen(arr));
	return 0;
}
# endif

//3.ģ��ʵ�ֿ⺯��strcpy
# if 0
#include <assert.h>
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* p = dest;
	while (*dest++ = *src++)//scrָ��\0�󣬽�\0����*dest���ж�����Ϊ0�����٣������ٽ���ѭ��
	{
		;
	}
	return p;
}
int main()
{
	char arr1[] = "xxxxxxx";
	char arr2[] = "abcd";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
# endif

//4.����һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
void swap(int* arr,int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		if (left < right && (arr[left] % 2) == 1)
		{
			left++;
		}
		if (left < right && (arr[right] % 2) == 0)
		{
			right--;
		}
		if (left < right)//��Ϊ����whileѭ���������±�һֱ�ڱ䣬������ȻҪ�����������
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}