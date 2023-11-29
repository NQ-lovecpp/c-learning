//#include "BinarySearchTree.h"
//
//int main()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	BSTree<int> btree;
//	for (auto e : a)
//	{
//		btree.Insert(e);
//	}
//	//btree.InOrder();
//	//cout << endl << btree.Find(-1) << endl;
//
//	btree.InOrder();
//	btree.Erase(10);
//	btree.InOrder();
//
//	return 0;
//}

#include"BinarySearchTree.h"

//int main()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	BSTree<int> bt;
//	for (auto e : a)
//	{
//		bt.InsertR(e);
//	}
//	bt.InOrder();
//
//	bt.EraseR(14);
//	bt.InOrder();
//
//	bt.EraseR(3);
//	bt.InOrder();
//
//	bt.EraseR(8);
//	bt.InOrder();
//
//	for (auto e : a)
//	{
//		bt.EraseR(e);
//		bt.InOrder();
//	}
//
//
//	BSTree<int> copy(bt);
//
//	return 0;
//}

//using namespace key_Value;
//
//int main()
//{
//	BSTree<string, string> dict;
//	dict.Insert("sort", "排序");
//	dict.Insert("left", "左边");
//	dict.Insert("right", "右边");
//	dict.Insert("insert", "插入");
//	dict.Insert("key", "关键字");
//
//	//string str;
//	//while (cin >> str)
//	//{
//	//	BSTreeNode<string, string>* ret = dict.Find(str);
//	//	if (ret)
//	//	{
//	//		cout << ret->_value << endl;
//	//	}
//	//	else
//	//	{
//	//		cout << "无此单词" << endl;
//	//	}
//	//}
//
//	dict.InOrder();
//	return 0;
//}

using namespace key;
int main() 
{
    key::BSTree<int> bst; // 声明一个二叉排序树对象

    // 第一个测试用例
    cout << "测试用例 1：" << endl;
    int test_case1[] = { 8, 10, 5, 6, 3, 13 };
    int test_case1_size = sizeof(test_case1) / sizeof(test_case1[0]);

    // 插入测试用例1数据
    for (int i = 0; i < test_case1_size; ++i) {
        bst.Insert(test_case1[i]);
    }

    // 查找测试
    int find_key = 6;
    if (bst.FindR(find_key)) {
        cout << "关键字 " << find_key << " 在树中找到。" << endl;
    }
    else {
        cout << "关键字 " << find_key << " 在树中未找到。" << endl;
    }

    // 中序遍历测试
    cout << "中序遍历结果：";
    bst.InOrder();

    // 删除测试
    int delete_key = 5;
    if (bst.EraseR(delete_key)) {
        cout << "关键字 " << delete_key << " 成功删除。" << endl;
    }
    else {
        cout << "关键字 " << delete_key << " 在树中未找到。删除失败。" << endl;
    }

    // 中序遍历测试
    cout << "删除后的中序遍历结果：";
    bst.InOrder();

    // 第二个测试用例
    cout << "\n测试用例 2：" << endl;
    int test_case2[] = { 15, 20, 10, 25, 5 };
    int test_case2_size = sizeof(test_case2) / sizeof(test_case2[0]);

    // 插入测试用例2数据
    for (int i = 0; i < test_case2_size; ++i) {
        bst.Insert(test_case2[i]);
    }

    // 查找测试
    int find_key2 = 20;
    if (bst.FindR(find_key2)) {
        cout << "关键字 " << find_key2 << " 在树中找到。" << endl;
    }
    else {
        cout << "关键字 " << find_key2 << " 在树中未找到。" << endl;
    }

    // 中序遍历测试
    cout << "测试用例 2 的中序遍历结果：";
    bst.InOrder();

    return 0;
}