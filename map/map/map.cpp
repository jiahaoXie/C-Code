#include<iostream>
#include<map>
#include<string>
using namespace std;
void main()
{
	/*
	map<string,int>mapTest;//����mapģ����һ��map�����
	///map�������ݵļ��ַ���
	///���뵽map�����ڲ���Ԫ��Ĭ���ǰ���keyֵ��С�����������
	///key����Ҫ��һ���ܹ�����<�����

	mapTest["aaa"]=100;
	mapTest["aaa"]=1000;
	mapTest["eee"]=500;
	mapTest["eee"]=5000;
	mapTest.insert(map<string,int>::value_type("bbb",200));//��׼���뷽��
	mapTest.insert(map<string,int>::value_type("bbb",2000));
	mapTest.insert(pair<string,int>("ccc",300));
	mapTest.insert(pair<string,int>("ccc",3000));
	mapTest.insert(make_pair("ddd",400));
	mapTest.insert(make_pair("ddd",4000));
	//map�в������ݵļ��ַ����� ֻ�е�һ�ֿ���mapTest["aaa"]��һkey�����һ�θ�ֵΪ��׼���������ǵ�һ�θ�ֵΪ��׼
	
	//map�е��������
	map<string,int>::iterator it;
	for(it=mapTest.begin();it!=mapTest.end();++it)
	{
		cout<<it->first<<"  "<<it->second<<endl;
	}
	*/

	map<string,int>mapTest;//����mapģ����һ��map�����
	mapTest["aaa"]=100;
	mapTest["eee"]=500;
	mapTest.insert(map<string,int>::value_type("bbb",200));//��׼���뷽��
	mapTest.insert(pair<string,int>("ccc",300));
	mapTest.insert(make_pair("ddd",400));

	int n=mapTest["bbb"];//����ĳ��key����Ӧ��valueֵ��
	cout<<n<<endl;		//��map��û�����key ����ֵΪ0
	
	//�������õ�������map�е�Ԫ�ؽ��в��Һ��޸�
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

	//map������ɾ���ķ��� erase
	mapTest.erase("bbb");//ɾ������1

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