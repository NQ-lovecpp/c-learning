#pragma once
#include <vector>

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// 原始写法
struct HashFuncString
{
	size_t operator()(const string& key)
	{
		// BKDR方法
		size_t hash = 0;
		for (auto ch : key)
		{
			hash *= 31;
			hash += ch;
		}
		return hash;
	}
};

// 模板特化写法
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		// BKDR方法
		size_t hash = 0;
		for (auto ch : key)
		{
			hash *= 31;
			hash += ch;
		}
		return hash;
	}
};


// 闭散列
namespace chen
{
	enum Status
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K,class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _s;       //状态
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_tables.resize(10);
		}

		bool Insert(const std::pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			// 负载因子_n/size == 0.7 就扩容
			if (_n * 10 / _tables.size() == 7)
			{
				size_t newSize = _tables.size() * 2;
				HashTable<K, V, Hash> newHT;
				newHT._tables.resize(newSize);
				// 遍历旧表
				for (size_t i = 0;i < _tables.size();i++)
				{
					if (_tables[i]._s == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
				}

				_tables.swap(newHT._tables);
			}

			Hash hf;
			// 线性探测
			size_t hashi = hf(kv.first) % _tables.size();
			while (_tables[hashi]._s == EXIST)
			{
				hashi++;
				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._s = EXIST;
			++_n;
			return true;
		}

		HashData<K,V>* Find(const K& key)
		{
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			while (_tables[hashi]._s != EMPTY)
			{
				if (_tables[hashi]._s==EXIST
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}

				hashi++;
				hashi %= _tables.size();
			}

			return NULL;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_s = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}

		void Print()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._s == EXIST)
				{
					cout << "[" << i << "]->" << _tables[i]._kv.first 
						 << ":" << _tables[i]._kv.second << endl;
				}
				else if (_tables[i]._s == EMPTY)
				{
					printf("[%ud]->\n", i);
				}
				else
				{
					printf("[%ud]->D\n", i);
				}
			}

			cout << endl;
		}

	private:
		std::vector<HashData<K,V>> _tables;
		size_t _n = 0;    // 存储的关键字个数
	};

	void TestHT1()
	{
		chen::HashTable<int, int> ht;
		int a[] = { 42,45,345,4,37,45,23 };
		for (auto e : a)
		{
			ht.Insert(std::make_pair(e, e));
		}

		ht.Print();
		ht.Insert(std::make_pair(42, 42));
		ht.Print();

		ht.Erase(42);
		ht.Erase(45);

		ht.Print();
	}

	void TestHT2()
	{
		string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		//HashTable<string, int, HashFuncString> ht;
		HashTable<string, int, HashFunc<string>> ht;
		for (auto& e : arr)
		{
			//auto ret = ht.Find(e);
			HashData<string, int>* ret = ht.Find(e);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(e, 1));
			}
		}

		ht.Print();

		ht.Insert(make_pair("apple", 1));
		ht.Insert(make_pair("sort", 1));

		ht.Insert(make_pair("abc", 1));
		ht.Insert(make_pair("acb", 1));
		ht.Insert(make_pair("aad", 1));

		ht.Print();
	}
}

// 哈希桶
namespace hash_bucket
{
	template<class T>
	class HashNode
	{
		HashNode* _next;
		T _data;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	// 前置声明
	template<class K,class T,class KeyOfT,class Hash>
	class HashTable;

	template<class K,class T,class Ref,class Ptr,class KeyOfT,class Hash>
	struct __HTIterator
	{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;

	public:
		__HTIterator(Node* node, HashTable<K, T, KeyOfT, Hash>* pht, size_t hashi)
			:_node(node)
			, _pht(pht)
			, _hashi(hashi)
		{}

		__HTIterator(Node* node, const HashTable<K, T, KeyOfT, Hash>* pht, size_t hashi)
			:_node(node)
			, _pht(pht)
			, _hashi(hashi)
		{}

