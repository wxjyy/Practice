#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�жϵ�ǰ�������ֽ���
# if 0
int main()
{
	int a = 1;
	//��ˣ�00 00 00 01
	//С�ˣ�01 00 00 00
	//a�ĵ�һ���ֽ������0����Ϊ����ֽ���
	//a�ĵ�һ���ֽ������1����ΪС���ֽ���
	int ret = *((char *)&a);//&a�õ�a�ĵ͵�ַ��&a������Ϊint*���Ƚ�������ǿתΪchar*�ٽ����ã��͵õ���a�ĵ�һ���ֽ�
	if (ret == 1)
	{
		printf("С���ֽ���\n");
	}
	else
	{
		printf("����ֽ���\n");
	}
	return 0;
}
# endif

//5.
# if 0
#include <Windows.h>
int main()
{
	unsigned int i;//�޷�������>=0�����Ի���ѭ��
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);//��ӡ9~0��i--���-1���޷������Ĳ���=ԭ��=����
						  //-1�Ĳ�����Ϊԭ��,0x ff ff ff ff=4294967295
		Sleep(1000);
	}
	return 0;
}
# endif

//��
//int main()
//{
//	char* p = "abcdef";
//	printf("%p\n", p);
//	printf("%s\n", p);
//
//	return 0;
//}

# if 1
void print_arr(int(*arr)[5], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", *(*(arr + i) + j));
			//��ά�����������arr����0���׵�ַ
			//arr+i����i���׵�ַ
			//*arr����0����Ԫ�ص�ַ&arr[0]
			//*��arr+i)����i����Ԫ�ص�ַ&arr[i]
			//*(arr+i)+j����i�еĵ�j��Ԫ�صĵ�ַ&arr[i][j]
			//*(*(arr+i)+j)��i�еĵ�j��Ԫ��arr[i][j]
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print_arr(arr, 3, 5);
	return 0;
}
# endif
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int(*p)[5] = &arr;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *(*p + i));
//	}
//	return 0;
//}
