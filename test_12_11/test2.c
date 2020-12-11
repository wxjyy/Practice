#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//结构体、const、assert、调试

//★1.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
# if 0
int main()
{
	int num = 20;//买的汽水数量
	int sum = 20;
	while (num>1)//注意循环条件
	{
		sum += num / 2;//得到的汽水数量
		num = num / 2 + num % 2;//新的空瓶数
	}
	printf("%d bottles\n", sum);
	return 0;
}
# endif

//2.模拟实现库函数strlen
# if 0
#include <assert.h>
int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);//断言
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

//3.模拟实现库函数strcpy
# if 0
#include <assert.h>
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* p = dest;
	while (*dest++ = *src++)//scr指向\0后，将\0赋给*dest，判断条件为0（即假），不再进入循环
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

//4.输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。
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
		if (left < right)//因为进入while循环后，左右下标一直在变，所以依然要加上这个条件
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