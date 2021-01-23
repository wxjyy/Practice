#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"

void menu()
{
	printf("*******************************************\n");
	printf("**[0]quit_system        [1]push_back     **\n");
	printf("**[2]push_front         [3]show_list     **\n");
	printf("**[4]pop_back           [5]pop_front     **\n");
	printf("**[6]length             [7]find          **\n");
	printf("**[8]clear              [9]delete_by_val **\n");
	printf("**[10]insert_by_val     [11]reverse      **\n");
	printf("**[12]sort              [13]remove_all   **\n");
	printf("*******************************************\n");
}

int main()
{
	ELEMTYPE item;
	int pos;
	int input = 1;
	SListNode* p;
	SList mylist;//ָ��ڵ��ָ��
	SListInit(&mylist);
	while (input)
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���ͷ������.\n");
			break;
		case 1:
			printf("������Ҫβ���������-1��������>\n");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫͷ���������-1��������>\n");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&mylist, item);
			}
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			printf("��Ϊ��>%d\n", SListLength(&mylist));
			break;
		case 7:
			printf("������Ҫ���ҵ�����>");
			scanf("%d", &item);
			p = SListFind(&mylist, item);
			if (p == NULL)
				printf("Ҫ���ҵ�ֵ%d������.\n",item);
			else
				printf("Ҫ���ҵ�ֵ%d����.\n",item);
			break;
		case 8:
			SListClear(&mylist);
			break;
		case 9:
			printf("������Ҫɾ��������>");
			scanf("%d", &item);
			SListDeleteByVal(&mylist, item);
			break;
		case 10:
			printf("������Ҫ���������>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		case 11:
			SListReverse(&mylist);
			break;
		case 12:
			SListSort(&mylist);
			break;
		case 13:
			printf("������Ҫɾ����ֵ��>");
			scanf("%d", &item);
			SListRemoveAll(&mylist, item);
			break;
		default:
			printf("���벻�Ϸ���������ѡ��>\n");
			break;
		}
		system("pause");
		system("cls");
	}
	SListDestroy(&mylist);

	return 0;
}