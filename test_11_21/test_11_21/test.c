#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//	{
//		printf("δ����\n");
//	}
//	else
//	{
//		printf("����\n");
//	}
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int age = 0;
//	printf("���������䣺\n");
//	scanf("%d", &age);
//	if (age < 18)
//	{
//		printf("����\n");
//	}
//	else if (age >= 18 && age < 30)
//	{
//		printf("����\n");
//	}
//	else if (age >= 30 && age < 50)
//	{
//		printf("����\n");
//	}
//	else
//	{
//		printf("����\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}

//1���ж�һ�����Ƿ�Ϊ����
//#include <stdio.h>
//
//int main()
//{
//	int num = 0;
//	printf("������һ������>");
//	scanf("%d", &num);
//	if (num % 2 == 1)
//	{
//		printf("����Ϊ����\n");
//	}
//	else
//	{
//		printf("����Ϊż��\n");
//	}
//	return 0;
//}

//2�����1-100֮�������
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day) //��������������α��ʽ
//	{
//		case 1:
//			printf("Monday\n");
//			break;
//		case 2:
//			printf("Tuesday\n");
//			break;
//		case 3:
//			printf("Wendnesday\n");
//			break;
//		case 4:
//			printf("Thursday\n");
//			break;
//		case 5:
//			printf("Friday\n");
//			break;
//		case 6:
//			printf("Saturday\n");
//			break;
//		case 7:
//			printf("Sunday\n");
//			break;
//		default:
//			printf("���벻����\n");
//			break;
//
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;
//	}
//	return 0;
//}

//#include <stdio.h>
//int Add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int a = 10;
//	int b = 20;
//	int sum = 0;
//	scanf("%d%d", &x, &y);
//	sum = Add(x, y);
//	printf("sum=%d\n", sum);
//	sum = Add(a, b);
//	printf("sum=%d\n", sum);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;
//	case 2:
//		n++;
//	case 3:
//		switch (n)
//		{
//		case 1:
//			n++;
//		case 2:
//			m++;
//			n++;
//			break;
//		}
//	case 4:
//		m++;
//		break;
//	default:
//		break;
//	}
//	printf("m = %d, n = %d\n", m, n);
//	return 0;
//}

//��ӡ1-10
//

//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			break; //����break��ֹͣ���ڵ�����ѭ����ֱ����ֹѭ��
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i++;
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int ch = getchar();//int ch = 0;
//					   //scanf("%c",&ch);
//	putchar(ch);//printf("%c\n", ch);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
	//��ӡ������ַ�
	//int ch = 0;
	//while ((ch = getchar()) != EOF)//CTRL+Z����EOF(end of file������ѭ��
	//{
	//	putchar(ch);
	//}
	
	//ֻ��ӡ�����ַ�
	/*int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch > '9')
			continue;
		putchar(ch);
	}*/


// ***
//	char password[20] = { 0 };
//	printf("���������룺>");
//	scanf("%s", password);//���������ǵ�ַ
//	//gets(password);//gets�ܰѿո��\n��ȡ��
//	printf("��ȷ��(Y/N):");//scanf�����뻺�����а��ַ�����ȡ�󣬻�ʣ\n�������뻺����
//						   //getchar���\n��ȡ�����ret=='Y'ֱ��Ϊ�٣�
//						   //���ǻ�û����Y/N��ֱ�Ӵ�ӡ�ˡ�����ȷ�ϡ�
//						   //���Ҫ��ջ�����,getcharû��ȡ���ַ��ͻ���ʾ��˸���ȴ�����
//						   //����������"123 ad"����%d���ַ��������룬scanf�����ո�Ͳ����ˣ�
//						   //һ��getchar()ֻ�ܶ�ȡһ���ַ�����������Ȼû����գ����Ҫдѭ��
//	//��ջ�������
//	/*while (getchar() != '\n')
//	{
//		;
//	}*/
//	int ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("����ȷ��\n");
//	}
//
//
//	return 0;
//}
//***


