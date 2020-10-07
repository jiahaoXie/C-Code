#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_element(int n)
{
	cout << n << "	";
}


class Print
{
public:
	void operator()(int n)
	{
		cout << n << "	";
	}

};

void Add3(int &n)
{
	n += 3;
}
class ADD
{
public:
	ADD(int number) :number_(number) {}
	void operator()(int& n)
	{
		n += number_;
	}
private:
	int number_;
};

class GreaterObj
{
public:
	GreaterObj(int number) :number_(number) {}
	bool operator()(int& n)
	{
		return n > number_;
	}
private:
	int number_;
};
void main()
{
	int a[] = {1,2,3,4,5};
	vector<int>  v(a,a+5);
	cout << "函数print_element：\n";
	for_each(v.begin(), v.end(), print_element);
	cout << endl;


	for_each(v.begin(), v.end(), Add3);
	for_each(v.begin(), v.end(), print_element);
	cout << endl;


	cout << "函数对象p:\n";
	Print p;
	for_each(v.begin(), v.end(),p);
	cout << endl;

	
	for_each(v.begin(), v.end(),ADD(5));	
		//很奇怪的一点是这里用ADD() 可以通过，但是定义一个类对象放入（例如ADD a）编译出错
	for_each(v.begin(), v.end(), p);
	cout << endl;


	//利用count_if（）统计大于某个数的个数
	cout<<count_if(v.begin(), v.end(), GreaterObj(3)) << endl;
	cout << count_if(a,a+5, GreaterObj(3)) << endl;

	system("pause");
}