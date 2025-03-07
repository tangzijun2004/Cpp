#pragma once
#include<iostream>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;//平衡因子
	pair<K,V> _kv;

	AVLTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent == 0)
			{
				//说明parent所在的子树的高度不变，更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//说明parent所在的子树的高度变了，继续往上跟新
				cur = parent;
				parent = cur->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent所在的子树出现不平衡了，需要旋转处理

				//左单旋
				if (parent->_bf == 2)
				{
					if(cur->_bf == 1)
						RoateL(parent);
					else if (cur->_bf == -1)
					{
						RoateRL(parent);
					}

				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
						RoateR(parent);
					else if (cur->_bf == 1)
					{
						RoateLR(parent);
					}

				}
				break;
			}
		}
		return true;
	}

	void RoateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = subR;

		subR->_left = parent;
		Node* ppNode = parent->_parent;//给parent的父亲保存下来，为subR的parent
		parent->_parent = subR;

		//给subR的parent赋值
		//1、原来parent是这棵树的根，现在是subR是跟根
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		//2、parent不是这棵树的根
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}
		parent->_bf = subR->_bf = 0;
	}

	void RoateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		//更新subL的节点的父亲
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;

			subL->_parent = ppNode;
		}
		subL->_bf = parent->_bf = 0;
	}

	void RoateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RoateR(parent->_right);
		RoateL(parent);

		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if(bf == 0)
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
	}

	void RoateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RoateL(parent->_left);
		RoateR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else if(bf == 0)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1:rightHeight + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		return abs(leftHeight - rightHeight) < 2 && _IsBalance(root->_left) && _IsBalance(root->_right);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}
private:
	Node* _root = nullptr;
};

void TestAVLTree()
{
	//int a[] = { 16,3,7,11,9,26,18,14,15};
	int a[] = {4,2,6,1,3,5,15,7,16,14};
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.InOrder();
	cout << t.IsBalance() << endl;
	
}