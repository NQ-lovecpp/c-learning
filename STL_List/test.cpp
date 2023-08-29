#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include <list>
#include <vector>


////////////////////////////////////////////////////////////
// list的构造
void TestList1()
{
    list<int> l1;                        // 构造空的l1
    list<int> l2(4, 100);                // l2中放4个值为100的元素
    list<int> l3(l2.begin(), l2.end());  // 用l2的[begin(), end()）左闭右开的区间构造l3
    list<int> l4(l3);                    // 用l3拷贝构造l4

    // 以数组为迭代器区间构造l5
    int array[] = { 16,2,77,29 };
    list<int> l5(array, array + sizeof(array) / sizeof(int));

    // 列表格式初始化C++11
    list<int> l6{ 1, 2, 3, 4, 5 };

    // 用迭代器方式打印l5中的元素
    list<int>::iterator it = l5.begin();
    while (it != l5.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    // C++11范围for的方式遍历
    for (auto& e : l5)
        cout << e << " ";

    cout << endl;
}

////////////////////////////////////////////////////////////
// list迭代器的使用
// 注意：遍历链表只能用迭代器和范围for
void PrintList(const list<int>& l)
{
    // 注意这里调用的是list的 begin() const，返回list的const_iterator对象
    for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << " ";
        // *it = 10; 编译不通过
    }

    cout << endl;
}

void TestList2()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    list<int> l(array, array + sizeof(array) / sizeof(array[0]));
    // 使用正向迭代器正向list中的元素
    // list<int>::iterator it = l.begin();   // C++98中语法
    auto it = l.begin();                     // C++11之后推荐写法
    while (it != l.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    // 使用反向迭代器逆向打印list中的元素
    // list<int>::reverse_iterator rit = l.rbegin();
    auto rit = l.rbegin();
    while (rit != l.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}

////////////////////////////////////////////////////////////
// list插入和删除
// push_back/pop_back/push_front/pop_front
void TestList3()
{
    int array[] = { 1,2,3,4,5,6 };
    list<int> L(array, array + sizeof(array) / sizeof(array[0]));

    // 在list的尾部插入4，头部插入0
    L.push_back(4);
    L.push_front(0);
    PrintList(L);

    // 删除list尾部节点和头部节点
    L.pop_back();
    L.pop_front();
    PrintList(L);
}

// insert /erase 
void TestList4()
{
    int array1[] = { 1, 2, 3 };
    list<int> L(array1, array1 + sizeof(array1) / sizeof(array1[0]));

    // 获取链表中第二个节点
    auto pos = ++L.begin();
    cout << *pos << endl;

    // 在pos前插入值为4的元素
    L.insert(pos, 4);
    PrintList(L);

    // 在pos前插入5个值为5的元素
    L.insert(pos, 5, 5);
    PrintList(L);

    // 在pos前插入[v.begin(), v.end)区间中的元素
    vector<int> v{ 7, 8, 9 };
    L.insert(pos, v.begin(), v.end());
    PrintList(L);

    // 删除pos位置上的元素
    L.erase(pos);
    PrintList(L);

    // 删除list中[begin, end)区间中的元素，即删除list中的所有元素
    L.erase(L.begin(), L.end());
    PrintList(L);
}

// resize/swap/clear
void TestList5()
{
    // 用数组来构造list
    int array1[] = { 1, 2, 3 };
    list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
    PrintList(l1);

    // 交换l1和l2中的元素
    list<int> l2;
    l1.swap(l2);
    PrintList(l1);
    PrintList(l2);

    // 将l2中的元素清空
    l2.clear();
    cout << l2.size() << endl;
}

int main()
{
    TestList4();
    return 0;
}