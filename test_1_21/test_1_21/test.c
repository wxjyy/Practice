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
	SList mylist;//指向节点的指针
	SListInit(&mylist);
	while (input)
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出无头单链表.\n");
			break;
		case 1:
			printf("请输入要尾插的数（以-1结束）：>\n");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要头插的数（以-1结束）：>\n");
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
			printf("表长为：>%d\n", SListLength(&mylist));
			break;
		case 7:
			printf("请输入要查找的数：>");
			scanf("%d", &item);
			p = SListFind(&mylist, item);
			if (p == NULL)
				printf("要查找的值%d不存在.\n",item);
			else
				printf("要查找的值%d存在.\n",item);
			break;
		case 8:
			SListClear(&mylist);
			break;
		case 9:
			printf("请输入要删除的数：>");
			scanf("%d", &item);
			SListDeleteByVal(&mylist, item);
			break;
		case 10:
			printf("请输入要插入的数：>");
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
			printf("请输入要删除的值：>");
			scanf("%d", &item);
			SListRemoveAll(&mylist, item);
			break;
		default:
			printf("输入不合法，请重新选择：>\n");
			break;
		}
		system("pause");
		system("cls");
	}
	SListDestroy(&mylist);

	return 0;
}