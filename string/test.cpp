#include "string.h"

void test_string1() 
{
    tzj::string s1("hello");
    tzj::string s2;
    std::cout << "s1: " << s1.c_str() << ", size: " << s1.size() << ", capacity: " << s1.capacity() << std::endl;
    std::cout << "s2: " << s2.c_str() << ", size: " << s2.size() << ", capacity: " << s2.capacity() << std::endl;

    // 测试 operator[]
    for (size_t i = 0; i < s1.size(); ++i) 
    {
        std::cout << s1[i] << " ";
    }
    std::cout << std::endl;
}

void test_string2() 
{
    tzj::string s1("hello");
    tzj::string s2(s1); // 拷贝构造函数
    tzj::string s3;
    s3 = s1; // 赋值运算符

    std::cout << "s1: " << s1.c_str() << std::endl;
    std::cout << "s2 (copy of s1): " << s2.c_str() << std::endl;
    std::cout << "s3 (assigned from s1): " << s3.c_str() << std::endl;
}

void test_string3() 
{
    tzj::string s1("hello");
    std::cout << "Before reserve: size=" << s1.size() << ", capacity=" << s1.capacity() << std::endl;
    s1.reserve(20);
    std::cout << "After reserve(20): size=" << s1.size() << ", capacity=" << s1.capacity() << std::endl;

    s1.resize(10, 'x');
    std::cout << "After resize(10, 'x'): " << s1.c_str() << ", size=" << s1.size() << std::endl;

    s1.resize(3);
    std::cout << "After resize(3): " << s1.c_str() << ", size=" << s1.size() << std::endl;
}

void test_string4() 
{
    tzj::string s1("hello");
    s1.push_back('!');
    std::cout << "After push_back('!'): " << s1.c_str() << std::endl;

    s1.append(" world");
    std::cout << "After append(\" world\"): " << s1.c_str() << std::endl;
}

void test_string5() 
{
    tzj::string s1("hello");
    s1.insert(2, 'x');
    std::cout << "After insert(2, 'x'): " << s1.c_str() << std::endl;

    s1.insert(3, "abc");
    std::cout << "After insert(3, \"abc\"): " << s1.c_str() << std::endl;
}

void test_string6() 
{
    tzj::string s1("hello world");
    s1.erase(5, 6);
    std::cout << "After erase(5, 6): " << s1.c_str() << std::endl;

    s1.erase(2);
    std::cout << "After erase(2): " << s1.c_str() << std::endl;
}

void test_string7() 
{
    tzj::string s1("hello world");
    size_t pos = s1.find('o');
    std::cout << "Find 'o' in s1: " << pos << std::endl;

    pos = s1.find("world");
    std::cout << "Find \"world\" in s1: " << pos << std::endl;

    tzj::string sub = s1.substr(6, 5);
    std::cout << "Substr(6, 5): " << sub.c_str() << std::endl;
}

void test_string8() 
{
    tzj::string s1("hello");
    tzj::string s2("world");
    tzj::string s3("hello");

    std::cout << "s1 == s3: " << (s1 == s3) << std::endl;
    std::cout << "s1 != s2: " << (s1 != s2) << std::endl;
    std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
    std::cout << "s1 > s2: " << (s1 > s2) << std::endl;
}

void test_string9() 
{
    tzj::string s1("hello");
    s1 += '!';
    std::cout << "After += '!': " << s1.c_str() << std::endl;

    s1 += " world";
    std::cout << "After += \" world\": " << s1.c_str() << std::endl;
}

void test_string10() 
{
    tzj::string s1("hello world");
    std::cout << "Before clear: " << s1.c_str() << std::endl;
    s1.clear();
    std::cout << "After clear: " << s1.c_str() << ", size=" << s1.size() << std::endl;
}

void test_string11() 
{
    tzj::string s1;
    std::cout << "Enter a string: ";
    std::cin >> s1;
    std::cout << "You entered: " << s1 << std::endl;
}

void test_string_all() 
{
    //test_string1();
    //test_string2();
    //test_string3();
    //test_string4();
    test_string5();
    test_string6();
    test_string7();
    test_string8();
    test_string9();
    test_string10();
    test_string11();
}

int main() 
{
    test_string_all(); // 运行所有测试
    return 0;
}