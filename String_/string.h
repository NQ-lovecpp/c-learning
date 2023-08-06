#pragma once

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//string()
		//	:_str(new char[1])
		//	, _size(0)
		//	,_capacity(0)
		//{
		//	_str[0] = '\0';
		//}

		string(const char* str="")
			:_size(strlen(str))
			,_capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return *(_str+pos);
		}

		size_t size()
		{
			return _size;
		}

		size_t capacity()
		{
			return _capacity;
		}

		const char* sc_str() const
		{
			return _str;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
		}

		void append(char ch)
		{
			if (_size == _capacity)
			{

			}
		}

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			size_t end = _size;
			while (end >= pos)
			{

			}
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos = -1;
	};

	void test_string1()
	{
		string s1("hello world");
		cout  << endl;
	}
}