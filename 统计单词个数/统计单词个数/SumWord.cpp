
//��һ�ַ��� ��cʵ��
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

 textWord.cpp : �������̨Ӧ�ó������ڵ㡣



/*
//�ڶ��ַ���δ������ʵ��
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

void main()
{
	//ifstream ifs("C:\\Users\\user\\Desktop\\1.txt",ios::in);  //���ļ�

	//if (!ifs.is_open()) //�ļ���ȡʧ��
	//{
	//	cout << "Error open file";
	//	exit(1);
	//}

	//char str[1000];  //�����洢���ļ��ж�ȡ����Ϣ
	//int k = 0;
	//
	//while (!ifs.eof())
	//{
	//	str[k] = ifs.get();
	//	k++;
	//}
	//str[k] = '\0'; //������־
	char str[1000];
	int i = 0;
	cout<<"please input string:";
	cin>>str;

	map<string, int> mmap;  //�����������map�������洢ÿ�����ʼ�����ֵĴ���
	
	while (str[i]!='\0')
	{
		string temp;
		temp.clear(); //�����ַ���
		while (str[i] != ' '&& str[i] != '\0'&&str[i] != '\n'&&str[i] != -1)
		{
			temp.insert(temp.end(),str[i]); //Ԫ�صĲ���
			i++;
		}
		
		map<string, int> ::iterator find = mmap.find(temp); //����Ҫ����ĵ����Ƿ��Ѿ���map������
		
		if (find != mmap.end())  //�������У�ʹ���ʵĴ�����ԭ���Ļ����ϼ�1
			find->second += 1;
		else                    //���������У����µ��ʲ��뵽������
			mmap.insert(pair<string,int>(temp,1));

		while ((str[i] == ' ' && str[i] != '\0') || str[i] == '\n' || str[i]==-1)
			i++;
	}
	map<string, int> ::iterator myit = mmap.begin();
	while (myit!=mmap.end()) //��������
	{
		cout << myit->first << "-----> " << myit->second << endl;
		++myit;
	}
	cout << mmap.size();
	system("pause");
	
}
*/
