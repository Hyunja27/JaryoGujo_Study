#ifndef _BANKSIMULATOR_H_
#define _BANKSIMULATOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	char name;
	int arrivalTime;//도착시간
	int serviceTime;//서비스시간
	int startTime;//시작시간
	int endTime;//종료시각 : 시작시각 + 서비스 시간
} SimCustomer;


typedef struct ArrayQueueNodeType
{
	SimCustomer data;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
	int maxElementCount;		// �ִ� ���� ����
	int currentElementCount;	// ���� ������ ����
	int front;					// front ��ġ
	int rear;					// rear ��ġ
	ArrayQueueNode *pElement;	// ��� ������ ���� 1���� �迭 ������
} ArrayQueue;

ArrayQueue* createArrayQueue(int maxElementCount);
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode *peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif