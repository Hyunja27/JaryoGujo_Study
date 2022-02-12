#include "banksimulator.h"
// #include "arrayqueue.h"


ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue* tmp = malloc(sizeof(ArrayQueue));

    tmp->maxElementCount = maxElementCount;
    tmp->pElement = malloc(sizeof(ArrayQueueNode) * maxElementCount);
    tmp->currentElementCount = 0;
    tmp->front = 0;
    tmp->rear = 0;
    return (tmp);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    if (!pQueue)
        return -1;
    if (((pQueue->rear + 1) % pQueue->maxElementCount) == pQueue->front)
    {
        printf("Full! \n");
        return -1;
    }
    pQueue->pElement[((pQueue->rear + 1) % pQueue->maxElementCount)] = element;
    pQueue->rear += 1;
    
    return ((pQueue->rear) % pQueue->maxElementCount);

}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    if (!pQueue)
        return 0;
    if (pQueue->rear == pQueue->front)
        return 0;
    
    // ArrayQueueNode *tmp = &(pQueue->pElement[(pQueue->front) % pQueue->maxElementCount]);
    // tmp->data.status = 0
    // tmp->data.name = ''
    // tmp->data.serviceTime = 0
    // tmp->data.arrivalTime = 0
    
    pQueue->front += 1;
    ArrayQueueNode *tmp = &(pQueue->pElement[(pQueue->front) % pQueue->maxElementCount]);
    return (tmp);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    if (!pQueue)
        return 0;
    if (pQueue->rear == pQueue->front)
        return 0;
    return (&(pQueue->pElement[(pQueue->front + 1) % pQueue->maxElementCount]));
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
    if (!pQueue)
        return;
    int i = pQueue->front;
    free(pQueue->pElement);
    pQueue->front = 0;
    pQueue->rear = 0;
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
    if ((pQueue->rear + 1) % pQueue->maxElementCount == pQueue->front)
        return TRUE;
    else
        return FALSE;
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    if (pQueue->rear == pQueue->front)
        return TRUE;
    else
        return FALSE;
}