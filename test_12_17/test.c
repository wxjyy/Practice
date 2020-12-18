#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//判断当前机器的字节序
# if 0
int main()
{
	int a = 1;
	//大端：00 00 00 01
	//小端：01 00 00 00
	//a的第一个字节如果是0，则为大端字节序
	//a的第一个字节如果是1，则为小端字节序
	int ret = *((char *)&a);//&a得到a的低地址，&a的类型为int*，先将其类型强转为char*再解引用，就得到了a的第一个字节
	if (ret == 1)
	{
		printf("小端字节序\n");
	}
	else
	{
		printf("大端字节序\n");
	}
	return 0;
}
# endif

//5.
# if 0
#include <Windows.h>
int main()
{
	unsigned int i;//无符号数恒>=0，所以会死循环
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);//打印9~0后，i--变成-1，无符号数的补码=原码=反码
						  //-1的补码视为原码,0x ff ff ff ff=4294967295
		Sleep(1000);
	}
	return 0;
}
# endif

//△
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
			//二维数组的数组名arr：第0行首地址
			//arr+i：第i行首地址
			//*arr：第0行首元素地址&arr[0]
			//*（arr+i)：第i行首元素地址&arr[i]
			//*(arr+i)+j：第i行的第j个元素的地址&arr[i][j]
			//*(*(arr+i)+j)第i行的第j个元素arr[i][j]
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
