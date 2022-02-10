#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue* tmp = malloc(sizeof(ArrayQueue));

    tmp->maxElementCount = maxElementCount;
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
    
    if (rear + 1 == pQueue->maxArray)


}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode *peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);