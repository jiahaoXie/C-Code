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
{//ע��Sum()�����Ĳ���Ϊ���ã�������ֵ���Ͳ������ã� �����������Ϊ���õ�Ŀ����Ϊ�����Ч��
	Time sum;
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
	//��Ϊ����ֵ���������á���Ϊ����������һ���µ�Time����Sum��������ʾ��������Time����ĺ͡�
	//�����������ΪTime &�������õĽ���sum����
	//������sum�����Ǿֲ��������ں�������ʱ��ɾ����������ý�ָ��һ�������ڵĶ���
	//ʹ�÷�������Time��ζ�ų�����ɾ��sum֮ǰ�������Ŀ��������ú������õ��ÿ�����
	//ע�⣺��Ҫ����ָ��ֲ�����������ʱ��������á�����ִ����Ϻ󣬾ֲ���������ʱ������ʧ�����ý�ָ�򲻴��ڵ����ݡ�

}

void Time::Show() const
{
	std::cout << "hours: " << hours << "  minutes: " << minutes << std::endl;
}


ostream & operator<<(ostream &os, const Time & t)
{
	os << "hours :" << t.hours << "	 minute: " << t.minutes << endl;
}

