//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string.h>
//
//using namespace std;
//
//class MyString 
//{
//private:
//    char* str;
//public:
//    // 构造函数
//    MyString(const char* s) 
//    {
//        str = new char[strlen(s) + 1];
//        strcpy(str, s);
//    }
//
//    // 拷贝构造函数
//    MyString(const MyString& other) 
//    {
//        str = new char[strlen(other.str) + 1];
//        strcpy(str, other.str);
//    }
//
//    // 拷贝赋值操作符重载
//    MyString& operator=(const MyString& other) 
//    {
//        if (this != &other) {
//            delete[] str;
//            str = new char[strlen(other.str) + 1];
//            strcpy(str, other.str);
//        }
//        return *this;
//    }
//
//    // 析构函数
//    ~MyString() 
//    {
//        delete[] str;
//    }
//
//    // 打印字符串
//    void print() 
//    {
//        std::cout << str << std::endl;
//    }
//};
//
//int main() {
//    MyString str1("Hello");
//    MyString str2 = str1; // 调用拷贝构造函数，进行深拷贝
//    str2.print();
//
//    MyString str3("World");
//    str3 = str2; // 调用拷贝赋值操作符重载，进行深拷贝
//    str3.print();
//
//    return 0;
//}

#include <string>
#include <iostream>
using namespace std;

class Employee
{
public:
	Employee(const string& n, int d)
	{
		name = n;
		department = d;
	}

	void print()const
	{
		cout << name << " " << department << endl;
	}

protected:
	string name;
	int department;
};

class Manager :public Employee
{
public:
	Manager(const string& n, int d, int lvl)
		:Employee(n, d)
		, level(lvl)
	{}

	void print()const
	{
		cout << name << " " << department << endl;
	}

private:
	int level;
};

int main()
{
	Manager m("haha", 1, 2);
	m.Manager::print();
	return 0;
}