#include<iostream>
#include"max.h"
using namespace std;

//����һ������ģ��
//template <typename T>
//const T& max(const T& a, const T& b)//ģ�塣���Ǻ��������ܱ�����
//{
//	return a < b ? b : a;
//}

void main()
{
	//����ģ���ǲ������Ķ�̬����
	//����ģ�岻�Ǻ��������ܱ�ִ�С�
	//ֻ����ϵͳ����ʱʵ��������Ϊģ�庯���������ĺ����������ܱ�ִ��
	cout << ::max(5.5, 15.15) << endl;		//�Զ��Ƶ�Ϊmax(const int& a,const int& b)
	cout << ::max('a', 'c') << endl;		////�Զ��Ƶ�Ϊmax(const char& a,const char& b)
	
	const char* str1 = "aaa";
	const char* str2 = "zzz";
	cout << ::max(str1, str2) << endl;
	cout << ::max(1, 5, 3) << endl;

	cout << ::max('a', 66) << endl;
	//�ɷ�ģ�庯��const int& max(const int& a, const int& b)�õ� ��Ϊchar�Ϳ�����ʽת��Ϊiny��

	cout << ::max<>(97, 100) << endl;//ģ�庯���Զ��Ƶ� max(const int&,const int&)
	cout << ::max<int>(97, 100) << endl;//��ʾָ��ģ�庯�� max(const int&,const int&)

	system("pause");
}