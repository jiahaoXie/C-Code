#include<iostream>
#include<string>
using namespace std;
void main()
{
	/*
	string s1("abcdABCD");
	cout<<s1<<endl;

	string s2(s1,2,5);
	cout<<s2<<endl;

	string::iterator first=s1.begin()+1;
	string::iterator end=s1.end();
	string::iterator last=s1.begin()+5;

	string s3(first,end);
	cout<<s3<<endl;
	
	string s4(first,last);//[first,last) ����first ������last
	cout<<s4<<endl;
	*/
	/*
	string s1("assdcsdfvds");
	cout<<s1.size()<<endl;//�õ��ַ�������
	cout<<s1.length()<<endl;
	
	cout<<s1.substr(1,6)<<endl;//substr��ȡ�ַ�������

	string::size_type pos=s1.find('c',2);//���ַ����в���ĳ���ַ�
	if(pos==string::npos) 
		cout<<"not found"<<endl;
	else
		cout<<"the char found:"<<pos<<endl;

	s1.replace(1,2,"ASDC");//replace�滻ָ���ַ�
	cout<<s1<<endl;

	s1.insert(1,"1234");//���ַ�����ָ��λ�ò����ַ���
	cout<<s1<<endl;

	s1.append("5566");//���ַ���ĩβ�����ַ���
	cout<<s1<<endl;

	string s2("1234");
	string s3("55667788");
	s2.swap(s3);//�ַ��� s2 ��s3���н���
	cout<<"s2="<<s2<<endl;
	cout<<"s3="<<s3<<endl;
	*/
	/*
	//�ַ����е���Ч�ַ���ȡ
	string s1="-----Hello world!!----";
	string s2="abcdABCDEFJH";
	string::size_type first=s1.find_first_of(s2);
	if(first==string::npos)
		cout<<"not found"<<endl;

	string::size_type end=s1.find_last_of(s2);
	if(end==string::npos)
		cout<<"not found"<<endl;
	cout<<s1.substr(first,end-first+1)<<endl;
	*/
	/*
	//ɾ��һ���ַ����е����ҿո� ���õ���Ա����erase
	string s1=" aa bb cc  dd ff ss  cc ";
	cout<<"the origin string:"<<s1<<endl;
	int index=0;
	 if( !s1.empty())
    {
         while( (index = s1.find(' ',index)) != string::npos)
         {
             s1.erase(index,1);
         }
     }
	 cout<<"the upgrade sting:"<<s1<<endl;
	 */

	//ɾ���ַ����е�ǰ��ո�
	string s1=" aa bb  cc  ddd ff ss  ";
	s1.erase(0,s1.find_first_not_of(" "));
	s1.erase(s1.find_last_not_of(" ")+1);
	cout<<"["<<s1<<"]"<<endl;
	system("pause");
}
