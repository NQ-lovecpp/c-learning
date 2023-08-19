#include <cassert>
#include <cstring>
namespace chen
{
    class string
    {
        // 流插入流提取运算符重载
        // (类中写友元函数声明，定义在类外)
        friend ostream& operator<<(ostream& _cout, const chen::string& s);
        friend istream& operator>>(istream& _cin, chen::string& s);

    public:
        typedef char* iterator;
        typedef char* const_iterator;

    public:
        // 构造函数
        string(const char* str = "")
            :_size(strlen(str))
            , _capacity(_size)
        {
            _str = new char[_size + 1];
            strcpy(_str, str);
        }

        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        // 拷贝构造函数
        string(const string& s)
        {
            string tmp(s._str);
            this->swap(tmp);
        }

        string& operator=(const string& s)
        {
            string tmp(s._str);
            this->swap(tmp);
            return *this;
        }

        // 析构函数
        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        // 迭代器
        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        const_iterator begin() const
        {
            return _str;
        }

        const_iterator end() const
        {
            return _str + _size;
        }

        // 修改
        // 尾插一个字符
        void push_back(char c)
        {
            if (_capacity < _size + 1)
            {
                reserve(_capacity == 0 ? 4 : 2 * _capacity);
            }
            _str[_size] = c;
            _str[++_size] = '\0';
        }

        void append(const char* str)
        {
            size_t len = strlen(str);
            if (_capacity < _size + len)
            {
                reserve(_capacity == 0 ? 4 : 2 * _capacity + len);
            }

            for (size_t i = 0;i <= len;i++)
            {
                _str[_size] = str[i];
                _size++;
            }
        }

        string& operator+=(char c)
        {
            push_back(c);
            return *this;
        }

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

        const char* c_str()const
        {
            return _str;
        }


        // 容量相关
        size_t size() const
        {
            return _size;
        }
        size_t capacity() const
        {
            return _capacity;
        }

        bool empty() const
        {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0')
        {
            assert(n >= 0);
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
                    _str[_size++] = c;
                }
                _str[_size] = '\0';
            }
        }

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;

                _capacity = n;
            }
        }


        // 下标访问
        char& operator[](size_t index)
        {
            return *(_str + index);
        }
        const char& operator[](size_t index) const
        {
            return *(_str + index);
        }

        // 关系运算符重载
        bool operator<(const string& s) const
        {
            return strcmp(_str, s._str) < 0;
        }

        bool operator==(const string& s) const
        {
            return strcmp(_str, s._str) == 0;
        }

        bool operator<=(const string& s) const
        {
            return *this < s || *this == s;
        }

        bool operator>(const string& s) const
        {
            return !(*this <= s);
        }

        bool operator>=(const string& s) const
        {
            return !(*this < s);
        }

        bool operator!=(const string& s) const
        {
            return !(*this == s);
        }



        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const
        {
            return strchr(_str + pos, c) - _str;
        }

        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const
        {
            char* p = strstr(_str + pos, s);
            if (p)
            {
                return p - _str;
            }
            else
            {
                return npos;
            }
        }

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c)
        {
            assert(pos <= _size);
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : _capacity + 4);
            }
            
            size_t end = _size + 1;
            while (end > pos)
            {
                _str[end] = _str[end - 1];
                end--;
            }
            _str[pos] = c;
            _size++;
            return *this;
        }
        string& insert(size_t pos, const char* str)
        {
            assert(pos <= _size);
            size_t len = strlen(str);
            if (_size + len > _capacity)
            {
                reserve(_size + len);
            }

            size_t end = _size + len;
            while (end >= pos + len)
            {
                _str[end] = _str[end - len];
                end--;
            }
            memcpy(_str + pos, str, len);
            _size += len;
            return *this;
        }

        // 删除pos位置上的元素，并返回该元素的下一个位置
        string& erase(size_t pos, size_t len);

    private:
        char* _str;
        size_t _size;
        size_t _capacity;

        const static size_t npos = -1;
    };

    ostream& operator<<(ostream& _cout, const string& s)
    {
        string::iterator it = s.begin();
        for (;it != s.end();it++)
        {
            _cout << *it;
        }
        return _cout;
    }

    istream& operator>>(istream& _cin, string& s)
    {
        s.clear();

        char buff[129];
        size_t i = 0;

        char ch = _cin.get();
        while (ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;
            if (i == 128)
            {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }

            ch = _cin.get();
        }

        if (i != 0)
        {
            buff[i] = '\0';
            s += buff;
        }

        return _cin;
    }


    void test_string100()
    {
        string s1("12345");
        s1.push_back('a');
        s1.push_back('a');
        s1.push_back('a');
        s1.push_back('a');
        s1.append("hello world");
        cout << s1 << endl;
        s1.resize(5);
        cout << s1 << endl;
        s1.resize(10, 'x');
        cout << s1 << endl;
    }

    void test_string101()
    {
        string s("123456789");
        cout << s.find("123") << endl;
        s.insert(3, "@@%%%%%%%%%%%%%%%%%%");
        cout << s << endl;
    }
}