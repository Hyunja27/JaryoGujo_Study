#pragma once

#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>


// ============================= Basic Structure =============================

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// ���� ����� ������ ����
	ListNode headerNode;		// ��� ���(Header Node)
} LinkedList;



// ============================= Basic init =============================

LinkedList* createLinkedList();


// ============================= Basic init =============================

int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif