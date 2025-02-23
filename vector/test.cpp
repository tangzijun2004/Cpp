#include "vector.h"
using tzj::vector;

void print(const vector<int>& v)
{
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v1.size(); i++)
	{
		v1[i]++;
	}

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	print(v1);
}

void test_vector2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(5);

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.insert(v1.begin(), 100);

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//vector<int>::iterator p = v1.begin() + 3;
	//v1.insert(p, 300);

	vector<int>::iterator p = v1.begin() + 3;
	v1.insert(p+3, 300);

	//// insert以后迭代器可能会失效(扩容)
	//// insert以后就不要使用这个形参迭代器了，因为他可能失效了
	//v1.insert(p, 300);

	// //高危行为
	// *p += 10;

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector3()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	auto it = v1.begin();
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			it = v1.erase(it);
		}
		else
		{
			++it;
		}
	}

	//v1.erase(v1.begin());
	//auto it = v1.begin()+4;
	//v1.erase(it);

	////// erase以后，迭代器失效了，不能访问
	////// vs进行强制检查，访问会直接报错
	//cout << *it << endl;
	//++it;
	//cout << *it << endl;

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector4()
{
	vector<int> v;
	v.resize(10, 0);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;


	int i = 0;
	int j = int();
	int k = int(1);
}

void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int> v1(v);

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2;
	v2.resize(10, 1);

	v1 = v2;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector6()
{
	vector<string> v;
	v.push_back("111111111111111111");
	v.push_back("222222222222222222");
	v.push_back("333333333333333333");
	v.push_back("444444444444444444");
	v.push_back("555555555555555555");

	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<string> v1(v);
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector7()
{
	vector<int> v((size_t)10, 1);
	vector<string> v1(10, "1111");

	vector<int> v2(10, 1);



	// vector<int> v;

	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;


	vector<int> v3(v.begin(), v.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	string str("hello world");
	vector<char> v4(str.begin(), str.end());
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	int a[] = { 16,2,77,29 };
	vector<int> v5(a, a + 4);
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test_vector7();
	return 0;
}