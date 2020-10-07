//Vector容器  值语义
//往容器中插入指针，容器拷贝的只是指针，容器并不负责指针所指向的内存空间的释放
//往容器中插入的是对象，容器拷贝整个对象（容器拷贝的对象与原对象脱离关系）

//利用ptr_vector来负责指针所指向的内存空间的释放

//ptr_vector.h
#ifndef _PTR_VECTOR_H_
#define _PTR_VECTOR_H_

#include <vector>
#include <memory>

//类模板
template <typename T>
class ptr_vector :public std::vector<T*>
{
public:
	~ptr_vector()
	{
		clear();
	}

	void clear()
	{
		std::vector<T*>::iterator it;
		for (it = begin(); it != end(); ++it)
			delete *it;//释放指针指向的内存

		std::vector<T*>::clear();//基类claear()方法仅仅只释放指针变量本身
	}

	void push_back(T* const &val)
	{
		std::auto_ptr<T> ptr(val);       //将val 用auto_ptr接管val所有权
		std::vector<T*>::push_back(val);//operator new  placement new
		ptr.release();//如果内存分配没有出现异常，ptr需要释放所有权
	}

	//还可利用智能指针 插入到向量当中
	void push_back(std::auto_ptr<T>& val)
	{
		std::vector<T*>::push_back(val.get());
		val.release();
	}
};

#endif	//_PTR_VECTOR_H_