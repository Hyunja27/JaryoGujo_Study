#include "polynomial.h"

int main(void)
{
    polyList* dList;
    polyList* targetList;
    polyList* targetList2;
    polyList* addTotalList;
    
    polyNode *tmp1 = malloc(sizeof(polyNode));
    tmp1->coef = 1;
    tmp1->expo = 5;
    polyNode *tmp2 = malloc(sizeof(polyNode));
    tmp2->coef = 2;
    tmp2->expo = 5;
    polyNode *tmp3 = malloc(sizeof(polyNode));
    tmp3->coef = 3;
    tmp3->expo = 6;
    polyNode *tmp4 = malloc(sizeof(polyNode));
    tmp4->coef = 4;
    tmp4->expo = 6;
    polyNode *tmp5 = malloc(sizeof(polyNode));
    tmp5->coef = 5;
    tmp5->expo = 10;
    polyNode *tmp6 = malloc(sizeof(polyNode));
    tmp6->coef = 6;
    tmp6->expo = 10;
    polyNode *tmp7 = malloc(sizeof(polyNode));
    tmp7->coef = 7;
    tmp7->expo = 15;
    polyNode *tmp8 = malloc(sizeof(polyNode));
    tmp8->coef = 8;
    tmp8->expo = 15;
    polyNode *tmp9 = malloc(sizeof(polyNode));
    tmp9->coef = 9;
    tmp9->expo = 20;
    polyNode *tmp10 = malloc(sizeof(polyNode));
    tmp10->coef = 10;
    tmp10->expo = 20;
    polyNode *getRT = malloc(sizeof(polyNode));


    dList = createpolyList();
    targetList = createpolyList();
    targetList2 = createpolyList();

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
    displaypolyList(dList);



    // ===============basic end====================
    // ===============index add====================



    addDLElement(dList, 8, tmp10);

    displaypolyList(dList);



    // ===============index add end====================
    // ===============index del =======================





    // removeDLElement(dList, 8);

    // displaypolyList(dList);



    // ===============index del end====================
    // ===============get elem ========================





    getRT = getDLElement(dList, 7);


    displaypolyList(dList);
    printf("-> elem cnt: %d\n", dList->currentElementCount);
    printf("-> get elem: %dx^%d\n\n", getRT->coef, getRT->expo);



    // ===============get elem end====================
    // ===============add poly ========================




    printf("\n\n ==== add polynomial test ====\n");

    rt = pushDLElement(targetList2, tmp3);
    rt = pushDLElement(targetList2, tmp4);
    rt = pushDLElement(targetList2, tmp5);
    rt = pushDLElement(targetList2, tmp6);
    rt = pushDLElement(targetList2, tmp7);
    rt = pushDLElement(targetList2, tmp8);
    rt = pushDLElement(targetList2, tmp9);


    rt = pushDLElement(targetList, tmp3);
    rt = pushDLElement(targetList, tmp4);
    rt = pushDLElement(targetList, tmp5);
    rt = pushDLElement(targetList, tmp6);
    rt = pushDLElement(targetList, tmp7);
    rt = pushDLElement(targetList, tmp8);
    rt = pushDLElement(targetList, tmp9);


    // addPolyNode(addTotalList, 10, 5);
    // displaypolyList(addTotalList);

    // addPolyNode(addTotalList, 5, 9);
    // displaypolyList(addTotalList);

    // addPolyNode(addTotalList, 15, 9);
    // displaypolyList(addTotalList);

	// printf("-> cnt: %d", addTotalList->currentElementCount);
    printf("\n\n ==== A polynomial ====\n");
    displaypolyList(targetList2);
    printf("\n\n ==== B polynomial ====\n");
    displaypolyList(targetList);
    addTotalList = sumPolyList(targetList2, targetList);
    printf("\n\n ==== total polynomial ====\n");
    displaypolyList(addTotalList);
	printf("-> cnt: %d", addTotalList->currentElementCount);

    printf("\n\n ==== add polynomial test end ====\n");



    // ===============add poly end=====================
    // ===============list clear ======================



    // displaypolyList(targetList2);
    // clearpolyList(targetList2);

    // displaypolyList(targetList2);
    // // // display 시도해도 무관. 단순히 정리만 한 것! 
    // printf("-> elem cnt: %d", targetList2->currentElementCount);




    // ===============list clear end===================
    // ===============list del ========================




    deletepolyList(targetList);

    // displaypolyList(targetList);
    // display 시도 시 Seg 폭망! 

    system("leaks a.out");
    return 0;
}




// printf("\nhere?!\n");
