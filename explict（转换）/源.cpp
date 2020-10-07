//ת������������͵�ֵ����ĳ�����͵���ֵ�� 
//��׼ת�������� C++ ���Բ�֧�����������ͣ�����Դ����û������ת������ת�����û���������͡�����Щ����ת����������Щ����֮��ִ��ת����
//ת����������ʽ��������Աͨ�����ô�һ������ת��Ϊ��һ������ʱ������ǿ��ת����ֱ�ӳ�ʼ�����������Ҳ��������ʽ�������Ի��������������Ͷ��ǳ���Ա����������ʱ����

//explicit �ؼ��ֻ�֪ͨ������ָ����ת����������ִ����ʽת����
//����ʹ�� explicit �ؼ��֣�����Դ�������ת��������ֻ������ִ����ʽǿ��ת����ֱ�ӳ�ʼ�������Ҳ��ᵼ�¡���ȫ Bool ���⡱�о���˵�����������͡�


#include <iostream>  

class Money
{
public:
	Money() : amount{ 0.0 } {};
	explicit Money(double _amount) : amount{ _amount } {};
	//ͨ����ת�����캯������Ϊ explicit����ֻ������ִ�ж����ֱ�ӳ�ʼ����ִ����ʽǿ��ת���� �⽫��ֹ���������͵Ĳ����ĺ���ͬ����ʽ����ת�����캯����Դ���͵Ĳ��������ҽ���ֹ�Ӹ�Դ���͵�ֵ���Ƴ�ʼ��������͡�
	double amount;
};

void display_balance(const Money balance)
{
	std::cout << "The balance is: " << balance.amount << std::endl;
}

int main(int argc, char* argv[])
{
	Money payable{ 79.99 };

	display_balance(payable);
	display_balance((Money)49.95);
	display_balance((Money)9.99f);

	system("pause");
	return 0;
}
