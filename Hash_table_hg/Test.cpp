#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

//#include "MyUnorderedSet.h"
//#include "MyUnorderedMap.h"

template <class Arg1, class Arg2, class Result>
struct binary_function 
{
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};

template <class T> 
struct equal_to : binary_function <T, T, bool> 
{
    bool operator() (const T& x, const T& y) const 
    { 
        return x == y; 
    }
};

//int main() 
//{
//    // (constructor) 构造函数
//    std::unordered_set<int> mySet;
//
//    // (insert) 插入元素
//    mySet.insert(1);
//    mySet.insert(2);
//    mySet.insert(3);
//
//    // (constructor) 通过范围构造函数
//    int arr[] = { 4, 5, 6 };
//    std::unordered_set<int> rangeSet(arr, arr + 3);
//
//    // (constructor) 通过初始化列表构造函数
//    std::unordered_set<int> initListSet = { 7, 8, 9 };
//
//    // (empty) 测试容器是否为空
//    std::cout << "Is set empty? " << (mySet.empty() ? "Yes" : "No") << std::endl;
//
//    // (size) 返回容器大小
//    std::cout << "Size of set: " << mySet.size() << std::endl;
//
//    // (find) 查找元素
//    auto it = mySet.find(2);
//    if (it != mySet.end()) {
//        std::cout << "Element 2 found in set." << std::endl;
//    }
//
//    // (count) 计算特定键的元素数量
//    int count = mySet.count(3);
//    std::cout << "Number of elements with key 3: " << count << std::endl;
//
//    // (emplace) 构造并插入元素
//    mySet.emplace(4);
//
//    // (erase) 删除元素
//    mySet.erase(1);
//
//    // (clear) 清空容器
//    mySet.clear();
//
//    // (hash_function) 获取哈希函数
//    std::hash<int> hashFunction = mySet.hash_function();
//
//    // (key_eq) 获取键的等价比较谓词
//    auto keyEqual = mySet.key_eq();
//
//    // (get_allocator) 获取分配器
//    auto allocator = mySet.get_allocator();
//
//    // (constructor) 拷贝构造函数
//    std::unordered_set<int> copySet(rangeSet);
//
//    // (operator=) 赋值运算符
//    std::unordered_set<int> assignedSet = initListSet;
//
//    // (emplace_hint) 构造并插入元素带有提示位置
//    auto hint = assignedSet.begin();
//    assignedSet.emplace_hint(hint, 10);
//
//    // (swap) 交换内容
//    mySet.swap(assignedSet);
//
//    // (begin) 返回迭代器指向开头
//    for (auto iter = mySet.begin(); iter != mySet.end(); ++iter) {
//        std::cout << *iter << " ";
//    }
//    std::cout << std::endl;
//
//    // (cbegin) 返回 const 迭代器指向开头
//    for (auto iter = mySet.cbegin(); iter != mySet.cend(); ++iter) {
//        std::cout << *iter << " ";
//    }
//    std::cout << std::endl;
//
//    // (bucket_count) 返回桶的数量
//    std::cout << "Bucket count: " << mySet.bucket_count() << std::endl;
//
//    // (max_bucket_count) 返回最大桶的数量
//    std::cout << "Max bucket count: " << mySet.max_bucket_count() << std::endl;
//
//    // (bucket) 返回元素的桶号
//    std::cout << "Bucket for key 2: " << mySet.bucket(2) << std::endl;
//
//    // (bucket_size) 返回桶中元素的数量
//    std::cout << "Bucket size for key 2: " << mySet.bucket_size(mySet.bucket(2)) << std::endl;
//
//    // (load_factor) 返回当前负载因子
//    std::cout << "Load factor: " << mySet.load_factor() << std::endl;
//
//    // (max_load_factor) 获取或设置最大负载因子
//    std::cout << "Max load factor: " << mySet.max_load_factor() << std::endl;
//    mySet.max_load_factor(0.7);
//
//    // (rehash) 设置桶的数量
//    mySet.rehash(10);
//
//    // (reserve) 请求容器容量变化
//    mySet.reserve(20);
//
//    return 0;
//}


//int main()
//{
//	unordered_set<int> s;
//	s.insert(5);
//	s.insert(2);
//	s.insert(6);
//	s.insert(1);
//	s.insert(4);
//
//	unordered_set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	cout << s.load_factor() << endl;
//	cout << s.max_load_factor() << endl;
//
//	unordered_map<string, string> dict;
//	dict["sort"];
//	dict["sort"] = "排序";
//	dict["string"] = "字符串";
//	dict["abc"] = "xx";
//
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	const size_t N = 100000;
//
//	unordered_set<int> us;
//	set<int> s;
//
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; ++i)
//	{
//		//v.push_back(rand()); // N比较大时，重复值比较多
//		//v.push_back(rand()+i); // 重复值相对少
//		v.push_back(i); // 没有重复，有序
//	}
//
//	// 21:15
//	size_t begin1 = clock();
//	for (auto e : v)
//	{
//		s.insert(e);
//	}
//	size_t end1 = clock();
//	cout << "set insert:" << end1 - begin1 << endl;
//
//	size_t begin2 = clock();
//	for (auto e : v)
//	{
//		us.insert(e);
//	}
//	size_t end2 = clock();
//	cout << "unordered_set insert:" << end2 - begin2 << endl;
//
//
//	size_t begin3 = clock();
//	for (auto e : v)
//	{
//		s.find(e);
//	}
//	size_t end3 = clock();
//	cout << "set find:" << end3 - begin3 << endl;
//
//	size_t begin4 = clock();
//	for (auto e : v)
//	{
//		us.find(e);
//	}
//	size_t end4 = clock();
//	cout << "unordered_set find:" << end4 - begin4 << endl << endl;
//
//	cout <<"插入数据个数："<< s.size() << endl;
//	cout <<"插入数据个数：" << us.size() << endl << endl;
//
//	size_t begin5 = clock();
//	for (auto e : v)
//	{
//		s.erase(e);
//	}
//	size_t end5 = clock();
//	cout << "set erase:" << end5 - begin5 << endl;
//
//	size_t begin6 = clock();
//	for (auto e : v)
//	{
//		us.erase(e);
//	}
//	size_t end6 = clock();
//	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
//	
//	return 0;
//}

#include"MyUnorderedMap.h"
#include"MyUnorderedSet.h"

int main()
{
	//hash_bucket::TestHT1();
	//hash_bucket::TestHT3();

	bit::test_map();
	bit::test_set();


	return 0;
}