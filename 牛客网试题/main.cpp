//#include<stdio.h>
//void main()
//{
//	int s, i;
//	for (s = 0, i = 1; i < 3;i++, s += i);
//	printf("%d\n",s);
//
//	while (1) {}
//}

//#include<iostream>
//using namespace std;
//
//void main()
//{
//	unsigned char* p1;
//	unsigned long* p2;
//	p1 = (unsigned char *)0x801000;
//	p2 = (unsigned long *)0x810000;
//
//	cout << p1 + 5 << "	" << p2 + 5 << endl;
//	system("pause");
//}

#include<stdio.h>
void main()
{
	int s = 0, n;
	for (n = 0; n < 4; n++)
	{
		switch (n)
		{
		default: s += 4;
		case 1:s += 1; break;
		case 2:s += 2; break;
		case 3:s += 3;
		}
	}
	printf("s= %d\n", s);

	while (1) {}

}