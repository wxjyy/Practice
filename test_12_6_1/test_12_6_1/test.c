#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>

//不同指针达到不同效果
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5 };
//	char* p = (char*)arr;
//	int i = 0;
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", *(p + i));//1 0 0 0 2 0 0 0 3 0 0 0 4 0 0 0 5 0 0 0
//	}
//	return 0;
//}

//实现strlen（）
//1.
//int my_strlen(char* s)
//{
//	int i = 0;
//	while (*(s + i) != '\0')
//	{
//		i++;
//	}
//	return i;
//}
//2.
//int my_strlen(char* s)
//{
//	char* start = s;
//	while (*s != '\0')
//	{
//		s++;
//	}
//	return (s - start);
//}
//
//int main()
//{
//	char arr[] = "abcde";
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}

//指针数组
//int main()
//{
//	int arr1[] = { 1, 2, 3 };
//	int arr2[] = { 2, 3, 4 };
//	int arr3[] = { 3, 4, 5 };
//	int arr4[] = { 4, 5, 6 };
//	int* arr[] = { arr1, arr2, arr3, arr4 };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}