namespace chen
{
	template<class T>
	class vector
	{
	public:

		// Vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish + 1;
		}
		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish + 1;
		}

		// capacity
		size_t size()
		{
			_finish - _start + 1;
		}

		size_t capacity() const
		{
			_endOfStorage - _start + 1;
		}

		void reserve(size_t n)
		{
			if (n > _capacity())
			{
				T* tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * sz);
				}
			}
			_start = tmp;
			_finish = _start + sz - 1;
			_endOfStorage = _start + n;
		}

		void resize(size_t n, const T& value = T())// 这里的“=”是初始化常量引用
		{
			if (n <= capacity())
			{
				_finish = _start + n - 1;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = value;
					// 调用赋值运算符重载，因为_finish所指向的对象是new出来的，
					//new已经调用了构造函数，可以说finish所指向的对象已经被定义，
					//对于已经定义的对象，当然=号调用的是赋值运算符重载
					++_finish;
				}
			}
		}

		// access
		T& operator[](size_t pos);
		const T& operator[](size_t pos)const;

		// modify
		void push_back(const T& x);

		void pop_back();

		void swap(vector<T>& v);

		iterator insert(iterator pos, const T& x);

		iterator erase(Iterator pos);

	private:
		iterator _start;  // 指向数据块的开始
		iterator _finish; // 指最后一个有效数据
		iterator _endOfStorage; // 指向最后一块空间
	};
}