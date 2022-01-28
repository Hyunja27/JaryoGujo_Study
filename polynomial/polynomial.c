
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

//degree : 5 <-> 6 4 1 2   
// void rearrangePolyList(polyList* pList){

// 	int len = pList->currentElementCount;

// 	struct polyNodeType* tmp[len];
	
// 	polyNode *now = pList->headerNode.pRLink;
	
// 	int idx = 0;

// 	while (now != &(pList->headerNode)){
// 		tmp[idx] = now;
// 		tmp[idx]->pLLink = NULL;
// 		tmp[idx]->pRLink = NULL;
// 	}
// }


// => 원격협업 시자악!

int	addPolyNode(polyList *pList, int coef, int expo)
{
	polyNode *curr = pList->headerNode.pRLink;
	polyNode *node;

	if (!pList)
		return FALSE;
	node = (polyNode *)malloc(sizeof(polyNode));
	if (!node)
		return FALSE;

	node->coef = coef;
	node->expo = expo;

	node->pLLink = 0;
	node->pRLink = 0;

	//리스트가 비어있거나, 인자로 들어온 expo가 최고차항일 경우
	if (pList->currentElementCount == 0){
		curr = node;
		node->pLLink = &(pList->headerNode);
		node->pRLink = &(pList->headerNode);
		pList->headerNode.pRLink = node;
		pList->headerNode.pLLink = node;
		pList->currentElementCount++;
		return (TRUE);

	}
	else if (curr->expo < expo){
		node->pRLink = pList->headerNode.pRLink;
		node->pLLink = &(pList->headerNode);
		curr->pLLink = node;
		pList->headerNode.pRLink = node;
		pList->currentElementCount++;
		return (TRUE);
	}
	else{
		while ((curr->pRLink) != &(pList->headerNode))
		{
			//기존 노드 중에 동일한 expo를 가진 노드가 있을 경우
			if (curr->expo == node->expo)
			{
				curr->coef += coef;
				return (TRUE);
			}
			curr = curr->pRLink;
		}
	}
	pList->headerNode.pLLink->pRLink = node;
	node->pLLink = pList->headerNode.pLLink;
	node->pRLink = &(pList->headerNode);
	pList->headerNode.pLLink = node;
	pList->currentElementCount++;
	return (TRUE);
}


polyList* sumPolyList(polyList *A, polyList *B)
{
	//A :        5x^2 + 6x
	//B : 4x^3 +         x  + 6
	//C : 4x&3 + 5x^2  +7x  + 6
	polyList *C; //C라는 다항식 그릇
	C = createpolyList(); //그릇에 메모리 할당
	polyNode *A_curr = A->headerNode.pRLink;
	polyNode *A_end = A->headerNode.pLLink;
	polyNode *B_curr = B->headerNode.pRLink;
	polyNode *B_end = B->headerNode.pLLink;

	// C에다가 A를 add
	while (A_curr != A_end->pRLink){
		addPolyNode(C, A_curr->coef, A_curr->expo);
		A_curr = A_curr->pRLink;
	}
	// C에다가 B를 add
	while (B_curr != B_end->pRLink){
		addPolyNode(C, B_curr->coef, B_curr->expo);
		B_curr = B_curr->pRLink;
	}
	return (C);
}



