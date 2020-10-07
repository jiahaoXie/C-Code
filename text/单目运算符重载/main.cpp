#include<iostream>
using namespace std;

class Clock {
public:
	Clock(int NewH = 0, int NewM = 0, int NewS = 0)
	{
		Hour = NewH;
		Minute = NewM;
		Second = NewS;
	}
	void ShowTime()
	{
		cout << "Time "<<Hour << ":" << Minute << ":" << Second << endl;
	}
	void operator++();//前置单目运算符i++重载
	void operator++(int);//后置单目运算符++i重载
	//二者 实质上为函数重载

	void GetH()
	{
		cin >> Hour;
		//scanf_s("%d", &Hour);
	}
	void GetM()
	{
		cin >> Minute;
		//scanf_s("%d", &Minute);
	}
	void GetS()
	{
		cin >> Second;
		//scanf_s("%d", &Second);
	}
private:
	int Hour, Minute, Second;
};

void Clock::operator++()
{
	++Second;
	if (Second >= 60)
	{
		Second -= 60;
		Minute++;
		if (Minute >= 60)
		{
			Minute -= 60;
			Hour++;
			Hour = Hour % 24;
		}
	}
	cout << "++Clock ";
}

void Clock::operator++(int )
{
	Second++;
	if (Second >= 60)
	{
		Second -= 60;
		Minute++;
		if (Minute >= 60)
		{
			Minute -= 60;
			Hour++;
			Hour = Hour % 24;
		}
	}
	cout << "Clock++ ";
}

void main()
{
	//Clock myClock(23, 59, 59);

	//这里也可以动态输入时钟的初始值！
	Clock myClock;
	myClock.GetH();
	myClock.GetM();
	myClock.GetS();

	cout << "the First time: ";
	myClock.ShowTime();

	myClock++;
	myClock.ShowTime();

	++myClock;
	myClock.ShowTime();

	system("pause");
}