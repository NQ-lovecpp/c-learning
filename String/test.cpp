#include <string>
#include <list>
#include <iostream>

using namespace std;

void test_string1()
{
	string s1;
	string s2("hello");

	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;

	string ret = s1 + s2 + "我来了";
	cout << ret << endl;
}

void test_string2()
{
	string s1 = "hello world";

	for (size_t i = 0;i < s1.size();i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0;i < s1.size();i++)
	{
		s1[i]++;
	}
	cout << s1 << endl;

	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = s1.begin();
	while (it != s1.end())
	{
		*it = 'a';
		++it;
	}

	cout << s1 << endl;

}

void testlist()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	//迭代器
	list<int>::iterator lit = lt.begin();

	while (lit != lt.end())
	{
		cout << *lit << endl;
		lit++;
	}
	cout << endl;
}

void test_string3()
{
	string s1("hello world");
	//string::reverse_iterator rit = s1.rbegin();

	auto rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	//范围for
	for (auto ch : s1)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;

}

void func(const string& s)
{
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_string4()
{
	string s1("hello world");
	func(s1);

	string s2(s1);
	cout << s2 << endl;

	string s3(s1, 6, 5);
	cout << s3 << endl;

	string s4(s1, 6, 3);
	cout << s4 << endl;

	string s5(s1, 6, s1.size() - 6);
	cout << s5 << endl;

	string s7(10, 'a');
	cout << s7 << endl;

	string s8(++s1.begin(), --s1.end());
	cout << s8 << endl;

	s8 = s7;
	s8 = "xxx";
	s8 = 'y';

}

void test_string5()
{
	string s1 = "hello world";
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	cout << "---" << endl;
	s1.clear();
	s1 += "张三";
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s1.max_size() << endl;
}

void test_string6()
{
	string s;
	s.reserve(100);//保留100个char空间

	size_t old = s.capacity();
	cout << "初始" << s.capacity() << endl;
	
	for (size_t i = 0;i < 100;i++)
	{
		s.push_back('x');

		if (s.capacity() != old)
		{
			cout << "扩容：" << s.capacity() << endl;
			old = s.capacity();
		}
	}

}

void test_string7()
{
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.resize(9, 'x');//比当前的size大就是插入，比当前的size小就是删除
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

void test_string8()
{
	string s("world");
	s.append(10, 'a');
	cout << s << endl;
	s += 98;
	cout << s << endl;
}

void test_string9()
{
	std::string str("xxxxxxxx");
	std::string base = "hkjhkjhkjlhkljhiu";
	str.assign(base);
	std::cout << str << '\n';

	str.assign(base, 5, 10);
	std::cout << str << '\n';
}

void test_string10()
{
	string str("hello world");
	str.insert(0, 2, 'x');
	str.insert(str.begin(), 's');
	cout << str << endl;

	str.erase(5);
	cout << str << endl;

	string s1("hello world");
	s1.replace(5, 1, "%%20");
	cout << "---" << endl;
	cout << s1 << endl;
	cout << str << endl;
	cout << "---" << endl;
	str.swap(s1);
	cout << s1 << endl;
	cout << str << endl;
	cout << "---" << endl;


}

void test_string11()
{
	string s1("test.cpp.tar.exe");
	size_t i = s1.rfind('.');
	
	string s2 = s1.substr(i);
	cout << s2 << endl;

	string s3("https://legacy.cplusplus.com/");
}

void test_string12()
{
	string s1 = "hello world";
	string::iterator it = s1.begin();
	(*it)++;
	cout << s1 << endl;
}

void test_string13()
{
	string s1("1234");
	s1.insert(1, s1);
	cout << s1 << endl;
}


int main()
{
	//test_string13();
	char str1[] = "hello world";
	char str2[] = "比特";
	u32string str3;

	cout << sizeof(str1) << endl;
	cout << sizeof(str2) << endl;
	cout << sizeof(str3) << endl;
	
	return 0;
}