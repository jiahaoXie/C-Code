#include<iostream>
#include<time.h>
#include<string>
#include<windows.h>
using namespace std;
int main()
{
	string s1[9]={"asa","afcs","gd","hh","htdh","htdfj","kiul","dtd","ytj"};
	string s;
	int i;
	string::size_type idx;
	for(int i=0;i<9;i++)
		cout<<s1[i]<<"\t";
	cout<<"\nplease input the words that you want to find:";
	cin>>s;
	 double dur;
    clock_t start,end;
    start = clock();
   
    
	for(i=0;i<9;i++)
	{

		idx=s1[i].find(s);//在s1[]中查找s.
		if(idx != string::npos )//存在则输出。
		{
			cout << "words found\n"<<s1[i]<<"  "<<i+1<<endl;
			
			end=clock();
			 dur = (double)(end - start);
   printf("Use Time:%f\n",(dur/CLOCKS_PER_SEC));
			break;
		}	 
	}
	if(i>=9)
		cout<<"words not find!"<<endl;
	system("pause");
}