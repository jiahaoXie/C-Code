//数据输入输出的格式化 使用系统头文件<iomanip>

#include<iostream>
#include<iomanip>

using namespace std;
//这里通过操作子方式进行格式化输出 当然也可以以成员函数方式进行格式化输出
//宽度控制 对齐控制 填充控制 精度控制 进制输出
void main()
{
	int n = 100;
	double d = 12.345;
	double d2 = 234.4567;
	cout << "=============宽度控制==================" << endl;
	//宽度控制利用到setw()方法 例如setw(10)表示每个数据占10位
	cout << n << "#" << endl;
	cout << setw(10) << n << "#" << endl;
	//注意：宽度控制不会影响下一次输出

	cout << "=============对齐控制==================" << endl;
	//系统内部默认情况下 为右对齐
	cout << setw(10) << setiosflags(ios::left) << n << "#" << endl;
	//setiosflags(ios::left)这里设置为左对齐
	cout << setw(10) << resetiosflags(ios::left) << n << "#" << endl;
	//resetiosflags(ios::left)撤销左对齐的操作 则系统恢复默认值右对齐
	//注意：对齐控制会影响下一次输出

	cout << "=============填充控制==================" << endl;
	cout << setw(10) <<setfill('!') << n << "#" << endl;
	//填充操作 系统默认为空格 填充，这里setfill('!')设置为感叹号填充
	//注意：填充控制会影响下一次输出

	cout << "=============精度控制==================" << endl;
	cout << setprecision(4) << d << endl;
	cout << setprecision(6) << d2 << endl;
	//setprecision(n)这里表示设置有效数字为n位 输出

	//若要设置成小数点后几位精度输出，则加上cout << setiosflags(ios::fixed);
	cout << setiosflags(ios::fixed);
	cout << setprecision(4) << d << endl;
	cout << setprecision(6) << d2 << endl;

	cout << "=============进制输出==================" << endl;
	cout << setiosflags(ios::showbase);//ios::showbase表示输出时 显示进制的前缀
	cout << n << endl;
	cout << oct << n << endl;
	cout << hex << n << endl;

	system("pause");
}