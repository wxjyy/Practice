#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

void menu()
{
	printf("********************************************\n");
	printf("*[0] quit_system          [1] push_back    *\n");
	printf("*[2] push_front           [3] show_list    *\n");
	printf("*[4] pop_back             [5] pop_front    *\n");
	printf("*[6] length               [7] capacity     *\n");
	printf("*[8] insert_val           [9] insert_pos   *\n");
	printf("*[10] delete_val          [11] delete_pos  *\n");
	printf("*[12] find                [13] sort        *\n");
	printf("*[14] reverse             [15] remove_all  *\n");
	printf("*[16] clear               [17] find_binary *\n");
	printf("*[*18] destroy                             *\n");
	printf("********************************************\n");

}

int main()
{
	SeqList mylist;
	SeqListInit(&mylist);
	ELEMTYPE item;
	int pos;
	int input = 1;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出顺序表.\n");
			break;
		case 1:
			printf("请输入要尾部插入的数（以-1结束）：>");
			while (scanf("%d", &item), item != -1)//输入数字尾插到顺序表内，直到输入-1停止插入
			{
				SeqListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要头部插入的数（以-1结束）：>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("表长为：>%d\n",SeqListLength(&mylist));
			break;
		case 7:
			printf("表容量为：>%d\n",SeqListCapacity(&mylist));
			break;
		case 8:
			printf("请输入要按值插入的数：>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 9:
			printf("请输入要插入的位置：>");
			scanf("%d", &pos);
			printf("请输入要按位置插入的值：>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;
		case 10:
			printf("请输入要删除的数：>");
			scanf("%d", &item);
			SeqListDeleteByVal(&mylist, item);
			break;
		case 11:
			printf("请输入要删除的位置：>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 12:
			printf("请输入要查找的数：>");
			scanf("%d", &item);
			pos = SeqListFind(&mylist, item);
			if (-1 == pos)
			{
				printf("该数不存在.\n");
			}
			else
			{
				printf("要查找的%d在下标为%d的位置.\n", item, pos);
			}
			break;
		case 13:
			SeqListSort(&mylist);
			break;
		case 14:
			SeqListReverse(&mylist);
			break;
		case 15:
			printf("请输入要删除的数：>");
			scanf("%d", &item);
			SeqListRemoveAll(&mylist, item);
			break;
		case 16:
			SeqListClear(&mylist);
			break;
		case 17:
			printf("请输入要二分查找的数：>");
			scanf("%d", &item);
			int pos = SeqListFindBinary(&mylist, item);
			if (-1 == pos)
			{
				printf("要查找的数%d不存在.\n", item);
			}
			else
			{
				printf("要查找的%d在下标为%d的位置.\n", item, pos);
			}
			break;
		default:
			printf("输入不合法，请重新输入.\n");
			break;
		}
		system("pause");
		system("cls");
	} while (input);

	SeqListDestroy(&mylist);

	return 0;
}