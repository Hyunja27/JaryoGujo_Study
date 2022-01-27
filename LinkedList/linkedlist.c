
#include "linkedlist.h"

// ============================= Basic Structure =============================

// typedef struct ListNodeType
// {
// 	int data;
// 	struct ListNodeType* pLink;
// } ListNode;

// typedef struct LinkedListType
// {
// 	int currentElementCount;	// ���� ����� ������ ����
// 	ListNode headerNode;		// ��� ���(Header Node)
// } LinkedList;



// ============================= Basic init =============================

LinkedList* createLinkedList(void){

	// (Q) 빈 노드를 하나 넣어서 링크드리스트의 멤버변수 형태를 다 초기화해야할까?!
	// 	   아니면, 하단과 같이 "링크드리스트" 만 짜서 리턴해야 할까?

	LinkedList *tmp_list = malloc(sizeof(LinkedList));
	ListNode *tmp_node = malloc(sizeof(ListNode));

	tmp_node->data = 0;
	tmp_node->pLink = NULL;

	tmp_list->currentElementCount = 0;
	tmp_list->headerNode = *(tmp_node);

	return (tmp_list);
}

// ============================= Basic Func =============================

int pushLLElement(LinkedList* pList, ListNode *element){
	
	ListNode *now = pList->headerNode.pLink;

	if (pList->currentElementCount == 0)
		pList->headerNode.pLink = element;
	else{
		while (now->pLink != NULL)
			now = now->pLink;	
		now->pLink = element;
	}

	element->pLink = NULL;
	pList->currentElementCount++;
	return (pList->currentElementCount);
}

int addLLElement(LinkedList* pList, int position, ListNode *element){
	if (position> pList->currentElementCount + 1 || position < 0)
	{
		fprintf(stderr, "add position Index Error.");
		return (-1);
	}

	ListNode *now = pList->headerNode.pLink;
	ListNode *tmp = NULL;

	int idx = 1;

	for (idx = 1; idx < position - 1; idx++)
		now = now->pLink;

	if (idx == 1){
		if (pList->currentElementCount != 0)
			element->pLink = now;
		else
			element->pLink = NULL;
		pList->headerNode.pLink = element;
	}
	else if (now->pLink == NULL){
		now->pLink = element;
		element->pLink = NULL;
	}
	else{
		tmp = now->pLink;
		now->pLink = element;
		element->pLink = tmp;
	}
	pList->currentElementCount++;
	return (position);
}

int removeLLElement(LinkedList* pList, int position){

	if (position > pList->currentElementCount || position < 0)
	{
		fprintf(stderr, "delete position Index Error.");
		return (-1);
	}
	
	ListNode *now = pList->headerNode.pLink;
	ListNode *tmp = NULL;

	int idx = 1;

	for (idx = 1; idx < position - 1; idx++)
		now = now->pLink;

	if (idx == 1){
		tmp = now->pLink;
		free(now);
		pList->headerNode.pLink = tmp;
	}
	else if (now->pLink->pLink == NULL){
		free(now->pLink);
		now->pLink = NULL;
	}
	else{
		tmp = now->pLink->pLink;
		free(now->pLink);
		now->pLink = tmp;
	}
	pList->currentElementCount--;
	return (position);
}


ListNode* getLLElement(LinkedList* pList, int position)
{
	if (position > pList->currentElementCount || position < 0)
	{
		fprintf(stderr, "get position Index Error.");
		return (NULL);
	}

	ListNode *now = pList->headerNode.pLink;

	int idx = 1;

	for (idx = 1; idx < position; idx++)
		now = now->pLink;
	
	return (now);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode *now = pList->headerNode.pLink;
	ListNode *tmp = NULL;

	if (pList->currentElementCount == 0)
	{
		pList->headerNode.pLink = NULL;
		pList->headerNode.data = 0;
		return ;
	}
	while (now->pLink != NULL){
		tmp = now->pLink;
		free(now);
		now = tmp;
	}
	free(now);
	pList->currentElementCount = 0;
	pList->headerNode.pLink = NULL;
	// pList의 헤더노드를 어떻게 안전히 초기화할까? 
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(&(pList->headerNode));
}

void displayList(LinkedList* pList){
	if (pList->currentElementCount <= 0 )
	{
		fprintf(stderr, "No element in D_list to Display.\n");
		return ;
	}
	
	ListNode *head = pList->headerNode.pLink;

	printf(" == Linked_List == \n\n [Head] -> ");
	
	while (head->pLink != NULL){
		printf("%d -> ",head->data);
		head = head->pLink;
	}
	printf("%d [End]\n\n == Dispaly_End == \n\n\n",head->data);
}

void ListRevert(LinkedList* pList){
	ListNode *lead = pList->headerNode.pLink;
	ListNode *center = NULL;
	ListNode *back = NULL;

	while(lead){
		back = center;
		center = lead;
		lead = lead->pLink;
		center->pLink = back;
	}
	pList->headerNode.pLink = center;
}
