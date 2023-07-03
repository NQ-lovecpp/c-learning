#define _CRT_SECURE_NO_WARNINGS
#include"List.h"

LTNode* BuyLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

bool LTEmpty(LTNode* phead)
{
	if (phead->next = phead)
		return true;
	else
		return false;
}

LTNode* LTInit()
{
	LTNode* phead = BuyLTNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);

	printf("ÉÚ±øÎ»<==>");
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		printf("%d<==>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* tail = phead->prev;
	LTNode* newnode = BuyLTNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}


void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyLTNode(x);

	newnode->next = phead->next;
	phead->next->prev = newnode;

	phead->next = newnode;
	newnode->prev = phead;
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));

	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;

	free(tail);
	tailPrev->next = phead;
	phead->prev - tailPrev;
}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));

	LTNode* del = phead->next;
	phead->next = del->next;
	del->next->prev = phead;
	free(del);
	del = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x);

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* prev = pos->prev;
	LTNode* newnode = BuyLTNode(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->next=
}