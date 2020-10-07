
#ifndef _NODE_H_
#define _NODE_H_
#include<vector>
#include<cassert>
#include<xmemory>
class Storage;
#include "FunctionTable.h"
#include"ptr_vector.h"

//��noncopyable�������Ƕ������� ��ֹ����������� ���˾��ÿ��п��ޣ�
class noncopyable
{
protected:
	noncopyable() {}
	~noncopyable() {}
private:
	noncopyable(const noncopyable&);
	const noncopyable& operator=(const noncopyable);
};

//��Node��Ϊ�����࣡��
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
	virtual ~Node() {};//������������Ϊ�麯��������ʱ�Ż������������������
};

class NumberNode : public Node
{
public:
	NumberNode(double number) : number_(number) {}
	double Calc() const;//�����ʵ�֣�����Ҳ�ǳ�����
private:
	const double number_;

};

class BinaryNode : public Node//������
{
public:
	BinaryNode(std::auto_ptr<Node>& left, std::auto_ptr<Node>& right)
		: left_(left), right_(right) {}
	~BinaryNode();//��Ҫ�ͷ�left_,right_
protected:
	//Node* const left_;//��ָ�볣����ָ�뱾���ܸı䣬����ָ�������ڵ�
	//Node* const right_;//ע��ָ�볣����ָ������ָ�����֮�������
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

	double Calc() const;//�����ڵ� ����
private:
	PtrFun pFun_;
};
//class AddNode : public BinaryNode
//{
//public:
//	AddNode(Node* left, Node* right)
//		:BinaryNode(left, right) {}//���û��๹�캯����ʼ��
//	double Calc() const;//��Ҫʵ��
//};
//
//class SubNode : public BinaryNode
//{
//public:
//	SubNode(Node* left, Node* right)
//		:BinaryNode(left, right) {}//���û��๹�캯����ʼ��
//	double Calc() const;//��Ҫʵ��
//};
//
//class MultiplyNode : public BinaryNode
//{
//public:
//	MultiplyNode(Node* left, Node* right)
//		:BinaryNode(left, right) {}//���û��๹�캯����ʼ��
//	double Calc() const;//��Ҫʵ��
//};
//
//class DivideNode : public BinaryNode
//{
//public:
//	DivideNode(Node* left, Node* right)
//		:BinaryNode(left, right) {}//���û��๹�캯����ʼ��
//	double Calc() const;//��Ҫʵ��
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
		//���ﲻ�ܽ� ����ָ��ֱ�ӷŽ�vector�����У��������release()����������ԭ��ָ��Ž���
		positives_.push_back(positive);
	}
	//��AppendChild(�������� ָ������Ȩ�ͷ���
	//vector �������ָ�뱾����û�б���ָ����ָ����ڴ�
	//vector������ָ��ָ����ڴ�Ĺ���
	
	//vector�ڲ�����Ҫ����4���ֽڵ��ڴ棬���ܴ��
	//�ִ��Ĳ���ϵͳ��֧�������ڴ� operator new������ʱ�򣬷����ڴ���ܻ�ʧ��
	//Ҫ�������ָ��node.release()��û���뵽vector�У����ʵͣ�

	~MultipleNode();
protected:
	//std::vector<Node*> childs_;
	ptr_vector<Node> childs_;
	
	//������ʹ������ָ��ʱ ����һ��ԭ��ָ��Node* ������һ���ڴ�й©
	//��vector<>�в���ֱ�Ӵ������ָ��
	//vector������ʱ���ǲ����Զ��ͷ���ָ����ڴ��,��ֻ�����ͷ�ָ���������
	//��� ����ָ���ڴ���ͷ���Ҫ����������������delete  ����~MultipleNode(){...delete *it;..}

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
		assert(left_->IsLvalue());//��������һ����ֵ�ڵ�
	}
	double Calc() const;
};
#endif
