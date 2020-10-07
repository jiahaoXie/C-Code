
#ifndef _NODE_H_
#define _NODE_H_
#include<vector>
#include<cassert>
class Storage;
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
	BinaryNode(Node* left, Node* right)
		: left_(left), right_(right) {}
	~BinaryNode();//��Ҫ�ͷ�left_,right_
protected:
	Node* const left_;//��ָ�볣����ָ�뱾���ܸı䣬����ָ�������ڵ�
	Node* const right_;//ע��ָ�볣����ָ������ָ�����֮�������

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
	UMinusNode(Node* child)
		:UnaryNode(child) {}
	double Calc() const;

};
class MultipleNode : public Node
{
public:
	MultipleNode(Node* node)
	{
		AppendChild(node, true);
	}
	void AppendChild(Node* node, bool positive)
	{
		childs_.push_back(node);
		positives_.push_back(positive);
	}
	~MultipleNode();
protected:
	std::vector<Node*> childs_;
	std::vector<bool> positives_;
};


class SumNode : public MultipleNode
{
public:
	SumNode(Node* node)
		: MultipleNode(node) {}
	double Calc() const;
};


class ProductNode : public MultipleNode
{
public:
	ProductNode(Node* node)
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
	AssignNode(Node* left, Node* right)
		: BinaryNode(left, right)
	{
		assert(left->IsLvalue());//�϶�����һ����ֵ�ڵ�
	}
	double Calc() const;
};
#endif
