#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
using namespace std;

class Person
{
public:
	Person(const string& name) :name_(name) {}
	void Print()  const{ cout << name_ << endl; }
	void PrintWithPrefix(string prefix) const
	{
		cout << prefix << name_ << endl;
	}
private:
	string name_;
};

void foo(const vector<Person>& v)
{
	for_each(v.begin(),v.end(),mem_fun_ref(&Person::Print));	//无参数 则采用一元函数对象
	for_each(v.begin(),v.end(),bind2nd(mem_fun_ref(&Person::PrintWithPrefix),"Person:"));
	//有参数 则采用bind2nd()将二元函数对象modulus转换一元函数对象
	//两个方法构成函数重载
}

void foo2(const vector<Person*>& v)
{//vector<Person*>& v这里是针对对象指针
	for_each(v.begin(),v.end(),mem_fun(&Person::Print));
	for_each(v.begin(),v.end(),bind2nd(mem_fun(&Person::PrintWithPrefix),"Person"));
}

void main()
{
	vector<Person> v;
	v.push_back(Person("tom"));
	v.push_back(Person("jerry"));
	foo(v);

	system("pause");
}