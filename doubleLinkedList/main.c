#include "doubleLinkedList.h"


int main(void)
{
    DoublyList* dList;
    
    DoublyListNode *tmp1 = malloc(sizeof(DoublyListNode));
    tmp1->data = 1;
    DoublyListNode *tmp2 = malloc(sizeof(DoublyListNode));
    tmp2->data = 2;
    DoublyListNode *tmp3 = malloc(sizeof(DoublyListNode));
    tmp3->data = 3;
    DoublyListNode *tmp4 = malloc(sizeof(DoublyListNode));
    tmp4->data = 4;
    DoublyListNode *tmp5 = malloc(sizeof(DoublyListNode));
    tmp5->data = 5;
    DoublyListNode *tmp6 = malloc(sizeof(DoublyListNode));
    tmp6->data = 6;
    DoublyListNode *tmp7 = malloc(sizeof(DoublyListNode));
    tmp7->data = 7;
    DoublyListNode *tmp8 = malloc(sizeof(DoublyListNode));
    tmp8->data = 8;
    DoublyListNode *tmp9 = malloc(sizeof(DoublyListNode));
    tmp9->data = 9;
    DoublyListNode *tmp10 = malloc(sizeof(DoublyListNode));
    tmp10->data = 10;
    DoublyListNode *getRT = malloc(sizeof(DoublyListNode));


    dList = createDoublyList();

    printf("\nlist elem_count: %d \n\n", dList->currentElementCount);

    int rt = 0;

    rt = pushDLElement(dList, tmp1);
    rt = pushDLElement(dList, tmp2);
    rt = pushDLElement(dList, tmp3);
    rt = pushDLElement(dList, tmp4);
    rt = pushDLElement(dList, tmp5);
    rt = pushDLElement(dList, tmp6);
    rt = pushDLElement(dList, tmp7);
    
    printf("\nlist elem_count: %d \n\n", dList->currentElementCount);
    displayDoublyList(dList);

    // ===============basic end====================
    // ===============index add====================

    addDLElement(dList, 8, tmp10);

    displayDoublyList(dList);

    // ===============index add end====================
    // ===============index del =======================

    // removeDLElement(dList, 8);

    // displayDoublyList(dList);

    // ===============index del end====================
    // ===============get elem ========================

    getRT = getDLElement(dList, 7);

    displayDoublyList(dList);
    printf("-> elem cnt: %d\n", dList->currentElementCount);
    printf("-> get elem: %d\n\n", getRT->data);

    // ===============get elem end=====================
    // ===============list clear ======================

    clearDoublyList(dList);

    displayDoublyList(dList);
    // // display 시도해도 무관. 단순히 정리만 한 것! 
    printf("-> elem cnt: %d", dList->currentElementCount);

    // ===============list clear end===================
    // ===============list del ========================

    // deleteDoublyList(dList);

    // displayDoublyList(dList);
    // // display 시도 시 Seg 폭망! 

    system("leaks a.out");
    return 0;
}

// printf("\nhere?!\n");
