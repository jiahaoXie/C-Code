#ifndef _DYN_BASE_H_  
#define _DYN_BASE_H_  
//�������ַ����Ͷ�Ӧ��  
#include <map>  
#include <string>  
using namespace std;

typedef void* (*CREATE_FUNC)();

class DynObjectFactory
{
public:
	//��Ϊ�ǹ����࣬��������Ϊ��̬����  
	static void* CreateObject(const string& name)
	{
		//CREATE_FUNC��һ������ָ�� ���ķ���ֵ�ǿ�ָ��  
		map<string, CREATE_FUNC>::const_iterator it;
		it = mapCls_.find(name);
		if (it == mapCls_.end())
			return 0;
		else
			return it->second();

	}

	static void Register(const string& name, CREATE_FUNC func)
	{
		//�ǿ��Է��ʾ�̬��Ա˽�б�����  
		mapCls_[name] = func;
	}
private:
	static map<string, CREATE_FUNC> mapCls_;
};

// g++  
// __attribute ((weak))  
//��̬��Ա��ʼ��һ��   ͨ������ؼ���������ʵ��  
__declspec(selectany) map<string, CREATE_FUNC> DynObjectFactory::mapCls_;

/*������һ����ӵĴ��ڣ�*/
//class Register
//{
//public:
//	Register(const string& name, CREATE_FUNC func)
//	{
//		DynObjectFactory::Register(name, func);
//	}
//};

//�����ע���ʱ��ͼ��뵽�����еĲ�Ʒ��  
//ͨ������һ��static����  
//�Ϳ��Զ�����г�ʼ��  
//�����static������Ҫ��ν��иı��أ��Ǿ�Ҫ����һ��������װ֮ǰ�ĺ���  

//#define REGISTER_CLASS(class_name) \
//
//class class_name##Register
//{ \
//	public: \
//		static void* NewInstance() \
//	{ \
//		return new class_name; \
//	} \
//private: \
//	static Register reg_; \
//}; \
//
//Register class_name##Register::reg_(#class_name, class_name##Register::NewInstance)
//	//�������������class_name����  

//ʹ����ģ��������ע�� 
template <typename T>
class DelegatingClass
{
public:
	DelegatingClass(const string& name)
	{
		DynObjectFactory::Register(name,&(DelegatingClass::NewInstance));
	}
	static void* NewInstance()
	{
		return new T;

	}
};

#define REGISTER_CLASS(class_name) DelegatingClass<class_name> class##class_name(#class_name)
#endif // _DYN_BASE_H_  