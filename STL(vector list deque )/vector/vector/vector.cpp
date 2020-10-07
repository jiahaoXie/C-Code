#include<iostream>
#include<vector>
#include<algorithm>	//算法要包含算法的头文件
using namespace std;

typedef vector<int> VINT;
void output(VINT &v)
{
	VINT::iterator it;
	for(it=v.begin();it!=v.end();++it)
		cout<<*it<<" ";
	cout<<endl;
}
void main()
{
	VINT v;
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(11);
	v.push_back(14);
	v.push_back(11);

	output(v);//还可通过迭代器来进行数据输出
	
	/*remove(v.begin(),v.end(),11);
	output(v);*/

	v.erase(remove(v.begin(),v.end(),11),v.end());
	//可通过erase和remove删除vector中特定的元素 

	//还可以利用迭代器进行for循环中的删除
	//VINT::iterator it;
	//for(it=v.begin();it!=v.end();)
	//{
	//	if(*it==11)
	//		it=v.erase(it);//删除当前下标位置的元素，并将下一个元素的下标给it
	//	else
	//		++it;
	//}

	//output(v);
	
	//也可通过数组输出的形式输出vector中的元素
	for(unsigned int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	

	system("pause");
}