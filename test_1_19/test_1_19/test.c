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
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳�˳���.\n");
			break;
		case 1:
			printf("������Ҫβ�������������-1��������>");
			while (scanf("%d", &item), item != -1)//��������β�嵽˳����ڣ�ֱ������-1ֹͣ����
			{
				SeqListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫͷ�������������-1��������>");
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
			printf("��Ϊ��>%d\n",SeqListLength(&mylist));
			break;
		case 7:
			printf("������Ϊ��>%d\n",SeqListCapacity(&mylist));
			break;
		case 8:
			printf("������Ҫ��ֵ���������>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 9:
			printf("������Ҫ�����λ�ã�>");
			scanf("%d", &pos);
			printf("������Ҫ��λ�ò����ֵ��>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;
		case 10:
			printf("������Ҫɾ��������>");
			scanf("%d", &item);
			SeqListDeleteByVal(&mylist, item);
			break;
		case 11:
			printf("������Ҫɾ����λ�ã�>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 12:
			printf("������Ҫ���ҵ�����>");
			scanf("%d", &item);
			pos = SeqListFind(&mylist, item);
			if (-1 == pos)
			{
				printf("����������.\n");
			}
			else
			{
				printf("Ҫ���ҵ�%d���±�Ϊ%d��λ��.\n", item, pos);
			}
			break;
		case 13:
			SeqListSort(&mylist);
			break;
		case 14:
			SeqListReverse(&mylist);
			break;
		case 15:
			printf("������Ҫɾ��������>");
			scanf("%d", &item);
			SeqListRemoveAll(&mylist, item);
			break;
		case 16:
			SeqListClear(&mylist);
			break;
		case 17:
			printf("������Ҫ���ֲ��ҵ�����>");
			scanf("%d", &item);
			int pos = SeqListFindBinary(&mylist, item);
			if (-1 == pos)
			{
				printf("Ҫ���ҵ���%d������.\n", item);
			}
			else
			{
				printf("Ҫ���ҵ�%d���±�Ϊ%d��λ��.\n", item, pos);
			}
			break;
		default:
			printf("���벻�Ϸ�������������.\n");
			break;
		}
		system("pause");
		system("cls");
	} while (input);

	SeqListDestroy(&mylist);

	return 0;
}