#include<iostream>
#include<map>
#include<string>
using namespace std;
void main()
{
	/*
	map<string,int>mapTest;//利用map模构造一个map类对象
	///map插入数据的几种方法
	///插入到map容器内部的元素默认是按照key值从小到大进行排序
	///key类型要求一定能够重载<运算符

	mapTest["aaa"]=100;
	mapTest["aaa"]=1000;
	mapTest["eee"]=500;
	mapTest["eee"]=5000;
	mapTest.insert(map<string,int>::value_type("bbb",200));//标准插入方法
	mapTest.insert(map<string,int>::value_type("bbb",2000));
	mapTest.insert(pair<string,int>("ccc",300));
	mapTest.insert(pair<string,int>("ccc",3000));
	mapTest.insert(make_pair("ddd",400));
	mapTest.insert(make_pair("ddd",4000));
	//map中插入数据的几种方法里 只有第一种可以mapTest["aaa"]是一key得最后一次赋值为基准，其他都是第一次赋值为基准
	
	//map中的数据输出
	map<string,int>::iterator it;
	for(it=mapTest.begin();it!=mapTest.end();++it)
	{
		cout<<it->first<<"  "<<it->second<<endl;
	}
	*/

	map<string,int>mapTest;//利用map模构造一个map类对象
	mapTest["aaa"]=100;
	mapTest["eee"]=500;
	mapTest.insert(map<string,int>::value_type("bbb",200));//标准插入方法
	mapTest.insert(pair<string,int>("ccc",300));
	mapTest.insert(make_pair("ddd",400));

	int n=mapTest["bbb"];//查找某个key所对应的value值。
	cout<<n<<endl;		//若map中没有这个key 返回值为0
	
	//还可利用迭代器对map中的元素进行查找和修改
	map<string,int>::iterator i;
	i=mapTest.find("ccc");
	/*if(i!=mapTest.end())
		cout<<i->second<<endl;*/
	if(i!=mapTest.end())
	{
		i->second=222;
		cout<<i->second<<endl;
	}
	else
		cout<<"not found"<<endl;

	//map中数据删除的方法 erase
	mapTest.erase("bbb");//删除方法1

	map<string,int>::iterator it;
	it=mapTest.find("ccc");
	if(it!=mapTest.end())
		mapTest.erase(it);
	for(it=mapTest.begin();it!=mapTest.end();++it)
	{
		cout<<it->first<<"  "<<it->second<<endl;
	}
	system("pause");
}