//动态创建对象（简单理解为通过一个字符串得到一个类） 有点类似于Java的反射技术
//运行时动态获取类型信息（方法与属性）
//动态创建对象 动态调用对象的方法  动态操作对象的属性  需要给每个类添加元数据
//动态创建对象  对原有的类不做任何更改，只需要增加一个宏就能实现动态创建
//注：就是为了消除if else
//可以在初始化静态成员变量前面加上__declspec(selectany) ，
//这样编译器会自动剔除对该静态成员的重复定义。

//采用工厂方法来实现对象的动态创建。
//大致原理为，创建一个单例工厂类，其中维护一个map(类名->对象创建函数)。
			//创建对象时，传入类名，然后根据此类名查询出创建函数，最后创建对象。
//采用这种方式，有一个关键问题，便是在工厂中注册类名。
//我们的办法是针对于每一个类(Class)，定义一个注册类(ClassReg)，在注册类(ClassReg)的构造函数中注册此类(Class)，
		//然后再定义一个注册类的全局对象，在该全局对象初始化时，便会执行注册代码完成注册。

//使用宏来替换相应的代码，这样便大大减少了重复代码量。
//采用宏当然可以，但每写完一个类，还要在类后面使用宏来注册，这样确实还是比较麻烦。
//而且这样代码不够美观，也不便于维护，同时采用宏来转换类名，遇到命名空间，嵌套类，会非常麻烦，我们必须在注册的时候，把名字写全，比如REG_CLASS(MyNameSpace::MyClass::MyStruct)。


//更好的办法是我们可以用类模板来实现这种功能。
//设想这种方式，若我们要定义一个类MyClass，并且想让此类支持动态创建，
		//那么我们只需这样定义即可class MyClass : public DynamicCreate<MyClass>{}; 。

#include <stdio.h>  
#include "DynamicFactory.h"  

class Test1 : public DynamicCreate<Test1>
{
public:
	// 注意：使用gcc，一定要显示申明构造函数，否则不会执行注册代码  
	Test1() {}
};

namespace OK {
	struct Test2 : public DynamicCreate<Test2>
	{
		Test2() {}

		class Test3 : public DynamicCreate<Test3>
		{
		public:
			Test3() {}
		};
	};

	struct Test4 : public DynamicCreate<Test4>
	{
		Test4() {}
	};
}

using namespace OK;

//测试代码  
int main()
{
	Test1 * p1 = DynamicFactory::Instance().Create<Test1>("Test1");
	printf("Create Test1 %s\n", (p1 ? "success" : "failure"));

	OK::Test2 * p2 = DynamicFactory::Instance().Create<OK::Test2>("OK::Test2");
	printf("Create OK::Test2 %s\n", (p2 ? "success" : "failure"));

	OK::Test2::Test3 * p3 = DynamicFactory::Instance().Create<OK::Test2::Test3>("OK::Test2::Test3");
	printf("Create OK::Test2::Test3 %s\n", (p3 ? "success" : "failure"));

	OK::Test4 * p4 = DynamicFactory::Instance().Create<OK::Test4>("OK::Test4");
	printf("Create OK::Test4 %s\n", (p4 ? "success" : "failure"));

	system("pause");
	return 0;
}