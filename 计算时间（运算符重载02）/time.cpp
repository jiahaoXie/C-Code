#include<iostream>
#include"time.h"

Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m )
{
	hours = h;
	minutes = m;
}
void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes = minutes % 60;
}
void Time::AddHr(int h)
{
	hours += h;
}
void Time::Reset(int h , int m)
{
	hours = h;
	minutes = m;
}
Time Time::operator*(double n)const
{
	Time result;
	long toatl = hours*n * 60 + minutes*n;
	result.hours = toatl / 60;
	result.minutes = toatl % 60;

	return result;
}
Time Time::operator-(const Time & t)const
{
	Time diff;
	int t1, t2;
	t1 = t.minutes + 60 * t.hours;
	t2 = minutes + 60 * hours;
	diff.hours = (t2 - t1) / 60;
	diff.minutes = (t2 - t1) % 60;

	return diff;
}
//Time Time:: Sum(const Time & t) const
Time Time::operator+(const Time & t) const
{//注意Sum()函数的参数为引用，但返回值类型不是引用！ 这里参数声明为引用的目的是为了提高效率
	Time sum;
	sum.minutes = minutes+t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
	//因为返回值不能是引用。因为函数将创建一个新的Time对象（Sum），来表示另外两个Time对象的和。
	//如果返回类型为Time &。则将引用的将是sum对象。
	//但由于sum对象是局部变量，在函数结束时被删除，因此引用将指向一个不存在的对象。
	//使用返回类型Time意味着程序将在删除sum之前构造它的拷贝，调用函数将得到该拷贝！
	//注意：不要返回指向局部变量或者临时对象的引用。函数执行完毕后，局部变量和临时对象将消失，引用将指向不存在的数据。

}

void Time::Show() const
{
	std::cout << "hours: " << hours << "  minutes: " << minutes << std::endl;
}