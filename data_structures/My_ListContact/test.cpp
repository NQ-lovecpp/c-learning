#pragma once
#include <iostream>
#include <cstdio>
#include <list>
#include <string>
using namespace std;
#include "Contact.h"

void menu()
{
	printf("********************************\n");
	printf("*****    1. add     2. del   ***\n");
	printf("*****    3. search  4. modify***\n");
	printf("*****    5. show    6. sort  ***\n");
	printf("*****    0. exit             ***\n");
	printf("********************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

int main()
{
	int input = 0;
	Contact c;
	do
	{
		menu();
		printf("请选择:>");
		cin >> input;
		switch (input)
		{
		case ADD:
			c.AddContact();
			break;
		case DEL:
			c.DelContact();
			break;
		case SEARCH:
			c.SearchContact();
			break;
		case MODIFY:
			c.ModifyContact();
			break;
		case SHOW:
			c.ShowContact();
			break;
		case SORT:
			break;
		case EXIT:
			cout << "结束,销毁中...";
			break;
		}
	} while (input);

	return 0;
}