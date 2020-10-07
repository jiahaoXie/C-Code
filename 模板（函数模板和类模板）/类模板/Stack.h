//Stack.h
#ifndef _STACK_H_
#define _STACK_H_

#include<exception>
//首先声明一个类模板（这里程序代码实现的是一个栈）
template <typename T>
class Stack
{
public:
	explicit Stack(int maxSize);//关键字explicit是为了防止其隐式构造
	~Stack();

	void Push(const T& elem);
	void Pop();
	T& Top();
	const T& Top() const;
	bool Empty() const;
private:
	T* elems_;
	int maxSize_;
	int top_;
};

template <typename T>
Stack<T>::Stack(int maxSize) :maxSize_(maxSize), top_(-1)
{
	elems_ = new T[maxSize_];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] elems_;
}

template <typename T>
void Stack<T>::Push(const T& elem)
{
	if (top_ + 1 >= maxSize_)
		throw out_of_range("Stack<>::Push() stack full");
		//out_of_range为标准库中的异常
	elems_[++top_] = elem;

}
template <typename T>
void Stack<T>::Pop()
{
	if (top_ + 1 <= 0)
		throw out_of_range("Stack<>::Push() stack empty");
	--top_;

}
template <typename T>
T& Stack<T>::Top()
{
	if (top_ + 1 <= 0)
		throw out_of_range("Stack<>::Push() stack empty");
	return elems_[top_];
}
template <typename T>
const T& Stack<T>::Top() const
{
	if (top_ + 1 <= 0)
		throw out_of_range("Stack<>::Push() stack empty");
	return elems_[top_];
}

template <typename T>
bool Stack<T>::Empty() const
{
	return top_ + 1 == 0;
}
#endif//_STACK_H_