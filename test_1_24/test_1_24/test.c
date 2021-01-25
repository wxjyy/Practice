#define _CRT_SECURE_NO_WARNINGS

//#include"stack.h"
#include "queue.h"

void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q, 0);
	SeqQueueEn(&Q, 1);
	SeqQueueEn(&Q, 3);
	SeqQueueEn(&Q, 5);
	SeqQueueEn(&Q, 4);
	SeqQueueEn(&Q, 2);
	SeqQueueEn(&Q, 2);
	SeqQueueEn(&Q, 2);
	SeqQueueEn(&Q, 3);
	SeqQueueShow(&Q);
	printf("=======================\n");
	SeqQueueDe(&Q);
	SeqQueueShow(&Q);
	printf("=======================\n");
	SeqQueueEn(&Q, 3);
	SeqQueueShow(&Q);
	printf("\nfront val = %d.\n", SeqQueueFront(&Q));
	printf("\nback val = %d.\n", SeqQueueBack(&Q));


}


/*链队列
int main()
{
	LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueueEn(&Q, 1);
	LinkQueueEn(&Q, 2);
	LinkQueueEn(&Q, 3);
	LinkQueueEn(&Q, 4);
	LinkQueueEn(&Q, 5);
	LinkQueueShow(&Q);
	printf("=======================\n");
	LinkQueueDe(&Q);
	LinkQueueShow(&Q);

	LinkQueueDestroy(&Q);

	return 0;
}
*/

/*链栈
int main()
{
	LinkStack st;
	LinkStackInit(&st);
	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 5);
	LinkStackShow(&st);
	printf("=======================\n");
	printf("%d出栈.\n", LinkStackTop(&st));
	printf("\n");
	LinkStackPop(&st);
	LinkStackShow(&st);

	LinkStackDestroy(&st);
	return 0;
}
*/


/*顺序栈
int main()
{
	SeqStack st;
	SeqStackInit(&st, 0);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackShow(&st);
	printf("=======================\n");
	while (!IsEmpty(&st))
	{
		StackElemType val = SeqStackTop(&st);//先取栈顶元素
		printf("%d出栈.\n", val);
		SeqStackPop(&st);//然后将栈顶元素出栈
	}
	printf("出栈完毕.\n");

	SeqStackDestroy(&st);
	return 0;
}
*/