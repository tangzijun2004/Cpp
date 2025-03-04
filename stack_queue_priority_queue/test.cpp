#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
#include "queue.h"
#include <algorithm>
using namespace std;

//void test_stack()
//{
//	tzj::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	//没有迭代器
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//}
//
//void test_queue()
//{
//	tzj::queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	q.push(5);
//
//	cout << q.size() << endl;
//
//	//没有迭代器
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	test_stack();
//	test_queue();
//	return 0;
//}


//仿函数
namespace tzj
{
	template<class T>
	struct less
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 < x2;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 > x2;
		}
	};
}


void test_sort()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(6);
	v.push_back(3);
	v.push_back(0);
	v.push_back(8);

	/*greater<int> gt;
	sort(v.begin(),v.end(),gt);*/
	sort(v.begin(), v.end(), tzj::greater<int>());
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

#include"priority_queue.h"
void test_priority_queue1()
{
	// 默认是大堆 -- less
	//priority_queue<int> pq;

	// 仿函数控制实现小堆
	tzj::priority_queue<int, vector<int>, Greater<int>> pq;

	pq.push(3);
	pq.push(5);
	pq.push(1);
	pq.push(4);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

struct LessPDate
{
	bool operator()(const Date* p1, const Date* p2)
	{
		return *p1 < *p2;
	}
};


void test_priority_queue2()
{
	// 仿函数控制实现小堆
	////tzj::priority_queue<Date, vector<Date>, less<Date>> pq;
	//tzj::priority_queue<Date, vector<Date>, greater<Date>> pq;
	//pq.push(Date(2023, 7, 20));
	//pq.push(Date(2023, 6, 20));
	//pq.push(Date(2023, 8, 20));

	//while (!pq.empty())
	//{
	//	cout << pq.top() << " ";
	//	pq.pop();
	//}
	//cout << endl;

	tzj::priority_queue<Date*, vector<Date*>, LessPDate> pq;
	pq.push(new Date(2023, 7, 20));
	pq.push(new Date(2023, 6, 20));
	pq.push(new Date(2023, 8, 20));

	while (!pq.empty())
	{
		cout << *pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}
int main()
{
	test_priority_queue1();
	test_priority_queue2();
	//test_sort();
	return 0;
}
