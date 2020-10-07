#include<iostream>
#include"time.h"

Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m)
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
void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

 Time operator*(double n, const Time &t)
{
	Time result;
	long toatl = t.hours*n * 60 + t.minutes*n;
	result.hours = toatl / 60;
	result.minutes = toatl % 60;

	return result;
}
 Time operator-(const Time & t1, const Time & t2)
{
	Time diff;
	int p1, p2;
	p1 = t1.minutes + 60 * t1.hours;
	p2 = t2.minutes + 60 * t2.hours;
	diff.hours = (p2 - p1) / 60;
	diff.minutes = (p2 - p1) % 60;

	return diff;
}
//Time Time:: Sum(const Time & t) const
 Time operator+(const Time & t1, const Time & t2)
{//注意Sum()函数的参数为引用，但返回值类型不是引用！ 这里参数声明为引用的目的是为了提高效率
	Time sum;
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
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


ostream & operator<<(ostream &os, const Time & t)
{
	os << "hours :" << t.hours << "	 minute: " << t.minutes << endl;
}

