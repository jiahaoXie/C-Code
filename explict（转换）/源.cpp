//转换会从其他类型的值生成某个类型的新值。 
//标准转换内置于 C++ 语言并支持其内置类型，你可以创建用户定义的转换，以转换到用户定义的类型、从这些类型转换或者在这些类型之间执行转换。
//转换可以是显式（当程序员通过调用从一个类型转换为另一个类型时，例如强制转换或直接初始化的情况），也可以是隐式（当语言或程序调用其他类型而非程序员给定的类型时）。

//explicit 关键字会通知编译器指定的转换不能用于执行隐式转换。
//现在使用 explicit 关键字，你可以创建简便的转换，它们只能用于执行显式强制转换或直接初始化，并且不会导致“安全 Bool 问题”中举例说明的问题类型。


#include <iostream>  

class Money
{
public:
	Money() : amount{ 0.0 } {};
	explicit Money(double _amount) : amount{ _amount } {};
	//通过将转换构造函数声明为 explicit，它只能用于执行对象的直接初始化或执行显式强制转换。 这将阻止接受类类型的参数的函数同样隐式接受转换构造函数的源类型的参数，并且将阻止从该源类型的值复制初始化类的类型。
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