//#include <stdio.h>
//int main()
//{
//	
//	int i = 0;
//
	////while�е�continue��������������ֱ��ȥ�жϲ���
	//while (i <= 10)
	//{
	//	if (i == 5)
	//		continue;
	//	printf("%d ", i);
	//	i++;
	//}

	////if�е�continueֱ��������������
	//for (i = 1; i <= 10; i++)
	//{
	//	if (i == 5)
	//		continue;
	//	printf("%d ", i);
	//}

//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//}//Խ���arr[12]ռ����i��λ��

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (; i < 10; i++)
//	{
//		for (; j < 10; j++)
//		{
//			printf("hehe\n");
//		}
//	}
//	return 0;
//}//ֻ��i=0����ѭ����j��ѭ����10�Σ�ʣ�µ�i����ѭ����j����ѭ��

//#include <stdio.h>
//int main()
//{
//	/*int x, y;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
//	{
//		printf("hehe\n");
//	}*/
//
//	int i = 1;
//	do
//	{
//		if (5 == i)
//			continue;
//		printf("%d\n", i);
//		i++;
//	} while (i <= 10);
//	return 0;
//}

//1������n�Ľ׳�
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	printf("������һ������>");
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	printf("n�Ľ׳�Ϊ��%d\n", ret);
//	return 0;
//}

//2������1��+2��+3��+....+10��
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		ret = ret * i;
//		sum = sum + ret;
//
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//3����һ�����������в��Ҿ����ĳ������n��
//#include <stdio.h>
//int main()
//{
//	printf("������Ҫ�ҵ����֣�>");
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int k = 2;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while(left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±�Ϊ%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}

//4����ʾ����ַ��������ƶ������м���
//#include <stdio.h>
//#include <Windows.h>//Sleep()
//int main()
//{
//	char arr1[] = "welcome to bit!";
//	char arr2[] = "###############";
	//��whileʵ��
	//int left = 0;
	//int right = strlen(arr1) - 1;//sizeof��\0��strlen����\0
	//while (left<=right)
	//{
	//	arr2[left] = arr1[left];
	//	left++;
	//	arr2[right] = arr1[right];
	//	right--;
	//	printf("%s\n", arr2);
	//	Sleep(1000);//1000ms=1s
	//	system("cls");//ִ��ϵͳ���cls�������Ļ
	//}
	//��forʵ��
	/*int left = 0;
	int right = 0;
	for (left = 0, right = strlen(arr1)-1; left <= right; left++, right--)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);
		system("cls");
	}
	printf("%s\n", arr2);

	return 0;
}*/

//ģ���û���¼�龰��ֻ���������������룬��ȷ����ʾ�ɹ����������˳�����
//������ȷ������123456
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("���������룺>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("������ȷ��\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("���ξ������˳�����\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>//rand  srand
//#include <time.h>//time
//void menu()
//{
//	printf("*****************************\n");
//	printf("****  1.play   0.exit  ******\n");
//	printf("*****************************\n");
//}
//RAND_MAX = 32767
//void game()
//{
//	int ret = rand()%100+1;//int rand(void); ����һ��0~32767֮��������
//					 //����rand֮ǰҪ��srand���������������
//	//printf("%d\n", ret);��������ÿ���
//	int guess = 0;
//	while (1)
//	{
//		printf("�����֣�>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´���\n��");
//		}
//		else if (guess < ret)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶��ˣ�\n");
//			break;
//		}
//	}
//
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//void srand(unsigned int seed)��������������
//									//time_t time(time_t*timer);
//	do
//	{
//		menu();
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("ѡ���������������");
//			break;
//
//		}
//	} while (input);//ֻҪinput��Ϊ0�ͼ���ѭ����Ϊ0����������11
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("##########################\n");
	printf("###   1.play  0.exit   ###\n");
	printf("##########################\n");
}
void game()
{
	int guess = 0;
	int ret = rand()%100+1;//Ҫ��ѭ���⣬��Ȼÿ��һ�ζ������²���һ�����������Զ�²���
	while (1)
	{
		printf("�����֣�>");//Ҫ��ѭ���ڣ���Ȼ��һ�β����������һֱ��ѭ������ѭ��
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			break;
		}
	}

	
}
int main()
{
	srand((unsigned int)time(NULL));//û��=
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}

	} while (input);
	return 0;
}