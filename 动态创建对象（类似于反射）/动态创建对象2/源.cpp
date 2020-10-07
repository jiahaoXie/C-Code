//��̬�������󣨼����Ϊͨ��һ���ַ����õ�һ���ࣩ �е�������Java�ķ��似��
//����ʱ��̬��ȡ������Ϣ�����������ԣ�
//��̬�������� ��̬���ö���ķ���  ��̬�������������  ��Ҫ��ÿ�������Ԫ����
//��̬��������  ��ԭ�е��಻���κθ��ģ�ֻ��Ҫ����һ�������ʵ�ֶ�̬����
//ע������Ϊ������if else
//�����ڳ�ʼ����̬��Ա����ǰ�����__declspec(selectany) ��
//�������������Զ��޳��Ըþ�̬��Ա���ظ����塣

//���ù���������ʵ�ֶ���Ķ�̬������
//����ԭ��Ϊ������һ�����������࣬����ά��һ��map(����->���󴴽�����)��
			//��������ʱ������������Ȼ����ݴ�������ѯ��������������󴴽�����
//�������ַ�ʽ����һ���ؼ����⣬�����ڹ�����ע��������
//���ǵİ취�������ÿһ����(Class)������һ��ע����(ClassReg)����ע����(ClassReg)�Ĺ��캯����ע�����(Class)��
		//Ȼ���ٶ���һ��ע�����ȫ�ֶ����ڸ�ȫ�ֶ����ʼ��ʱ�����ִ��ע��������ע�ᡣ

//ʹ�ú����滻��Ӧ�Ĵ��룬��������������ظ���������
//���ú굱Ȼ���ԣ���ÿд��һ���࣬��Ҫ�������ʹ�ú���ע�ᣬ����ȷʵ���ǱȽ��鷳��
//�����������벻�����ۣ�Ҳ������ά����ͬʱ���ú���ת�����������������ռ䣬Ƕ���࣬��ǳ��鷳�����Ǳ�����ע���ʱ�򣬰�����дȫ������REG_CLASS(MyNameSpace::MyClass::MyStruct)��


//���õİ취�����ǿ�������ģ����ʵ�����ֹ��ܡ�
//�������ַ�ʽ��������Ҫ����һ����MyClass���������ô���֧�ֶ�̬������
		//��ô����ֻ���������弴��class MyClass : public DynamicCreate<MyClass>{}; ��

#include <stdio.h>  
#include "DynamicFactory.h"  

class Test1 : public DynamicCreate<Test1>
{
public:
	// ע�⣺ʹ��gcc��һ��Ҫ��ʾ�������캯�������򲻻�ִ��ע�����  
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

//���Դ���  
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