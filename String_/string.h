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

		//Ö»¶Áµü´úÆ÷
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

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			size_t end = _size;
			while (end >= pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}

			_str[pos] = ch;
			end--;
		}
		void insert(size_t pos, const char* str)
		{}

		void erase(size_t pos, size_t len = npos)
		{}

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
}