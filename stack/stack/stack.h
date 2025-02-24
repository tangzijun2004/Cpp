#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;
#pragma once;

namespace tzj
{
	template<class T, class Container>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		size_t Size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

		T& top()
		{
			return _con.back();
		}

	private:
		Container _con;
	};

	void test_stack()
	{
		//stack<int, vector<int>> st;
		//stack<int, list<int>> st;
		stack<int, deque<int>> st;

		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}

	}
}