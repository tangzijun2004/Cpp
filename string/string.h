#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
//namespace tzj
//{
//	class string
//	{
//	public:
//		//string()
//		//	:_str(new char[1])
//		//{
//		//	_str[0] = '\0';
//		//}
//		string(const char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		//编译器默认生成浅拷贝，这里需要自己构建深拷贝
//		string(const string& str)
//			:_str(new char[strlen(str._str)+1])
//		{
//			strcpy(_str, str._str);
//		}
//		size_t size()
//		{
//			return strlen(_str);
//		}
//
//		const char* c_str()
//		{
//			return _str;
//		}
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//		//s1.operator=(s3);
//		//s1 = s3
//		//s1 = s1
//		string& operator =(const string& str)
//		{
//			if (this != &str)
//			{
//				char* tmp = new char[strlen(str._str) + 1];
//				strcpy(tmp, str._str);
//				delete[] _str;
//				_str = tmp;
//			}
//			return *this;
//		}
//		void test_string1()
//		{
//			string s1("hello");
//			string s2;
//			for (size_t i = 0; i < s1.size(); ++i)
//			{
//				cout << s1[i] << " ";
//			}
//			cout << endl;
//
//			for (size_t i = 0; i < s2.size(); ++i)
//			{
//				cout << s2[i] << " ";
//			}
//			cout << endl;
//		}
//		void test_string2()
//		{
//			string s1("hello");
//			string s2(s1);
//			string s3("world");
//			//s1.operator=(s3);
//			s1 = s3;
//			cout << s1.c_str() << endl;
//			cout << s2.c_str() << endl;
//		}
//	private:
//		char* _str;
//	};
//}

namespace tzj
{
    //实现一个支持增删查改的string
    class string
    {
    public:
        friend ostream& operator<< (ostream& out, const string& s);
        friend istream& operator>>(istream& in, string& s);
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

        const_iterator begin() const
        {
            return _str;
        }

        const_iterator end() const 
        {
            return _str + _size;
        }

        string(const char* str = "")
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        //s1(s2)
        string(const string& str)
        {
            _size = str._size;
            _capacity = str._capacity;
            _str = new char[_capacity + 1];
            strcpy(_str, str._str);
        }

        //s1 = "123" s2 = s1
        //methon1 
        //string& operator= (const string& str)
        //{
        //    if (this != &str)
        //    {
        //        _size = str._size;
        //        _capacity = str._capacity;
        //        char* tmp = new char[_capacity + 1];
        //        strcpy(tmp, str._str);
        //        delete[] _str;
        //        _str = tmp;
        //    }
        //    return *this;
        //}

        void swap(string& str)
        {
            std::swap(_str, str._str);
            std::swap(_size, str._size);
            std::swap(_capacity, str._capacity);
        }

        string& operator= (string str)
        {
            swap(str);
            return *this;
        }

        char& operator[](size_t i)
        {
            assert(i >= 0 && i < _size);
            return _str[i];
        }

        const char& operator[](size_t i) const
        {
            assert(i >= 0 && i < _size);
            return _str[i];
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
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }

        void resize(size_t n, char ch = '\0')
        {
            if (n < _size)
            {
                _str[n] = '\0';
                _size = n;
            }
            else
            {
                if (n > _capacity)
                {
                    reserve(n);
                }
                for (size_t i = _size; i < n; ++i)
                {
                    _str[i] = ch;
                }
                _size = n;
                _str[_size] = '\0';
            }
        }

        void push_back(char ch)
        {
            if (_size == _capacity)
            {
                size_t newcapacity = _capacity == 0 ? 16 : _capacity * 2;
                reserve(newcapacity);
            }
            _str[_size] = ch;
            ++_size;
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

        string& insert(size_t pos, const char ch)
        {
            assert(pos >= 0 && pos <= _size);
            if (_size == _capacity)
            {
                int newcapacity = _capacity == 0 ? 16 : 2 * _capacity;
                reserve(newcapacity);
            }
            for (size_t i = _size; i >= (int)pos; --i)
            {
                _str[i+1] = _str[i];
            }
            _str[pos] = ch;
            ++_size;
            return *this;
        }

        string& insert(size_t pos, const char* str)
        {
            assert(pos <= _size);
            int len = strlen(str);
            if (_size + len > _capacity)
            {
                reserve(_size + len);
                _capacity = _size + len;
            }
            for (size_t i = _size; i >= (int)pos; --i)
            {
                _str[i + len] = _str[i];
            }
            strncpy(_str+pos,str,len);
           /* for (int i = pos; i <= pos + len; ++i)
            {
                _str[i] = str[i - pos];
            }*/
            _size += len;
            return *this;
        }

        string& erase(size_t pos, size_t len = npos)
        {
            assert(pos >= 0 && pos < _size);
            if (len > _size - pos)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                size_t i = pos + len;
                while (i <= _size)
                {
                    _str[pos++] = _str[i++];
                }
                _size -= len;
            }
            return *this;
        }

        size_t find(char ch, size_t pos = 0)
        {
            for (size_t i = pos; i < _size; ++i)
            {
                if (_str[i] == ch)
                {
                    return i;
                }
            }
            return npos;
        }

        size_t find(const char* str, size_t pos = 0)
        {
            char* p = strstr(_str, str);
            if (p == nullptr)
            {
                return npos;
            }
            else
            {
                return p - _str;
            }
        }

        string substr(size_t pos, size_t len = npos)
        {
            assert(pos < _size);
            size_t n = len;
            if (len == npos || pos + len > npos)
            {
                n = _size - pos;
            }
            string tmp;
            tmp.reserve(n);
            for (size_t i = pos; i < pos + n; ++i) tmp += _str[i];
            return tmp;
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

        bool operator<(const string& s) const
        {
            int ret = strcmp(_str, s._str);
            return ret < 0;
        }

        bool operator==(const string& s) const
        {
            int ret = strcmp(_str, s._str);
            return ret == 0;
        }
        bool operator<= (const string& s) const
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
        bool operator !=(const string& s) const 
        {
            return !(*this == s);
        }
     
        // s1 += 'a'
        string& operator +=(char ch)
        {
            this->push_back(ch);
            return *this;
        }

        string& operator +=(const char* str)
        {
            this->append(str);
            return *this;
        }
    
    private:
        char* _str;
        size_t _size;//已经有多少个有效字符
        size_t _capacity;//能存放多少个有效字符
    public:
        static const size_t npos;
    };
    const size_t string::npos = -1;

    ostream& operator<< (ostream& out, const string& s)
    {
        for (size_t i = 0; i < s.size(); ++i)
        {
            out << s[i];
        }
        return out;
    }

    istream& operator>>(istream& in, string& s)
    {
        s.clear();
        char ch = in.get();
        // 处理前缓冲区前面的空格或者换行
        while (ch == ' ' || ch == '\n')
        {
            ch = in.get();
        }
        //in >> ch;
        char buff[128];
        int i = 0;

        while (ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;
            if (i == 127)
            {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }

            //in >> ch;
            ch = in.get();
        }

        if (i != 0)
        {
            buff[i] = '\0';
            s += buff;
        }

        return in;
    }
}