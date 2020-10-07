//向后插入
//back_insert_iterator	back_insert
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

void ShowVec(const vector<int>& v)
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void main()
{
	int a[] = {1,2,3,4,5};
	vector<int> v(a,a+5);
	vector<int> v2;

	v.push_back(6);
	back_insert_iterator<vector<int> > b(v);
	*b = 7;
	//这里的插入迭代器 back_insert_oterator 是往容器后面插入数据 
			//作用效果等同于push_banck()
	ShowVec(v);

	cout << "copy result:v2-v" << endl;
	back_insert_iterator<vector<int> > b2(v2);
	copy(v.begin(),v.end(),b2);
	ShowVec(v2);

	back_inserter(v)=8;	
//back_inserter（）与back_insert_iterator<>相比 不需要指定类型，源代码中类模板自动识别定义的对象的类型
	ShowVec(v);

	cout << "copy result:v2-v" << endl;
	copy(v.begin(),v.end(),back_inserter(v2));
	//copy()方法在v2后面插入
	ShowVec(v2);

	system("pause");
}
