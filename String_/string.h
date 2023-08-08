#pragma once
#include <cassert>
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//只读迭代器
		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str+_size;
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

		//string(const string& s)
		//{
		//	_str = new char[s._size];
		//}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

		////陈旧的写法
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, s._str);

		//		delete[] _str;
		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}
		//	return *this;
		//}

		////现代写法
		//string& operator=(const string& s)
		//{

		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		this->swap(tmp);
		//	}
		//	return *this;
		//}


		//极致写法
		string& operator=(string tmp)
		{
			swap(tmp);
			return *this;
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

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return *(_str + pos);
		}
 
		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		const char* c_str() const
		{
			return _str;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];//多出来的一个空间是留给'\0'的
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				while (_size < n)
				{
					_str[_size] = ch;
					++_size;
				}

				_str[_size] = '\0';
			}
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos;i < _size;i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* sub, size_t pos = 0)
		{
			const char* p = strstr(_str, sub);
			if (p)
			{
				return p - _str;
			}
			else
			{
				return npos;
			}
		}

		string substr(size_t pos, size_t len = npos)
		{
			string s;
			size_t end = pos + len;
			if (len == npos || pos + len >= _size)//有多少取多少
			{
				len = _size - len;
			}
			s.reserve(len);
			for (size_t i = pos;i < _size;i++)
			{
				s += _str[i];
			}
			return s;
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, char c)
		{
			assert(pos <= _size);
			if (_size >= _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = c;
			_size++;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size+len);
			}
			//移动数据
			for (size_t i = _size;i >= pos;i--)
			{
				_str[len + i] = _str[i];
			}
			//插入字符串str
			while (*str != '\0')
			{
				_str[pos++] = *(str++);
			}
			
			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (pos==npos || pos + len >= _size)//pos位置之后全为0
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator<(const string& s) const
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator<=(const string& s) const
		{
			return *this < s || *this == s;
		}

		bool operator>=(const string& s) const
		{
			return *this > s || *this == s;
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos = -1;
	};

	ostream& operator<<(ostream& out, const string& s)
	{
		for (char ch : s)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch;
		ch = in.get();
		s.reserve(128);

		while (ch != ' ' && ch != '\0')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}


	void test_string1()
	{
		string s1("hello world!");
		string s2("hello bit!");
		cout << s1 << s2 << endl;
		string::iterator it = s2.begin();
		for (;it != s2.end();it++)
		{
			cout << *it << ' ';
		}
		cout << endl;
		s1.push_back('x');
		s1.push_back('x');
		s1.push_back('x');
		cout << s1 << endl;
		s1.append("abcdefg");
		cout << s1 << endl;
		s1.insert(1, 'x');
		cout << s1 << endl;
	}

	void test_string2()
	{
		string s1 = "world";
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;
		s1.insert(0, "hello ");
		cout << s1 << endl;
		cout << s1.capacity() << endl;
		cout << s1.size() << endl;
	}

	void test_string3()
	{
		string s1 = "helloworld";
		s1.erase(5, 10);
		cout << s1 << endl;
		s1.erase(2);
		cout << s1 << endl;
		s1.resize(50);
		cout << s1 << endl;

	}

	//void test_string4()
	//{
	//	string s1("hello world");
	//	cin>>
	//}



}