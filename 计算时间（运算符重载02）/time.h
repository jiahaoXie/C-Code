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
			//��Sum()���� ��Ϊoperator+() ��������غ���
	void Show() const;
};
//ע�⣺��ĳ�Ա�����в��������Ĭ�ϲ������ڳ�Ա��������ʱ ����ҪдĬ�ϲ���
#endif //_TIME_H