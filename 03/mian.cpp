//#include<stdio.h>
//void main()
//{
//	unsigned char i = 7;
//	int j = 0;
//	for (; i > 0; i -= 3)
//	{
//		++j;
//	}
//	printf("j= %d\n",j);
//	while (1) {}
//}

#include<iostream>
using namespace std;

void main(void)
{
	int n;
	char y[10] = "ntse";
	char *x = y;
	n = strlen(x);
	*x = x[n];
	x++;
	printf("x=%s\n", x);
	printf("y=%s\n", y);

	system("pause");
}


//#include<iostream>
//using namespace std;
//void test(int a)
//{
//	cout << "int :" << a << endl;
//}
//void test(float a)
//{
//	cout << "float :" << a << endl;
//}
//void main()
//{
//	test(1);
//	test('d');
//	test(3+'a');
//	//test(0.5);
//
//	system("pause");
//}