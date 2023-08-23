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
			return _end + 1;
		}
		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _end + 1;
		}

		// capacity
		size_t size()
		{

		}
		size_t capacity() const;
		void reserve(size_t n);
		void resize(size_t n, const T& value = T());

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