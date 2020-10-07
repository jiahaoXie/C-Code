#include"distance.h"

void main()
{
	Point myp1(1, 1), myp2(4, 5);
	Distance myd(myp1,myp2);
	cout << myd.GetDis() << endl;

	system("pause");
}