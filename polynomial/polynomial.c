
#include "polynomial.h"

// ============================= Basic Structure =============================

// typedef struct polyNodeType
// {
// 	int coef;
//  int expo;
// 	struct polyNodeType* pLLink;
// 	struct polyNodeType* pRLink;
// } polyNode;

// typedef struct polyListType
// {
// 	int	currentElementCount;		// ���� ����� ������ ����
// 	polyNode	headerNode;		// ��� ���(Header Node)
// } polyList;

// ============================= Basic init =============================

polyList* createpolyList(void){
	polyList *tmp_Dlist = malloc(sizeof(polyList));
	polyNode *tmp_polynode = malloc(sizeof(polyNode));

	tmp_polynode->coef = 0;
	tmp_polynode->expo = 0;
	tmp_polynode->pLLink = NULL;
	tmp_polynode->pRLink = NULL;

	tmp_Dlist->currentElementCount = 0;
	tmp_Dlist->headerNode = *(tmp_polynode);
	
	return (tmp_Dlist);
}

// ============================= Basic Func =============================

void deletepolyList(polyList* pList){
	
	polyNode *head = pList->headerNode.pRLink;
	polyNode *tail = pList->headerNode.pLLink;
	polyNode *target;

	while (head != tail){
		target = head;
		head = head->pRLink;
		free(target);
	}
	free(head);
	head = NULL;
	tail = NULL;
	free(&(pList->headerNode));
	free(pList);
	pList = NULL;
}

int pushDLElement(polyList* pList, polyNode *element){
	
	polyNode *now = pList->headerNode.pLLink;

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

int addDLElement(polyList* pList, int position, polyNode *element){
	
	if (position > pList->currentElementCount + 1 || position < 0)
	{
		fprintf(stderr, "add position Index Error.\n");
		return (-1);
	}

	polyNode *now = pList->headerNode.pRLink;
	int idx = 1;

	for (idx = 1; idx < position - 1; idx++)
		now = now->pRLink;

	if (idx == 1){
		if (pList->currentElementCount != 0){
			element->pRLink = now;
			element->pLLink = &(pList->headerNode);
			pList->headerNode.pRLink = element;
		}
		else{
			element->pLLink = &(pList->headerNode);
			element->pRLink = &(pList->headerNode);
			pList->headerNode.pRLink = element;
			pList->headerNode.pLLink = element;
		}
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

int removeDLElement(polyList* pList, int position){

	if (position > pList->currentElementCount || position < 0)
	{
		fprintf(stderr, "delete position Index Error.\n");
		return (-1);
	}

	polyNode *now = pList->headerNode.pRLink;
	polyNode *tmp;
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

void clearpolyList(polyList* pList){
	polyNode *head = pList->headerNode.pRLink;
	polyNode *tail = pList->headerNode.pLLink;
	polyNode *target;

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

int getpolyListLength(polyList* pList){
	return (pList->currentElementCount);
}

polyNode* getDLElement(polyList* pList, int position){
	
	if (position > pList->currentElementCount || position < 0)
	{
		fprintf(stderr, "get position Index Error.\n");
		return (NULL);
	}

	polyNode *now = pList->headerNode.pRLink;
	polyNode *tmp;
	int idx = 1;

	for (idx = 1; idx < position; idx++)
		now = now->pRLink;
	return (now);
}

void displaypolyList(polyList* pList){
	if (pList->currentElementCount <= 0 )
	{
		fprintf(stderr, "No element in D_list to Display.\n");
		return ;
	}
	
	polyNode *head = pList->headerNode.pRLink;
	polyNode *tail = pList->headerNode.pLLink;

	printf(" == polynomial_List == \n\n [Head] <-> ");
	
	while (head != tail){
		printf("%dx^%d <-> ",head->coef, head->expo);
		head = head->pRLink;
	}
	printf("%dx^%d <-> [tail (A.K.A Head)]\n\n == Dispaly_End == \n\n\n",head->coef, head->expo);
}

void rearrangePolyList(polyList* pList){
	int len = pList->currentElementCount;
	struct polyNodeType* tmp[len];
	polyNode *now = pList->headerNode.pRLink;
	int idx = 0;

	while (now != &(pList->headerNode)){
		tmp[idx] = now;
		tmp[idx]->pLLink = NULL;

	}
}

void sumPolyList();

