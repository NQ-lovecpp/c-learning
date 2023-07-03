#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

void TestList1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPopFront(plist);
	LTPrint(plist);
}

int main()
{
	TestList1();
	return 0;
}