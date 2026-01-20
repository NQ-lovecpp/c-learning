#include <cassert>
#include <iostream>

namespace Recite
{
	template<class K,class V>
	struct AVLTreeNode
	{
		AVLTreeNode(const std::pair<K, V>& kv)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _kv(kv)
			, _bf(0)
		{}

		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;

		std::pair<K, V> _kv;
		int _bf;
	};

	template<class K,class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	public:
		bool Insert(const std::pair<K,V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}
			
			Node* cur = _root;
			Node* parent = nullptr;

			// 让parent遍历到插入位置的parent处
			while (cur != nullptr)
			{
				if (cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(kv); //cur现在是插入的新节点指针
			if (parent->_kv.first > kv.first)
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
			else
			{
				parent->_right = cur;
				cur->_parent = parent;
			}


			// 调整
			// 两种迭代 三种大分流

			while (parent)
			{
				if (cur == parent->_left)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}

				if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//插入位置在parent右树的右树（右右）
					if (parent->_bf == 2 && cur->_bf == 1)
					{
						RotateL(parent);
					}

					// 左左
					else if (parent->_bf == -2 && cur->_bf == -1)
					{
						RotateR(parent);
					}

					// 右左
					else if (parent->_bf == 2 && cur->_bf == -1)
					{
						RotateRL(parent);
					}

					// 左右
					else if (parent->_bf == -2 && cur->_bf == 1)
					{
						RotateLR(parent);
					}

					break;
				}

			}

			return true;
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			subR->_left = parent;

			Node* parentParent = parent->_parent;

			parent->_parent = subR;
			if (subRL)
				subRL->_parent = parent;

			if (_root == parent)
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				if (parentParent->_left == parent)
				{
					parentParent->_left = subR;
				}
				else
				{
					parentParent->_right = subR;
				}

				subR->_parent = parentParent;
			}

			parent->_bf = subR->_bf = 0;
		}

		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			Node* parentParent = parent->_parent;

			subL->_right = parent;
			parent->_parent = subL;

			if (_root == parent)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (parentParent->_left == parent)
				{
					parentParent->_left = subL;
				}
				else
				{
					parentParent->_right = subL;
				}

				subL->_parent = parentParent;
			}

			subL->_bf = parent->_bf = 0;
		}

		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;

			RotateR(parent->_right);
			RotateL(parent);

			if (bf == 0)
			{
				// subRL自己就是新增
				parent->_bf = subR->_bf = subRL->_bf = 0;
			}
			else if (bf == -1)
			{
				// subRL的左子树新增
				parent->_bf = 0;
				subRL->_bf = 0;
				subR->_bf = 1;
			}
			else if (bf == 1)
			{
				// subRL的右子树新增
				parent->_bf = -1;
				subRL->_bf = 0;
				subR->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}

		void RotateLR(Node* parent)
		{
			//...
			RotateL(parent->_left);
			RotateR(parent);
		}

		void Inorder()
		{
			_Inorder(_root);
			std::cout << std::endl;
		}

	private:
		void _Inorder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_Inorder(root->_left);
			std::cout << root->_kv.first << " ";
			_Inorder(root->_right);
		}
		Node* _root = nullptr;
	};
}