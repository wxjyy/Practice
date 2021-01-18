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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
			//case������֮���пո�
		case 1:
			printf("��������Ҫβ���������(��-1��������>");
			while (scanf("%d", &item), item != -1)//���ű��ʽ
			{
				SeqListPushBack(&mylist, item);//�����ں����ڸı�item��ֵ��ֻ�贫ֵ�����贫ַ
			}
			break;
		case 2:
			printf("��������Ҫͷ���������(��-1��������>");
			while (scanf("%d", &item), item != -1)//���ű��ʽ
			{
				SeqListPushFront(&mylist, item);//�����ں����ڸı�item��ֵ��ֻ�贫ֵ�����贫ַ
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
			printf("��Ϊ��>%d\n", SeqListLength(&mylist));
			break;
		case 7:
			printf("�������Ϊ%d\n", SeqListCapacity(&mylist));
			break;
		case 8:
			printf("������Ҫ�����ֵ��>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 9:
			printf("������Ҫ�����λ�ã�>");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ��>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;
		case 10:
			printf("������Ҫɾ����ֵ��>");
			scanf("%d", &item);
			SeqListDeleteByVal(&mylist, item);
			break;
		case 11:
			printf("������Ҫɾ����λ�ã�>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 12:
			printf("������Ҫ���ҵ�ֵ��>");
			scanf("%d", &item);
			pos = SeqListFind(&mylist, item);
			if (pos == -1)
			{
				printf("Ҫ���ҵ�%d������\n", item);
			}
			else
			{
				printf("Ҫ���ҵ�%d���±�Ϊ%d��λ��\n", item, pos);
			}
			break;
		case 13:
			SeqListSort(&mylist);
			break;
		case 14:
			SeqListReverse(&mylist);
			break;
		case 15:
			printf("������Ҫɾ����ֵ��>");
			scanf("%d", &item);
			SeqListRemoveAll(&mylist, item);
			break;
		case 16:
			SeqListClear(&mylist);
			break;
		case 18:
			printf("������Ҫ���ҵ�ֵ��>");
			scanf("%d", &item);
			pos = SeqListFindBinary(&mylist, item);
			if (pos == -1)
			{
				printf("Ҫ���ҵ�%d������\n", item);
			}
			else
			{
				printf("Ҫ���ҵ�%d���±�Ϊ%d��λ��\n", item, pos);
			}
			break;
		case 0:
			break;
		}
		system("pause");
		system("cls");
	}
	SeqListDestroy(&mylist);//���ݻٵĻ�������ڴ�й©����Ϊmalloc���ٵĿռ�����Լ�free��

	return 0;
}