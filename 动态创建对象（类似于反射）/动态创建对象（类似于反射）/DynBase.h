#ifndef _DYN_BASE_H_  
#define _DYN_BASE_H_  
//用来绑定字符串和对应的  
#include <map>  
#include <string>  
using namespace std;

typedef void* (*CREATE_FUNC)();

class DynObjectFactory
{
public:
	//因为是工具类，所以设置为静态函数  
	static void* CreateObject(const string& name)
	{
		//CREATE_FUNC是一个函数指针 他的返回值是空指针  
		map<string, CREATE_FUNC>::const_iterator it;
		it = mapCls_.find(name);
		if (it == mapCls_.end())
			return 0;
		else
			return it->second();

	}

	static void Register(const string& name, CREATE_FUNC func)
	{
		//是可以访问静态成员私有变量的  
		mapCls_[name] = func;
	}
private:
	static map<string, CREATE_FUNC> mapCls_;
};

// g++  
// __attribute ((weak))  
//静态成员初始化一次   通过假如关键字来进行实现  
__declspec(selectany) map<string, CREATE_FUNC> DynObjectFactory::mapCls_;

/*此类是一个间接的存在，*/
//class Register
//{
//public:
//	Register(const string& name, CREATE_FUNC func)
//	{
//		DynObjectFactory::Register(name, func);
//	}
//};

//如何在注册的时候就加入到工厂中的产品中  
//通过定义一个static变量  
//就可以对其进行初始化  
//而这个static变量又要如何进行改变呢，那就要求用一个类来封装之前的函数  

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
//	//必须紧紧的连在class_name后面  

//使用类模板来引发注册 
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