//ostream_iterator �����������
//istream_iterator ������������

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
	//����̨��̨���������^z��
	//copy form vector to cout
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout << endl;

	system("pause");
}