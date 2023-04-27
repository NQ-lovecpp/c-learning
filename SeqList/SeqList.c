#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

void SLInit(SL* ps1)
{
	ps1->a = malloc(sizeof(SLDatatype)*4);
	if (ps1->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps1->capacity = 4;
	ps1->size = 0;
}

void SLDestroy(SL* ps1)
{
	free(ps1->a);
	ps1->a = NULL;
	ps1->size = 0;
	ps1->capacity = 0;
}

void SLCheckCapacity(SL* ps1)
{
	if (ps1->size == ps1->capacity)
	{
		SLDatatype* tmp = (SLDatatype*)realloc(ps1->a, sizeof(SLDatatype) * (ps1->capacity) * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps1->a = tmp;
		ps1->capacity *= 2;
	}
}

void SLPushBack(SL* ps1, SLDatatype x)
{
	SLCheckCapacity(ps1);
	ps1->a[ps1->size] = x;
	ps1->size++;
}


void SLPrint(SL* ps1)
{
	for (int i = 0;i < ps1->size;i++)
	{
		printf("%d ", ps1->a[i]);
	}

}
void SLPushFront(SL* ps1, SLDatatype x)
{
	SLCheckCapacity(ps1);
	//Å²¶¯Êý¾Ý
	int end = ps1->size - 1;
	while (end >= 0)
	{
		ps1->a[end + 1] = ps1->a[end];
		--end;
	}
}
void SLPopBack(SL* ps1)
{

}
void SLPopFront(SL* ps1);