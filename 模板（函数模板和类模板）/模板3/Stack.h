//Stack.h
#ifndef _STACK_H_
#define _STACK_H_

#include <exception>
#include <deque>
using namespace std;

template <typename T, typename CONT = deque<T> >	
//模板类当做参数来进行传递	这里是缺省模板参数
//deque也是一个容器
class Stack
{
public:
	Stack() :c_()
	{

	}
	~Stack()
	{

	}

	void Push(const T& elem)
	{
		c_.push_back(elem);
	}
	void Pop()
	{
		c_.pop_back();//back()去除容器里面最后一个
	}
	T& Top()
	{
		return c_.back();
	}
	const T& Top() const
	{
		return c_.back();
	}
	bool Empty() const
	{
		return c_.empty();
	}
private:
	CONT c_;
	int top_;
};
#endif//_STACK_H_