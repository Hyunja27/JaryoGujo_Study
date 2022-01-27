
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

	tmp_list->currentElementCount = 0;

	return (tmp_list);
}

// ============================= Basic Func =============================

int addLLElement(LinkedList* pList, int position, ListNode element){
	if (position + 1 > pList->currentElementCount || position < 0)
	{
		fprintf(stderr, "add position Index Error.");
		return (-1);
	}

	ListNode *now = &(pList->headerNode);
	ListNode *tmp = NULL;

	int idx = 1;

	for (idx = 1; idx < position - 1; idx++)
		now = now->pLink;

	if (idx == 1){
		element.pLink = now;
		pList->headerNode = element;
	}
	else if (now->pLink == NULL){
		now->pLink = &element;
	}
	else{
		tmp = now->pLink;
		now->pLink = &element;
		element.pLink = tmp;
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
	
	ListNode *now = &(pList->headerNode);
	ListNode *tmp = NULL;

	int idx = 1;

	for (idx = 1; idx < position - 1; idx++)
		now = now->pLink;

	if (idx == 1){
		tmp = pList->headerNode.pLink;
		free(now);
		pList->headerNode = *tmp;
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
		return (-1);
	}

	ListNode *now = &(pList->headerNode);

	int idx = 1;

	for (idx = 1; idx < position; idx++)
		now = now->pLink;
	
	return (now);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode *now = &(pList->headerNode);
	ListNode *tmp = NULL;

	while (now->pLink == NULL){
		tmp = now->pLink;
		free(now);
		now->pLink = tmp;
		pList->currentElementCount--;
	}
	free(now);
	pList->currentElementCount--;
	// pList의 헤더노드를 어떻게 안전히 초기화할까? 
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList);
