#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

struct  MyGreater
{
	bool operator()(int left, int right)
	{
		return left > right;
	}

};
void main()
{
	
	//map<int, string> mapTest;
	//mapTest.insert(map<int,string>::value_type(1,"aaaaaa"));
	//mapTest.insert(map<int, string>::value_type(3, "ccccccc"));
	//mapTest.insert(map<int, string>::value_type(2, "bbbbb"));
	//mapTest.insert(map<int, string>::value_type(4, "dddddd"));

	////map（key/value）容器 在对元素进行输出 会自动根据key值进行排序(默认为从小到大排序)
	//for (map<int, string>::const_iterator it = mapTest.begin(); it != mapTest.end(); it++)
	//	cout << it->first << "	" << it->second << endl;

	//利用MyGreater 可实现从大到小进行排序
	map<int, string, MyGreater> mapTest;
	mapTest.insert(map<int, string>::value_type(1, "aaaaaa"));
	mapTest.insert(map<int, string>::value_type(3, "ccccccc"));
	mapTest.insert(map<int, string>::value_type(2, "bbbbb"));
	mapTest.insert(map<int, string>::value_type(4, "dddddd"));

	//map（key/value）容器 在对元素进行输出 会自动根据key值进行排序
	for (map<int, string, MyGreater>::const_iterator it = mapTest.begin(); it != mapTest.end(); it++)
		cout << it->first << "	" << it->second << endl;

	system("pause");

}