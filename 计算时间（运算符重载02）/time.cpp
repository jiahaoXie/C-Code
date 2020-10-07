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
{//ע��Sum()�����Ĳ���Ϊ���ã�������ֵ���Ͳ������ã� �����������Ϊ���õ�Ŀ����Ϊ�����Ч��
	Time sum;
	sum.minutes = minutes+t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
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