		Self& operator++()
		{
			if (_node->_next) 
			{
				// 当前桶还有节点，就走到下一个节点
				_node = _node->_next;
			}
			else
			{
				// 当前桶已经走完了，从下一个桶开始找
				++_hashi;
				while (_hashi < _pht->_tables.size())
				{
					if (_pht->_tables[_hashi])
					{
						_node = _pht->_tables[_hashi];
						break;
					}

					++_hashi;
				}

				if (_hashi == _pht->_tables.size())
				{
					_node = nullptr;
				}
			}

			return *this;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

	public:
		Node* _node;
		const HashTable<K, T, KeyOfT, Hash>* _pht;
		size_t _hashi;
	};
	

	// unordered_set -> Hashtable<K, K>
	// unordered_map -> Hashtable<K, pair<K, V>>
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		typedef HashNode<T> Node;

		template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
		friend struct __HTIterator;

	public:
		typedef __HTIterator<K, T, T&, T*, KeyOfT, Hash> iterator;
		typedef __HTIterator<K, T, const T&, const T*, KeyOfT, Hash> const_iterator;

		iterator begin()
		{
			for (size_t i = 0;i < _tables.size();i++)
			{
				if (_tables[i])
				{
					return iterator(_tables[i], this, i);
				}
			}

			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this, -1);
		}

		const_iterator begin() const
		{
			for (size_t i = 0;i < _tables.size();i++)
			{
				if (_tables[i])
				{
					return const_iterator(_tables[i], this, i);
				}
			}
			
			return end();
		}

		const_iterator end()const
		{
			return const_iterator(nullptr, this, -1);
		}

		HashTable()
		{
			_tables.resize(10);
		}

		~HashTable()
		{
			for (size_t i = 0;i < _tables.size();i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		std::pair<iterator,bool> Insert(const T& data)
		{
			Hash hf;
			KeyOfT kot;

			iterator it = Find(kot(data));
			if (it != end())
			{
				return make_pair(it, false);
			}

			if (_n == _tables.size())
			{
				vector<Node*> newTables;
				newTables.resize(_tables.size() * 2, nullptr);
				// 遍历旧表
				for (size_t i = 0;i < _tables.size();i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						// 挪动到映射的新表
						size_t hashi = hf(kot(cur->_data)) % newTables.size();
						cur->_next = newTables[i];
						newTables[hashi] = cur;

						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newTables);
			}
			
			size_t hashi = hf(kot(data)) % _tables.size();
			Node* newnode = new Node(data);

			// 头插
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return make_pair(iterator(newnode, this, hashi), true);
		}

		iterator Find(const K& key)
		{
			Hash hf;
			KeyOfT kot;

			size_t hashi = hf(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this, hashi);
				}

				cur = cur->_next;
			}
			
			return end();
		}

		bool Erase(const K& key)
		{
			Hash hf;
			KeyOfT kot;

			size_t hashi = hf(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;

					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}

		void Some()
		{
			size_t bucketSize = 0;
			size_t maxBucketLen = 0;
			size_t sum = 0;
			double averageBucketLen = 0;

			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				if (cur)
				{
					++bucketSize;
				}

				size_t bucketLen = 0;
				while (cur)
				{
					++bucketLen;
					cur = cur->_next;
				}

				sum += bucketLen;

				if (bucketLen > maxBucketLen)
				{
					maxBucketLen = bucketLen;
				}
			}

			averageBucketLen = (double)sum / (double)bucketSize;

			printf("all bucketSize:%d\n", _tables.size());
			printf("bucketSize:%d\n", bucketSize);
			printf("maxBucketLen:%d\n", maxBucketLen);
			printf("averageBucketLen:%lf\n\n", averageBucketLen);
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};



	//template<class K, class V>
	//class HashTable
	//{
	//private:
	//	union bucket
	//	{
	//		std::list<pair<K, V>> _lt;
	//		std::set<pair<K, V>> _rbtree;
	//	};
	//	vector<bucket> _tables;
	//	size_t _n;
	//};
}