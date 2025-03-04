

namespace key
{
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

	template<class K>
	class BSTree
	{
		typedef BTreeNode<K> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key > key)
					cur = cur->_left;
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (cur->_key > key)
					cur = cur->_left;
				else if (cur->_key < key)
					cur = cur->_right;
				else
					return false;
			}
			cur = new Node(key);
			if (parent->_key > key)
				parent->_left = cur;
			else
				parent->_right = cur;
			return true;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
								parent->_left = cur->_right;
							else
								parent->_right = cur->_right;
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
								parent->_left = cur->_left;
							else
								parent->_right = cur->_left;
						}
						delete cur;
					}
					else
					{
						Node* rightMin = cur->_right;
						Node* rightMinParent = cur;
						while (rightMin->_left)
						{
							rightMinParent = rightMin;
							rightMin = rightMin->_left;
						}
						cur->_key = rightMin->_key;
						if (rightMinParent->_left == rightMin)
							rightMinParent->_left = rightMin->_right;
						else
							rightMinParent->_right = rightMin->_right;
						delete rightMin;
					}
					return true;
				}
			}
			return false;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

	private:
		Node* _root;
	};
}

namespace tzj
{
	//Key/vuale Ä£ÐÍ
	template<class K, class V>
	struct BTreeNode
	{
		BTreeNode<K, V>* _left;
		BTreeNode<K, V>* _right;

		K _key;
		V _value;

		BTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K, class V>
	class BSTree
	{
		typedef BTreeNode<K, V> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key > key)
					cur = cur->_left;
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (cur->_key > key)
					cur = cur->_left;
				else if (cur->_key < key)
					cur = cur->_right;
				else
					return false;
			}
			cur = new Node(key,value);
			if (parent->_key > key)
				parent->_left = cur;
			else
				parent->_right = cur;
			return true;
		}

		bool Erase(const K& key, const V& value)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
								parent->_left = cur->_right;
							else
								parent->_right = cur->_right;
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
								parent->_left = cur->_left;
							else
								parent->_right = cur->_left;
						}
						delete cur;
					}
					else
					{
						Node* rightMin = cur->_right;
						Node* rightMinParent = cur;
						while (rightMin->_left)
						{
							rightMinParent = rightMin;
							rightMin = rightMin->_left;
						}
						cur->_key = rightMin->_key;
						if (rightMinParent->_left == rightMin)
							rightMinParent->_left = rightMin->_right;
						if (rightMinParent == cur)
							rightMinParent->_right = rightMin->_right;
						delete rightMin;
					}
					return true;
				}
			}
			return false;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}



	private:
		Node* _root;
	};


}
