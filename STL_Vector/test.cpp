#include <iostream>
#include <vector>
#include <string>

using namespace std;

void test_vector1()
{
	vector<int> v1;
	vector<int> v2(10, 0);
	vector<int> v3(v2.begin(), v2.end());

	string str("hello world");
	vector<int> v4(str.begin(), str.end());

	vector<int> v5(v4);
	

	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;

	vector<int>::const_reverse_iterator it = v4.rbegin();
	while (it != v4.rend())
	{
		cout << (char)(*it) << " ";
		it++;
	}
	cout << endl;
	
	for (auto& e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector2()
{
	size_t sz;
	vector<int> v;
	v.reserve(100);

	sz = v.capacity();
	for (int i = 0;i < 100;i++)
	{
		v.push_back(1);
		if (v.capacity() != sz)
		{
			cout << v.capacity() << endl;
			sz = v.capacity();
		}
	}
}

void test_vector3()
{
	vector<int> v;
	cout << v.max_size() << endl;
}

void test_vector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.insert(v.begin(), 0);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	auto it = find(v.begin(), v.end(), 3);
	v.insert(it, 999);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "---" << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.clear();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


int main()
{
	test_vector4();
	return 0;
}