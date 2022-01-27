#pragma once

#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct polyNodeType
{
	int coef;
    int expo;
	struct polyNodeType* pLLink;
	struct polyNodeType* pRLink;
} polyNode;

typedef struct polyListType
{
	int	currentElementCount;		// ���� ����� ������ ����
	polyNode	headerNode;		// ��� ���(Header Node)
} polyList;

polyList* createpolyList();
void deletepolyList(polyList* pList);
int addDLElement(polyList* pList, int position, polyNode *element);
int removeDLElement(polyList* pList, int position);
void clearpolyList(polyList* pList);
int getpolyListLength(polyList* pList);
polyNode* getDLElement(polyList* pList, int position);
void displaypolyList(polyList* pList);
int pushDLElement(polyList* pList, polyNode *element);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif