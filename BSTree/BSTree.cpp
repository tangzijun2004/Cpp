#include<iostream>
#include<string>
using namespace std;
#include"BSTree.hpp"

void TestBSTree2()
{
	tzj::BSTree<string, string>dict;
	dict.Insert("sort", "ÅÅÐò");
	dict.Insert("string", "×Ö·û´®");
	dict.Insert("tree", "Ê÷");
	dict.Insert("inser", "²åÈë");

	string str;
	while (cin >> str)
	{
		tzj::BTreeNode<string, string>* ret = dict.Find(str);
		if (ret)
		{
			cout << ret->_value << endl;
		}
		else
		{
			cout << "ÎÞ¸Ãµ¥´Ê" << endl;
		}
	}
}

void TestBSTree1()
{
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	//int a[] = { 3,4,5,6,7,8,9 };
	key::BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
	t.Erase(5);
	t.InOrder();
}

void TestBSTree3()
{
	string strArr[] = { "Î÷¹Ï","Æ»¹û","Ó£ÌÒ","Î÷¹Ï","Æ»¹û","Î÷¹Ï", "Î÷¹Ï","Æ»¹û","Ó£ÌÒ", "Î÷¹Ï","Î÷¹Ï","Ó£ÌÒ","Î÷¹Ï" };
	tzj::BSTree<string, int> countTree;
	for (auto str : strArr)
	{
		tzj::BTreeNode<string, int>* ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}
#include<vector>
int main()
{

	TestBSTree1();
	//TestBSTree2();
	//TestBSTree3();
	
	return 0;
}

