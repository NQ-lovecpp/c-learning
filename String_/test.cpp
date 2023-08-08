#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;
#include "string.h"



int main()
{

	string s1 = "hello worldxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	string s2(s1);
	cout << sizeof(s1) << endl;
	cout << (void*)s1.c_str() << endl;
	cout << (void*)s2.c_str() << endl;
		
	return 0;
}

//bit::test_string3();

//string s1;
//cout << s1.capacity() << endl;

//string s2("hello world");
//cout << s2.capacity() << endl;


//cout << sizeof(s1) << endl;
//cout << sizeof(s2) << endl;