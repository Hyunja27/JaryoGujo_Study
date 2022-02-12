#include "banksimulator.h" 

int main(void)
{
    ArrayQueue  *readyQueue;
    ArrayQueue  *arrivalQueue;
	ArrayQueueNode tmp;
	ArrayQueueNode *servising;
	int time = 0;
	int endtime = 15;
	servising = NULL;
	readyQueue = createArrayQueue(10);
	arrivalQueue = createArrayQueue(10);
	
	char Customer[5] = {'H', 'S', 'I' , 'N', 'U'};
	int serviceTime[5] = {1, 2, 3, 4, 5};
	int arrivalTime[5] = {0, 2, 4, 6, 7};
	
	int i = 0;
	while (i < 5)
	{
		tmp.data.serviceTime = serviceTime[i];
		tmp.data.arrivalTime = arrivalTime[i];
		tmp.data.name = Customer[i];
		tmp.data.status = arrival;
		enqueueAQ(arrivalQueue, tmp);
		i++;
	}

	i = 0;
	while (i < 5)
	{
		printf("\n\n");
		printf("name -> %c \n",arrivalQueue->pElement[i+1].data.name);
		printf("serv -> %d \n",arrivalQueue->pElement[i+1].data.serviceTime);
		printf("arri -> %d \n\n",arrivalQueue->pElement[i+1].data.arrivalTime);
		// printf("stat -> %d \n\n",arrivalQueue->pElement[i+1].data.status);
		i++;
	}

	while (time != endtime)
	{
		if (peekAQ(arrivalQueue) && time == peekAQ(arrivalQueue)->data.arrivalTime)
			enqueueAQ(readyQueue,*(dequeueAQ(arrivalQueue)));
		
		if (servising && (servising->data.serviceTime + servising->data.startTime == time))//종료
		{
			servising->data.status = end;
			servising->data.endTime = time;
			servising = NULL;
		}

		if (servising == NULL)//시작
		{
			servising = dequeueAQ(readyQueue);
			if (servising != NULL)
			{
				servising->data.status = start;
				servising->data.startTime = time;
			}
		}
		
		i = readyQueue->front;

		printf("\n ========================= [ %d ] ===================================\n", time);
		while (i < readyQueue->rear)
		{
			printf("\n");
			printf("name -> %c \n",readyQueue->pElement[i+1].data.name);
			printf("serv -> %d \n",readyQueue->pElement[i+1].data.serviceTime);
			printf("arri -> %d \n",readyQueue->pElement[i+1].data.arrivalTime);
			printf("stat -> %d \n\n",arrivalQueue->pElement[i+1].data.status);
			
			i++;
		}

		if (servising)
		{
			printf("\n\n [ Now On working ]\n");
			printf("\n  ============= \n");
			printf("  | name -> %c |\n",servising->data.name);
			printf("  | serv -> %d |\n",servising->data.serviceTime);
			printf("  | arri -> %d |\n",servising->data.arrivalTime);
			printf("  ============= \n\n");
			
			printf("\n ===================================================================\n");
		}
		else
			printf("월급루팡\n");
		time++;
	}

	i = 0;
	printf("\n\n  [ ReadyQueue status on Now]\n");
	while (i < 5)
	{
		printf("\n");
		printf("name -> %c \n",readyQueue->pElement[i+1].data.name);
		printf("serv -> %d \n",readyQueue->pElement[i+1].data.serviceTime);
		printf("arri -> %d \n",readyQueue->pElement[i+1].data.arrivalTime);
		printf("stat -> %d \n",readyQueue->pElement[i+1].data.status);
		printf("startTime -> %d \n",readyQueue->pElement[i+1].data.startTime);
		printf("endTime -> %d \n",readyQueue->pElement[i+1].data.endTime);
		printf("waitTime -> %d \n",readyQueue->pElement[i+1].data.startTime - readyQueue->pElement[i+1].data.arrivalTime);
		i++;
	}
}