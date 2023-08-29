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

		// construct and destroy

		vector()
		{}

		vector(size_t n, const T& value = T())
		{
			reserve(n);
			for (size_t i = 0;i < n;i++)
			{
				push_back(value);
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last);
		{
			while (first != lase)
			{
				push_back(*first);
				++first;
			}
		}

		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		vector<T>& operator= (vector<T> v)
		{
			swap(tmp);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish_ = _endOfStorage = nullptr;
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
					//new已经调用了构造函数，可以说finish所指向的对象已经完成初始化，
					//对于已经定义的对象，当然=号调用的是赋值运算符重载
					++_finish;
				}
			}
		}

		// access
		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < size());

			return _start[pos];
		}

		// modify
		void push_back(const T& x)
		{
			insert(end(), x);
		}


		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _endOfStorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;
		}

		iterator erase(Iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;

			return pos;
		}

	private:
		iterator _start;  // 指向数据块的开始
		iterator _finish; // 指最后一个有效数据
		iterator _endOfStorage; // 指向最后一块空间
	};
}