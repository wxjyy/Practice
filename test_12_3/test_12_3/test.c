#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//ʵ��һ�������������ð������
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz-1; i++)
//	{
//		for (j = 0; j < sz -1 -i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//
//	return 0;
//}

//����һ���������飬��ɶ�����Ĳ���
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�
//void init(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//void reverse(int* arr, int sz)
//{
//	int tmp = 0; 
//	int i = 0;
//	for (i = 0; i < sz / 2; i++)
//	{
//		tmp = arr[i];
//		arr[i] = arr[sz - 1 - i];
//		arr[sz - 1 - i] = tmp;
//	}
//	
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//init(arr,sz);
//	print(arr,sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	return 0;
//}

//������A�е����ݺ�����B�е����ݽ��н�����������һ����
int main()
{
	int arr1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int i = 0;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	//print(arr1, sz);
	//print(arr2, sz);
	for (i = 0; i < sz; i++)
	{
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	//print(arr1, sz);
	//print(arr2, sz);

	return 0;
}