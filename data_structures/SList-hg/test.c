#define _CRT_SECURE_NO_WARNINGS

//#include"SList.h"
//
//void TestSList1()
//{
//	SLTNode* plist = NULL;
//	SLPushFront(&plist, 1);
//	SLPushFront(&plist, 2);
//	SLPushFront(&plist, 3);
//	SLPushFront(&plist, 4);
//
//	SLTPrint(plist);
//
//}
//
//void TestSList2()
//{
//	SLTNode* plist = NULL;
//	SLPushBack(&plist, 1);
//	SLPushBack(&plist, 2);
//	SLPushBack(&plist, 3);
//	SLPushBack(&plist, 4);
//	SLTPrint(plist);
//
//	SLPopBack(&plist);
//	SLTPrint(plist);
//	SLPopBack(&plist);
//	SLTPrint(plist);
//	SLPopBack(&plist);
//	SLTPrint(plist);
//	SLPopBack(&plist);
//	SLTPrint(plist);
//
//	//SLPopBack(&plist);
//}
//
//void TestSList3()
//{
//	SLTNode* plist = NULL;
//	SLPushBack(&plist, 1);
//	SLPushBack(&plist, 2);
//	SLPushBack(&plist, 3);
//	SLPushBack(&plist, 4);
//	SLTPrint(plist);
//}
//
//int main()
//{
//	TestSList1();
//
//	return 0;
//}

#include "SList.h"

int main()
{
    SLTNode* phead = NULL;


    SLPushFront(&phead, 5);
    SLPushFront(&phead, 10);
    SLPushFront(&phead, 15);
    printf("After push front: ");
    SLTPrint(phead);


    SLPushBack(&phead, 20);
    SLPushBack(&phead, 25);
    SLPushBack(&phead, 30);

    SLTPrint(phead);


    SLPopFront(&phead);
    SLPopFront(&phead);

    SLTPrint(phead);


    SLPopBack(&phead);
    SLPopBack(&phead);

    SLTPrint(phead);

    return 0;
}