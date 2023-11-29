//#include <iostream>
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//	string a = "hello world";
//	string b = a;
//	cout << (void*)(a.c_str()) << endl;
//	cout << (void*)(b.c_str()) << endl;
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//
//	string c = b;
//	c = "";
//	cout << (void*)(a.c_str()) << endl;
//	cout << (void*)(b.c_str()) << endl;
//	cout << (void*)(c.c_str()) << endl;
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//
//	a = "";
//	cout << (void*)(a.c_str()) << endl;
//	cout << (void*)(b.c_str()) << endl;
//	cout << (void*)(c.c_str()) << endl;
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	return 0;
//}#include <iostream>#include <string>using namespace std;class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
private:
	int haha = 0;
};
class Student : public Person
{
public:
	int _No; // 学号
};



int main()
{
	Student sobj;

	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//2.基类对象不能赋值给派生类对象
	//sobj = pobj;

	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sobj;
	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
	ps1->_No = 10;
	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_No = 10;
	return 0;
}