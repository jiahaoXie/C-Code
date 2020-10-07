#include<iostream>
#include<math.h>

using namespace std;
class Point
{
private:
	float X, Y;
public:
	Point(float xx, float yy)
	{
		cout << "point 构造函数" << endl;
		X = xx;
		Y = yy;
	}
	Point(Point &p)
	{
		X = p.X;
		Y = p.Y;
		cout << "Point 拷贝构造函数" << endl;
	}
	float GetX() { return X; }
	float GetY() { return Y; }

};

class Distance
{
private:
	Point p1, p2;
	double dist;
public:
	Distance(Point a, Point b) :p1(a),p2(b)
	{
		cout << "Distance 构造函数" << endl;
		double x = double(p1.GetX() - p2.GetX());
		double y = double(p1.GetY() - p2.GetY());
		dist = sqrt(x*x + y*y);
	}
	double GetDis() { return dist; }

};

//Distance::Distance(Point a, Point b) :p1(a), p2(b)
//{
//	cout << "Distance 构造函数" << endl;
//	double x = double(p1.GetX() - p2.GetX());
//	double y = double(p1.GetY()-p2.GetY());
//	dist = sqrt(x*x+y*y);
//}
