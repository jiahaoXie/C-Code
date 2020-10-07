#ifndef _TIME_H
#define _TIME_H

class Time {
private:
	int hours, minutes;
public:
	Time();
	Time(int h,int m=0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator*(double n)const;
	Time operator-(const Time & t)const;
	Time operator+(const Time & t) const;
	//Time Sum(const Time & t) const;
			//将Sum()函数 改为operator+() 即变成重载函数
	void Show() const;
};
//注意：类的成员函数中参数如果有默认参数，在成员函数定义时 并需要写默认参数
#endif //_TIME_H