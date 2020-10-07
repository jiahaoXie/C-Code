#ifndef _NODE_H_
#define _NODE_H_
class Node
{
public:
	Node();
	~Node();
	void Calc() const;
};
class NodePtr {
public:
	explicit NodePtr(Node* ptr = 0)
		:ptr_(ptr) {}
	//资源进行转移 由ptr转移到ptr_

	NodePtr(NodePtr& other) :ptr_(other.Release()) {}
	
	NodePtr& operator=(NodePtr& other)
	{
		Reset(other.Release());
		return *this;
	}
	~NodePtr() { delete ptr_; }
	
	Node& operator*() const { return *Get(); }
	//重载*运算符
	Node* operator->() const { return Get(); }
	//重载指针运算符
	Node* Get() const { return ptr_; }
	Node* Release()
	{//释放资源的函数
		Node* tmp = ptr_;
		ptr_ = 0;
		return tmp;
	}
	void Reset(Node* ptr = 0)
	{
		if (ptr_ != ptr)
		{
			delete ptr_;
		}
		ptr_ = ptr;
	}
private:
	Node* ptr_;
};
#endif//_NODE_H_
