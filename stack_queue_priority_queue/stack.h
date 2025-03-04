#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;
#pragma once;

namespace tzj
{
	template<class T, class Container = deque<T>>
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
}