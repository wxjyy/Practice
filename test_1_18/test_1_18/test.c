#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

int main()
{
	SeqList mylist;
	SeqListInit(&mylist);
	ELEMTYPE item;
	int pos;
	int input = 1;
	while (input)
	{
		printf("*************************************\n");
		printf("*[1] push_back     [2] push_front   *\n");
		printf("*[3] show_list     [0] quit_system  *\n");
		printf("*[4] pop_back      [5] pop_front    *\n");
		printf("*[6] length        [7] capacity     *\n");
		printf("*[8] insert_val    [9] insert_pos   *\n");
		printf("*[10] delete_val   [11] delete_pos  *\n");
		printf("*[12] find         [13] sort        *\n");
		printf("*[14] reverse      [15] remove_all  *\n");
		printf("*[16] clear        [*17] destroy    *\n");
		printf("*[18] find_binary                   *\n");
		printf("*************************************\n");
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			//case与数字之间有空格
		case 1:
			printf("请输入你要尾部插入的数(以-1结束）：>");
			while (scanf("%d", &item), item != -1)//逗号表达式
			{
				SeqListPushBack(&mylist, item);//不用在函数内改变item的值，只需传值，无需传址
			}
			break;
		case 2:
			printf("请输入你要头部插入的数(以-1结束）：>");
			while (scanf("%d", &item), item != -1)//逗号表达式
			{
				SeqListPushFront(&mylist, item);//不用在函数内改变item的值，只需传值，无需传址
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
			printf("表长为：>%d\n", SeqListLength(&mylist));
			break;
		case 7:
			printf("表的容量为%d\n", SeqListCapacity(&mylist));
			break;
		case 8:
			printf("请输入要插入的值：>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 9:
			printf("请输入要插入的位置：>");
			scanf("%d", &pos);
			printf("请输入要插入的值：>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;
		case 10:
			printf("请输入要删除的值：>");
			scanf("%d", &item);
			SeqListDeleteByVal(&mylist, item);
			break;
		case 11:
			printf("请输入要删除的位置：>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 12:
			printf("请输入要查找的值：>");
			scanf("%d", &item);
			pos = SeqListFind(&mylist, item);
			if (pos == -1)
			{
				printf("要查找的%d不存在\n", item);
			}
			else
			{
				printf("要查找的%d在下标为%d的位置\n", item, pos);
			}
			break;
		case 13:
			SeqListSort(&mylist);
			break;
		case 14:
			SeqListReverse(&mylist);
			break;
		case 15:
			printf("请输入要删除的值：>");
			scanf("%d", &item);
			SeqListRemoveAll(&mylist, item);
			break;
		case 16:
			SeqListClear(&mylist);
			break;
		case 18:
			printf("请输入要查找的值：>");
			scanf("%d", &item);
			pos = SeqListFindBinary(&mylist, item);
			if (pos == -1)
			{
				printf("要查找的%d不存在\n", item);
			}
			else
			{
				printf("要查找的%d在下标为%d的位置\n", item, pos);
			}
			break;
		case 0:
			break;
		}
		system("pause");
		system("cls");
	}
	SeqListDestroy(&mylist);//不摧毁的话会造成内存泄漏，因为malloc开辟的空间必须自己free掉

	return 0;
}