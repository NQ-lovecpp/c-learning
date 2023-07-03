#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;      //top是栈顶的下一个位置的下标
	pst->capacity = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	if (pst->top == pst->capacity)
	{
		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity*2;
		STDataType* tmp = realloc(pst->a, newCapacity*sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newCapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));
	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));

	return pst->a[pst->top - 1];
}

int STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}

bool STEmpty(ST* pst)
{
	assert(pst);

	if (pst->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}