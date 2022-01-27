
#include "doubleLinkedList.h"

// ============================= Basic Structure =============================

// typedef struct DoublyListNodeType
// {
// 	int data;
// 	struct DoublyListNodeType* pLLink;
// 	struct DoublyListNodeType* pRLink;
// } DoublyListNode;

// typedef struct DoublyListType
// {
// 	int	currentElementCount;		// ���� ����� ������ ����
// 	DoublyListNode	headerNode;		// ��� ���(Header Node)
// } DoublyList;


// ============================= Basic init =============================

DoublyList* createDoublyList(void){
	DoublyList *tmp_Dlist = malloc(sizeof(DoublyList));
	DoublyListNode *tmp_Dnode = malloc(sizeof(DoublyListNode));

	tmp_Dnode->data = 0;
	tmp_Dnode->pLLink = NULL;
	tmp_Dnode->pRLink = NULL;

	tmp_Dlist->currentElementCount = 0;
	tmp_Dlist->headerNode = *(tmp_Dnode);
	
	return (tmp_Dlist);
}

// ============================= Basic Func =============================

void deleteDoublyList(DoublyList* pList){
	
	DoublyListNode *head = pList->headerNode.pRLink;
	DoublyListNode *tail = pList->headerNode.pLLink;
	DoublyListNode *target;

	while (head != tail){
		target = head;
		head = head->pRLink;
		free(target);
	}
	free(head);
	head = NULL;
	tail = NULL;
	free(pList);
	pList = NULL;
}

int pushDLElement(DoublyList* pList, DoublyListNode *element){
	
	DoublyListNode *now = pList->headerNode.pLLink;

	if (pList->currentElementCount == 0){
		element->pRLink = &(pList->headerNode);
		element->pLLink = &(pList->headerNode);
		pList->headerNode.pLLink = element;
		pList->headerNode.pRLink = element;
	}
	else {	
		element->pRLink = &(pList->headerNode);
		element->pLLink = now;
		now->pRLink = element;
		pList->headerNode.pLLink = element;
	}
	pList->currentElementCount++;
	return (pList->currentElementCount);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode *element){
	
	if (position > pList->currentElementCount + 1 || position < 0)
	{
		fprintf(stderr, "add position Index Error.\n");
		return (-1);
	}

	DoublyListNode *now = pList->headerNode.pRLink;
	int idx = 1;

	for (idx = 1; idx < position - 1; idx++)
		now = now->pRLink;

	if (idx == 1){
		element->pRLink = now;
		element->pLLink = &(pList->headerNode);
		pList->headerNode.pRLink = element;
	}
	else if (now->pRLink == &(pList->headerNode)){
		element->pRLink = &(pList->headerNode);
		element->pLLink = now;
		now->pRLink = element;
		pList->headerNode.pLLink = element;
	}
	else{
		element->pRLink = now->pRLink;
		element->pLLink = now;

		now->pRLink->pLLink = element;
		now->pRLink = element;
	}
	pList->currentElementCount++;
	return (position);
}

int removeDLElement(DoublyList* pList, int position){

	if (position > pList->currentElementCount || position < 0)
	{
		fprintf(stderr, "delete position Index Error.\n");
		return (-1);
	}

	DoublyListNode *now = pList->headerNode.pRLink;
	DoublyListNode *tmp;
	int idx = 1;

	for (idx = 1; idx < position; idx++)
		now = now->pRLink;

	if (idx == 1){
		tmp = now->pRLink;
		tmp->pLLink = &(pList->headerNode);
		pList->headerNode.pRLink = tmp;
		free(now);
	}
	else if (now->pRLink == &(pList->headerNode)){
		tmp = now->pLLink;
		tmp->pRLink = &(pList->headerNode);
		pList->headerNode.pLLink = tmp;

		free(now);
	}
	else{
		now->pRLink->pLLink = now->pLLink;
		now->pLLink->pRLink = now->pRLink;
		free(now);
	}
	pList->currentElementCount--;
	return (position);
}

void clearDoublyList(DoublyList* pList){
	DoublyListNode *head = pList->headerNode.pRLink;
	DoublyListNode *tail = pList->headerNode.pLLink;
	DoublyListNode *target;

	while (head != tail){
		target = head;
		head = head->pRLink;
		free(target);
	}
	free(head);
	pList->currentElementCount = 0;
	pList->headerNode.pLLink = NULL;
	pList->headerNode.pRLink = NULL;
}

int getDoublyListLength(DoublyList* pList){
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position){
	
	if (position > pList->currentElementCount || position < 0)
	{
		fprintf(stderr, "get position Index Error.\n");
		return (NULL);
	}

	DoublyListNode *now = pList->headerNode.pRLink;
	DoublyListNode *tmp;
	int idx = 1;

	for (idx = 1; idx < position; idx++)
		now = now->pRLink;
	return (now);
}

void displayDoublyList(DoublyList* pList){
	if (pList->currentElementCount <= 0 )
	{
		fprintf(stderr, "No element in D_list to Display.\n");
		return ;
	}
	
	DoublyListNode *head = pList->headerNode.pRLink;
	DoublyListNode *tail = pList->headerNode.pLLink;

	printf(" == Double_Linked_List == \n\n [Head] <-> ");
	
	while (head != tail){
		printf("%d <-> ",head->data);
		head = head->pRLink;
	}
	printf("%d <-> [tail (A.K.A Head)]\n\n == Dispaly_End == \n\n\n",head->data);
}
