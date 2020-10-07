
#ifndef _NODE_H_
#define _NODE_H_
#include<vector>
#include<cassert>
#include<xmemory>
class Storage;
#include "FunctionTable.h"
#include"ptr_vector.h"

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
	virtual bool IsLvalue() const
	{
		return false;
	}
	virtual void Assign(double)
	{
		assert(!"Assign called incorrectlly.");
	}
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
	BinaryNode(std::auto_ptr<Node>& left, std::auto_ptr<Node>& right)
		: left_(left), right_(right) {}
	~BinaryNode();//需要释放left_,right_
protected:
	//Node* const left_;//（指针常量）指针本身不能改变，不能指向其他节点
	//Node* const right_;//注意指针常量与指向常量的指针二者之间的区别！
	std::auto_ptr<Node>left_;
	std::auto_ptr<Node>right_;

};
class UnaryNode : public Node
{
public:
	UnaryNode(std::auto_ptr<Node>& child)
		: child_(child) {}
	~UnaryNode();
protected:
	std::auto_ptr<Node>  child_;

};

class FunctionNode : public UnaryNode
{
public:
	FunctionNode(std::auto_ptr<Node>& child, PtrFun pFun)
		: UnaryNode(child), pFun_(pFun) {}

	double Calc() const;//函数节点 计算
private:
	PtrFun pFun_;
};
//class AddNode : public BinaryNode
//{
//public:
//	AddNode(Node* left, Node* right)
//		:BinaryNode(left, right) {}//调用基类构造函数初始化
//	double Calc() const;//需要实现
//};
//
//class SubNode : public BinaryNode
//{
//public:
//	SubNode(Node* left, Node* right)
//		:BinaryNode(left, right) {}//调用基类构造函数初始化
//	double Calc() const;//需要实现
//};
//
//class MultiplyNode : public BinaryNode
//{
//public:
//	MultiplyNode(Node* left, Node* right)
//		:BinaryNode(left, right) {}//调用基类构造函数初始化
//	double Calc() const;//需要实现
//};
//
//class DivideNode : public BinaryNode
//{
//public:
//	DivideNode(Node* left, Node* right)
//		:BinaryNode(left, right) {}//调用基类构造函数初始化
//	double Calc() const;//需要实现
//};

class UMinusNode : public UnaryNode
{
public:
	UMinusNode(std::auto_ptr<Node> child)
		:UnaryNode(child) {}
	double Calc() const;

};
class MultipleNode : public Node
{
public:
	MultipleNode(std::auto_ptr<Node>& node)
	{
		AppendChild(node, true);
	}
	void AppendChild(std::auto_ptr<Node>& node, bool positive)
	{
		childs_.push_back(node);
		//childs_.push_back(node.release());	
		//这里不能将 智能指针直接放进vector容器中，必须调用release()函数返回其原生指针放进来
		positives_.push_back(positive);
	}
	//在AppendChild(）函数中 指针所有权释放了
	//vector 保存的是指针本身，并没有保存指针所指向的内存
	//vector不负责指针指向的内存的管理
	
	//vector内部至少要分配4个字节的内存，才能存放
	//现代的操作系统都支持虚拟内存 operator new操作的时候，分配内存可能会失败
	//要插入的裸指针node.release()还没插入到vector中（概率低）

	~MultipleNode();
protected:
	//std::vector<Node*> childs_;
	ptr_vector<Node> childs_;
	
	//这里在使用智能指针时 还有一个原生指针Node* ，存在一定内存泄漏
	//在vector<>中不能直接存放智能指针
	//vector析构的时候是不会自动释放所指向的内存的,它只负责释放指针变量本身。
	//因而 这里指针内存的释放需要调用析构函数进行delete  例如~MultipleNode(){...delete *it;..}

	std::vector<bool> positives_;
};


class SumNode : public MultipleNode
{
public:
	SumNode(std::auto_ptr<Node> node)
		: MultipleNode(node) {}
	double Calc() const;
};


class ProductNode : public MultipleNode
{
public:
	ProductNode(std::auto_ptr<Node>& node)
		: MultipleNode(node) {}
	double Calc() const;
};
class VariableNode : public Node
{
public:
	VariableNode(unsigned int id, Storage& storage)
		: id_(id), storage_(storage) {}
	double Calc() const;
	bool IsLvalue() const;
	void Assign(double val);
private:
	const unsigned int id_;
	Storage& storage_;
};

class AssignNode : public BinaryNode
{
public:
	AssignNode(std::auto_ptr<Node>& left, std::auto_ptr<Node>& right)
		: BinaryNode(left, right)
	{
		assert(left_->IsLvalue());//断言它是一个左值节点
	}
	double Calc() const;
};
#endif
