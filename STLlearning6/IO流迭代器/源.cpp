//ostream_iterator 输出流迭代器
//istream_iterator 输入流迭代器

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;

void main()
{
	//int a[] = { 1,2,3,4,5 };
	//vector<int> v(a, a + 5);

	////copy form vector to cout
	//copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	//cout << endl;

	vector<int> v;
	//copy from cin to vector
	copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(v));
	//控制台后台输入结束（^z）
	//copy form vector to cout
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout << endl;

	system("pause");
}