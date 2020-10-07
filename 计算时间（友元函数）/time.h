#ifndef _TIME_H
#define _TIME_H

using std::ostream;
using std::endl;
class Time {
private:
	int hours, minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	friend Time operator*(double n,const Time &t);
	friend Time operator-(const Time & t1, const Time & t2);
	friend Time operator+(const Time & t1, const Time & t2) ;
	friend ostream & operator<<( ostream &os, const Time & t);
	//Time Sum(const Time & t) const;
	//��Sum()���� ��Ϊoperator+() ��������غ���
	void Show() const;
};
//ע�⣺��ĳ�Ա�����в��������Ĭ�ϲ������ڳ�Ա��������ʱ ����ҪдĬ�ϲ���
#endif //_TIME_H

