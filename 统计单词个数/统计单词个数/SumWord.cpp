
//第一种方法 用c实现
#include<stdio.h>
#include<iostream>
void main()
{
	char a[100],c1,c2;
	int i,sum;
	printf("please input string to array a:");
	gets(a);
	i=sum=0;
	while(a[i]!='\0')
	{
		c1=a[i];
		if(i==0)
			c2=' ';
		else
			c2=a[i-1];
		if(c1!=' '&&c2==' ')
			sum++;
		i++;
		
	}
	printf("the string have %d words!",sum);
	system("pause");
}

 textWord.cpp : 定义控制台应用程序的入口点。



/*
//第二种方法未能运行实现
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

void main()
{
	//ifstream ifs("C:\\Users\\user\\Desktop\\1.txt",ios::in);  //打开文件

	//if (!ifs.is_open()) //文件读取失败
	//{
	//	cout << "Error open file";
	//	exit(1);
	//}

	//char str[1000];  //用来存储从文件中读取的信息
	//int k = 0;
	//
	//while (!ifs.eof())
	//{
	//	str[k] = ifs.get();
	//	k++;
	//}
	//str[k] = '\0'; //结束标志
	char str[1000];
	int i = 0;
	cout<<"please input string:";
	cin>>str;

	map<string, int> mmap;  //定义关联容器map，用来存储每个单词及其出现的次数
	
	while (str[i]!='\0')
	{
		string temp;
		temp.clear(); //重置字符串
		while (str[i] != ' '&& str[i] != '\0'&&str[i] != '\n'&&str[i] != -1)
		{
			temp.insert(temp.end(),str[i]); //元素的插入
			i++;
		}
		
		map<string, int> ::iterator find = mmap.find(temp); //查所要插入的单词是否已经在map容器中
		
		if (find != mmap.end())  //在容器中，使单词的次数在原来的基础上加1
			find->second += 1;
		else                    //不在容器中，将新单词插入到容器中
			mmap.insert(pair<string,int>(temp,1));

		while ((str[i] == ' ' && str[i] != '\0') || str[i] == '\n' || str[i]==-1)
			i++;
	}
	map<string, int> ::iterator myit = mmap.begin();
	while (myit!=mmap.end()) //遍历单词
	{
		cout << myit->first << "-----> " << myit->second << endl;
		++myit;
	}
	cout << mmap.size();
	system("pause");
	
}
*/
