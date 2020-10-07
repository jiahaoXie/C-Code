
#ifndef _NODE_H_
#define _NODE_H_

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
class AddNode : public BinaryNode
{
public:
	AddNode(Node* left, Node* right)
		:BinaryNode(left, right) {}//���û��๹�캯����ʼ��
	double Calc() const;//��Ҫʵ��
};

class SubNode : public BinaryNode
{
public:
	SubNode(Node* left, Node* right)
		:BinaryNode(left, right) {}//���û��๹�캯����ʼ��
	double Calc() const;//��Ҫʵ��
};

class MultiplyNode : public BinaryNode
{
public:
	MultiplyNode(Node* left, Node* right)
		:BinaryNode(left, right) {}//���û��๹�캯����ʼ��
	double Calc() const;//��Ҫʵ��
};

class DivideNode : public BinaryNode
{
public:
	DivideNode(Node* left, Node* right)
		:BinaryNode(left, right) {}//���û��๹�캯����ʼ��
	double Calc() const;//��Ҫʵ��
};

class UMinusNode : public UnaryNode
{
public:
	UMinusNode(Node* child)
		:UnaryNode(child) {}
	double Calc() const;

};
#endif
