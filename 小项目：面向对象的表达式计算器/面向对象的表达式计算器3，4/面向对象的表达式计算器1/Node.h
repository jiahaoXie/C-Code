
#ifndef _NODE_H_
#define _NODE_H_

//类noncopyable的作用是对象语义 禁止拷贝（编程中 个人觉得可有可无）
class noncopyable
{
protected:
	noncopyable() {}
	~noncopyable() {}
private:
	noncopyable(const noncopyable&);
	const noncopyable& operator=(const noncopyable);
};

//类Node作为抽象类！！
class Node:public noncopyable
{
public:
	virtual double Calc() const = 0;
	virtual ~Node() {};//析构函数声明为虚函数，析构时才会调用派生类析构函数
};

class NumberNode : public Node
{
public:
	NumberNode(double number) : number_(number) {}
	double Calc() const;//如果不实现，则其也是抽象类
private:
	const double number_;

};

class BinaryNode : public Node//抽象类
{
public:
	BinaryNode(Node* left, Node* right)
		: left_(left), right_(right) {}
	~BinaryNode();//需要释放left_,right_
protected:
	Node* const left_;//（指针常量）指针本身不能改变，不能指向其他节点
	Node* const right_;//注意指针常量与指向常量的指针二者之间的区别！

};
class UnaryNode : public Node
{
public:
	UnaryNode(Node* child)
		: child_(child) {}
	~UnaryNode();
protected:
	Node* const child_;

};
class AddNode : public BinaryNode
{
public:
	AddNode(Node* left, Node* right)
		:BinaryNode(left, right) {}//调用基类构造函数初始化
	double Calc() const;//需要实现
};

class SubNode : public BinaryNode
{
public:
	SubNode(Node* left, Node* right)
		:BinaryNode(left, right) {}//调用基类构造函数初始化
	double Calc() const;//需要实现
};

class MultiplyNode : public BinaryNode
{
public:
	MultiplyNode(Node* left, Node* right)
		:BinaryNode(left, right) {}//调用基类构造函数初始化
	double Calc() const;//需要实现
};

class DivideNode : public BinaryNode
{
public:
	DivideNode(Node* left, Node* right)
		:BinaryNode(left, right) {}//调用基类构造函数初始化
	double Calc() const;//需要实现
};

class UMinusNode : public UnaryNode
{
public:
	UMinusNode(Node* child)
		:UnaryNode(child) {}
	double Calc() const;

};
#endif
