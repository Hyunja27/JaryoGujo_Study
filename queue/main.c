#include "arrayqueue.h"

// typedef struct ArrayQueueNodeType
// {
// 	char data;
// } ArrayQueueNode;

// typedef struct ArrayQueueType
// {
// 	int maxElementCount;		// �ִ� ���� ����
// 	int currentElementCount;	// ���� ������ ����
// 	int front;					// front ��ġ
// 	int rear;					// rear ��ġ
// 	ArrayQueueNode *pElement;	// ��� ������ ���� 1���� �迭 ������
// } ArrayQueue;

int main(void)
{
    ArrayQueue *Q;
    ArrayQueueNode a1;
    a1.data = 'a';
    ArrayQueueNode a2;
    a1.data = 'b';
    ArrayQueueNode a3;
    a1.data = 'c';
    ArrayQueueNode a4;
    a1.data = 'd';
    ArrayQueueNode a5;
    a1.data = 'e';

    Q = createArrayQueue(3);
    

    printf("max-> %d\n",Q->maxElementCount);
    printf("curr-> %d\n",Q->currentElementCount);
    printf("front-> %d\n",Q->front);
    printf("rear-> %d\n",Q->rear);

    enqueueAQ(Q, a1);
    dequeueAQ(Q);

    printf("max-> %d\n",Q->maxElementCount);
    printf("curr-> %d\n",Q->currentElementCount);
    printf("front-> %d\n",Q->front);
    printf("rear-> %d\n",Q->rear);

    return (0);
}