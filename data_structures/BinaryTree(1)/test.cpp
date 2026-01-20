#include <iostream>
#include <queue>
#include <string>

using namespace std;

// 二叉树节点
template<class K>
struct BTreeNode
{
    BTreeNode<K>* _left;
    BTreeNode<K>* _right;
    K _key;

    BTreeNode(const K& key)
        :_left(nullptr)
        , _right(nullptr)
        , _key(key)
    {}
};

// 二叉树
template<class K>
class BTree
{
    typedef BTreeNode<K> Node;
public:
    BTree() = default;

    // 构造函数，根据层序遍历的输入格式创建二叉树
    BTree(const string& input)
    {
        _root = CreateTree(input);
    }

    // 计算二叉树的深度
    int GetDepth()
    {
        return _GetDepth(_root);
    }

    // 先序遍历
    void PreOrder()
    {
        _PreOrder(_root);
        cout << endl;
    }   
    
    // 中序遍历
    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }

    // 后序遍历
    void PostOrder()
    {
        _PostOrder(_root);
        cout << endl;
    }

    // 输出树状简图
    void PrintTree()
    {
        _PrintTree(_root, "");
    }

private:
    Node* CreateTree(const string& levelOrder) 
    {
        if (levelOrder.empty()) 
            return nullptr;

        queue<Node*> queue;
        Node* root = new Node(levelOrder[0]);
        queue.push(root);

        size_t i = 1;
        while (!queue.empty() && i < levelOrder.size()) 
        {
            Node* current = queue.front();
            queue.pop();

            // 左子节点
            if (i < levelOrder.size()) 
            {
                if (levelOrder[i] != '#')
                {
                    current->_left = new Node(levelOrder[i]);
                    queue.push(current->_left);
                }
                else
                {
                    current->_left = nullptr;
                }

            }
            ++i;

            // 右子节点
            if (i < levelOrder.size()) 
            {
                if (levelOrder[i] != '#')
                {
                    current->_right = new Node(levelOrder[i]);
                    queue.push(current->_right);
                }
                else
                {
                    current->_right = nullptr;
                }

            }
            ++i;
        }

        return root;
    }

    int _GetDepth(Node* root)
    {
        if (root == nullptr)
            return 0;

        int leftDepth = _GetDepth(root->_left);
        int rightDepth = _GetDepth(root->_right);

        return max(leftDepth, rightDepth) + 1;
    }

    void _PreOrder(Node* root)
    {
        if (root == nullptr)
            return;

        cout << root->_key << " ";
        _PreOrder(root->_left);
        _PreOrder(root->_right);
    }

    void _InOrder(Node* root)
    {
        if (root == nullptr)
            return;

        _InOrder(root->_left);
        cout << root->_key << " ";
        _InOrder(root->_right);
    }

    void _PostOrder(Node* root)
    {
        if (root == nullptr)
            return;

        _PostOrder(root->_left);
        _PostOrder(root->_right);
        cout << root->_key << " ";
    }

    // 输出树状简图的辅助函数
    void _PrintTree(Node* root, const string& prefix)
    {
        if (root == nullptr)
            return;

        cout << prefix;
        cout << "|--" << root->_key << endl;

        _PrintTree(root->_left, prefix + "|   ");
        _PrintTree(root->_right, prefix + "|   ");
    }

private:
    Node* _root = nullptr;
};

int main()
{
    // 测试用例 1
    string input1 = "AB#C##D##";
    BTree<char> tree1(input1);

    cout << "测试用例 1:" << endl;
    cout << "二叉树的深度：" << tree1.GetDepth() << endl;

    cout << "先序遍历结果：";
    tree1.PreOrder();

    cout << "中序遍历结果：";
    tree1.InOrder();

    cout << "后序遍历结果：";
    tree1.PostOrder();

    cout << "树状简图：" << endl;
    tree1.PrintTree();

    cout << endl;

    // 测试用例 2
    string input2 = "1#2##3##";
    BTree<int> tree2(input2);

    cout << "测试用例 2:" << endl;
    cout << "二叉树的深度：" << tree2.GetDepth() << endl;

    cout << "先序遍历结果：";
    tree2.PreOrder();

    cout << "中序遍历结果：";
    tree2.InOrder();

    cout << "后序遍历结果：";
    tree2.PostOrder();

    cout << "树状简图：" << endl;
    tree2.PrintTree();

    return 0;
}

