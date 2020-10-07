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
	
	string s4(first,last);//[first,last) 包含first 不包含last
	cout<<s4<<endl;
	*/
	/*
	string s1("assdcsdfvds");
	cout<<s1.size()<<endl;//得到字符串长度
	cout<<s1.length()<<endl;
	
	cout<<s1.substr(1,6)<<endl;//substr截取字符串长度

	string::size_type pos=s1.find('c',2);//在字符串中查找某个字符
	if(pos==string::npos) 
		cout<<"not found"<<endl;
	else
		cout<<"the char found:"<<pos<<endl;

	s1.replace(1,2,"ASDC");//replace替换指定字符
	cout<<s1<<endl;

	s1.insert(1,"1234");//在字符串中指定位置插入字符串
	cout<<s1<<endl;

	s1.append("5566");//在字符串末尾增加字符串
	cout<<s1<<endl;

	string s2("1234");
	string s3("55667788");
	s2.swap(s3);//字符串 s2 和s3进行交换
	cout<<"s2="<<s2<<endl;
	cout<<"s3="<<s3<<endl;
	*/
	/*
	//字符串中的有效字符截取
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
	//删除一个字符串中的左右空格 利用到成员函数erase
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

	//删除字符串中的前后空格
	string s1=" aa bb  cc  ddd ff ss  ";
	s1.erase(0,s1.find_first_not_of(" "));
	s1.erase(s1.find_last_not_of(" ")+1);
	cout<<"["<<s1<<"]"<<endl;
	system("pause");
}
