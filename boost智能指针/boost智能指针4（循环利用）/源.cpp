#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
using namespace std;

class Parent;
class Child;
typedef boost::shared_ptr<Parent> parent_ptr;
typedef boost::shared_ptr<Child> child_ptr;
class Child
{
public:
	Child() { cout << "Child ..." << endl; }
	~Child() { cout << "~Child ..." << endl; }
	parent_ptr parent_;

};
class Parent
{
public:
	Parent() { cout << "Parent ..." << endl; }
	~Parent() { cout << "~Parent ..." << endl; }
	boost::weak_ptr<Child> child_;//����ѭ������
};
void main(void)
{
	parent_ptr parent(new Parent);//1
	child_ptr child(new Child);//1
	parent->child_ = child;//���ò���1
	child->parent_ = parent;//2

	////����ѭ������
	//parent->child_.reset();

	system("pause");
}