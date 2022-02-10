#include "./arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue* tmp = malloc(sizeof(ArrayQueue));

    tmp->maxElementCount = maxElementCount;
    tmp->ArrayQueueNode = malloc(sizeof(ArrayQueueNode) * maxElementCount);
    tmp->currentElementCount = 0;
    tmp->front = 0;
    tmp->rear = 0;
    tmp->pElement = NULL;

    return (tmp);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    if (pQueue == NULL)
        return -1;
    if ((rear + 1) % pQueue->currentElementCount == front)
        return -1;
    pQueue->ArrayQueueNode[((rear + 1) % pQueue->maxElementCount)] = element;
    pQueue->rear += 1;
    
    return ((rear) % pQueue->maxElementCount);

}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    if (pQueue == NULL)
        return -1;
    if (rear == front)
        return -1;
    pQueue->front += 1
    ArrayQueueNode *tmp = pQueue->pElement[(front) % pQueue->maxElementCount];

    return (tmp);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    if (pQueue == NULL)
        return -1;
    if (rear == front)
        return -1;
    return (*(pQueue->pElement[(front + 1) % pQueue->maxElementCount]));
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
    if (pQueue == NULL)
        return -1;
    int i = pQueue->front;
    while (i++ != pQueue->rear)
    {
        if ((pQueue->pElement[i]) != NULL)
            free(pQueue->pElement[i]);
    }
    pQueue->front = 0;
    pQueue->rear = 0;
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
    if ((rear + 1) % pQueue->currentElementCount == front)
        return TRUE;
    else
        return FALSE;
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    if (rear == front)
        return TRUE;
    else
        return FALSE;
}