//Vector����  ֵ����
//�������в���ָ�룬����������ֻ��ָ�룬������������ָ����ָ����ڴ�ռ���ͷ�
//�������в�����Ƕ����������������������������Ķ�����ԭ���������ϵ��

//����ptr_vector������ָ����ָ����ڴ�ռ���ͷ�

//ptr_vector.h
#ifndef _PTR_VECTOR_H_
#define _PTR_VECTOR_H_

#include <vector>
#include <memory>

//��ģ��
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
			delete *it;//�ͷ�ָ��ָ����ڴ�

		std::vector<T*>::clear();//����claear()��������ֻ�ͷ�ָ���������
	}

	void push_back(T* const &val)
	{
		std::auto_ptr<T> ptr(val);       //��val ��auto_ptr�ӹ�val����Ȩ
		std::vector<T*>::push_back(val);//operator new  placement new
		ptr.release();//����ڴ����û�г����쳣��ptr��Ҫ�ͷ�����Ȩ
	}

	//������������ָ�� ���뵽��������
	void push_back(std::auto_ptr<T>& val)
	{
		std::vector<T*>::push_back(val.get());
		val.release();
	}
};

#endif	//_PTR_VECTOR_H_