#include <unordered_set>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

int main()
{
	unordered_set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(7);
	s.insert(8);

	unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	map<string, string> dict;
	dict.insert(make_pair("sort", "ÅÅĞò"));
	dict["1string"] = "×Ö·û´®";
	dict["abc"] = "xx";

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	return 0;
}