#define _CRT_SECURE_NO_WARNINGS
//1��ʵ��һ���������ж�һ�����ǲ�����������������ʵ�ֵĺ�����ӡ100��200֮���������
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i < n; i++)
//	{
//		if (n%i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int ret = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		ret = is_prime(i);
//		if (ret == 1)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//2��ʵ�ֺ����ж�year�ǲ������ꡣ
//int is_leap_year(int y)
//{
//	if ((y % 4 == 0) && (y % 100 != 0))
//	{
//		return 1;
//	}
//	else if (y % 400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 0;
//	printf("��������ݣ�>");
//	scanf("%d", &year);
//	if (is_leap_year(year) == 1)
//	{
//		printf("������\n");
//	}
//	else
//	{
//		printf("��ƽ��\n");
//	}
//	return 0;
//}

//3��ʵ��һ�������������������������ݡ�
//void swap(int *lx, int *ly)
//{
//	int z = 0;
//	z = *lx;
//	*lx = *ly;
//	*ly = z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("����ǰ��a=%d b=%d\n", a, b);
//	swap(&a, &b);
//	printf("������a=%d b=%d\n", a, b);
//	return 0;
//}

//4��ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ�����磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
//void mcl_table(int n)
//{
//	int i = 0;
//	int j = 0;
//	int m = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			m = i*j;
//			printf("%d*%d=%d ", j, i, m);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int num = 0;
//	printf("��������/���У�����");
//	scanf("%d", &num);
//	mcl_table(num);
//	return 0;
//}

//�ػ�����
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//goto���ʵ��
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//	again:
//	printf("���ĵ��Խ���2min��ػ������룺'������'��ȡ���ػ�\n");
//	scanf("%s", input);
//	if (strcmp("������", input) == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}
//whileʵ��
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//	while (1)
//	{
//		printf("���ĵ��Խ���2min��ػ������룺'������'��ȡ���ػ�\n");
//		scanf("%s", input);
//		if (strcmp("������", input) == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
	//char arr1[] = "abcdef";
	//char arr2[20] = "xxxxxxx";
	//strcpy(arr2, arr1);//char* strcpy ( char* destination, const char* source)
	//printf("%s\n", arr2);

	//char arr[] = "hello world";
	//memset(arr, 'x', 5);
	//printf("%s\n", arr);
	//return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	char * p = arr;//ָ��p����������arr��Ԫ�ء�a���ĵ�ַ
//	*p = 'w';//����a�������ˡ�w��
//	printf("%s\n", arr);
//	return 0;
//}

//int get_max(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//
//int main()
//{
//	int a = 30;
//	int b = 20;
//	int max = 0;
//	max = get_max(a, b);
//	printf("%d\n", max);
//	return 0;
//}

//#include <stdio.h>

//void swap1(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//void swap2(int* px, int* py)
//{
//	int z = 0;
//	z = *px;
//	*px = *py;
//	*py = z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("����ǰ��a=%d b=%d\n", a, b);
//	swap2(&a,&b);
//	printf("������a=%d b=%d\n", a, b);
//	return 0;
//}


//дһ��������ʵ��һ��������������Ķ��ֲ���
//#include <stdio.h>
//int binary_search(int arr[], int input, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < input)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid]>input)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//	
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	int input = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0;
//	printf("������Ҫ���ҵ�����>");
//	scanf("%d", &input);
//	ret = binary_search(arr, input, sz);
//	if (ret == -1)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±�Ϊ��%d\n", ret);
//	}
//	return 0;
//}

//дһ��������ÿ����һ������������ͻὫnum��ֵ��1
//#include <stdio.h>
//void Add(int* pn)
//{
//	(*pn)++;
//	//*pn++; ++�����ȼ�����* �������������˼�ǣ�
//	//�Ƚ�����pn����num����Ȼ��ָ��pn�Ӽ�
//	//���ս���ǣ�num����û�䣬��ַpn����
//}
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("%d\n", num);
//	return 0;
//}

//��������ʽ����
#include <stdio.h>
int main()
{
	printf("%d\n", printf("%d", printf("%d", 43)));
	//printf�����ķ���ֵ�ǣ�����ӡ�ַ��ĸ���
	return 0;
}