#include "linkedlist.h"


int main(void)
{
    LinkedList* List;
    
    ListNode *tmp1 = malloc(sizeof(ListNode));
    tmp1->data = 1;
    ListNode *tmp2 = malloc(sizeof(ListNode));
    tmp2->data = 2;
    ListNode *tmp3 = malloc(sizeof(ListNode));
    tmp3->data = 3;
    ListNode *tmp4 = malloc(sizeof(ListNode));
    tmp4->data = 4;
    ListNode *tmp5 = malloc(sizeof(ListNode));
    tmp5->data = 5;
    ListNode *tmp6 = malloc(sizeof(ListNode));
    tmp6->data = 6;
    ListNode *tmp7 = malloc(sizeof(ListNode));
    tmp7->data = 7;
    ListNode *tmp8 = malloc(sizeof(ListNode));
    tmp8->data = 8;
    ListNode *tmp9 = malloc(sizeof(ListNode));
    tmp9->data = 9;
    ListNode *tmp10 = malloc(sizeof(ListNode));
    tmp10->data = 10;
    ListNode *getRT = malloc(sizeof(ListNode));


    // ===============basic start====================

    printf("\n===============basic start====================\n");

    List = createLinkedList();

    printf("\nlist elem_count: %d \n\n", List->currentElementCount);

    int rt = 0;

    rt = pushLLElement(List, tmp1);
    rt = pushLLElement(List, tmp2);
    rt = pushLLElement(List, tmp3);
    rt = pushLLElement(List, tmp4);
    rt = pushLLElement(List, tmp5);
    rt = pushLLElement(List, tmp6);
    rt = pushLLElement(List, tmp7);
    
    printf("\nlist elem_count: %d \n\n", List->currentElementCount);
    displayList(List);

    // ===============basic end====================
    // ===============index add====================
    printf("\n===============index add====================\n");

    addLLElement(List, 8, tmp10);

    displayList(List);

    // ===============index add end====================
    // ===============index del =======================
    printf("\n===============index del====================\n");

    removeLLElement(List, 1);
    
    displayList(List);

    // ===============index del end====================
    // ===============get elem ========================
    printf("\n===============get elem====================\n");

    getRT = getLLElement(List, 1);

    displayList(List);
    printf("-> elem cnt: %d\n", List->currentElementCount);
    printf("-> get elem: %d\n\n", getRT->data);

    // ===============get elem end=====================
    // ===============revert ========================
    printf("\n===============revert====================\n");

    ListRevert(List);

    displayList(List);
    printf("-> elem cnt: %d\n", List->currentElementCount);
    printf("-> get elem: %d\n\n", getRT->data);
    

    // ===============get elem end=====================
    // ===============list clear ======================
    


    // ===============get elem end=====================
    // ===============list clear ======================
    printf("\n===============list clear====================\n");

    clearLinkedList(List);

    displayList(List);
    // // display 시도해도 무관. 단순히 정리만 한 것! 
    printf("-> elem cnt: %d", List->currentElementCount);

    // ===============list clear end===================
    // ===============list del ========================
    // printf("\n===============list del====================\n");

    // deleteLinkedList(List);

    // displayList(List);
    // // display 시도 시 Seg 폭망! 

    // system("leaks a.out");
    return 0;
}

// printf("\nhere?!\n");
