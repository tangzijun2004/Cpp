#include "list.h"
#include <iostream>
using tzj::list;
using namespace std;

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();

	while (it != lt.end())
	{
		(*it) += 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

}

struct A
{
	A(int a1 = 0, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
	{}

	int _a1;
	int _a2;
};

void test_list2()
{
	list<A> lt;
	lt.push_back(A(1, 1));
	lt.push_back(A(2, 2));
	lt.push_back(A(3, 3));
	lt.push_back(A(4, 4));

	list<A>::iterator it = lt.begin();
	while (it != lt.end())
	{
		//cout << (*it)._a1 << " " << (*it)._a2 << endl;
		cout << it->_a1 << " " << it->_a2 << endl;

		++it;
	}
	cout << endl;
}

void test_list3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_front(5);
	lt.push_front(6);
	lt.push_front(7);
	lt.push_front(8);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_front();
	lt.pop_back();

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.clear();
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << lt.size() << endl;
}

void test_list4()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> lt1(lt);
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> lt2;
	lt2.push_back(10);
	lt2.push_back(20);
	lt2.push_back(30);
	lt2.push_back(40);

	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1 = lt2;

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test_list1();
	test_list2();
	test_list3();
	test_list4();
	return 0;
}