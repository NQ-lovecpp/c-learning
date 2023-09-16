#include <iostream>
#include <list>
#include <string>
#include "List.h"
using namespace std;

template<typename Container>
void print_container(const Container& con)
{
	typename Container::const_iterator it = con.begin();
	while (it != con.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;
}

int main()
{
	list<string> lt;
	lt.push_back("hello world1");
	lt.push_back("hello world2");
	lt.push_back("hello world3");
	lt.push_back("hello world4");
	lt.push_back("hello world5");
	lt.push_back("hello world6");
	print_container(lt);
	return 0;
}