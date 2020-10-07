#include <iostream>  
#include "Shape.h"  
#include "DynBase.h"  

using namespace std;


void Circle::Draw()
{
	cout << "Circle::Draw() ..." << endl;
}
Circle::~Circle()
{
	cout << "~Circle ..." << endl;
}

void Square::Draw()
{
	cout << "Square::Draw() ..." << endl;
}
Square::~Square()
{
	cout << "~Square ..." << endl;
}



void Rectangle::Draw()
{
	cout << "Rectangle::Draw() ..." << endl;
}

Rectangle::~Rectangle()
{
	cout << "~Rectangle ..." << endl;
}

//利用宏定义进行注册   宏是一个非常强大的工具  利用此方法可以用来注册  
REGISTER_CLASS(Circle);
REGISTER_CLASS(Square);
REGISTER_CLASS(Rectangle);