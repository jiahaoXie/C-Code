#include<iostream>
#include"time.h"

void main()
{
	using std::cout;
	using std::endl;

	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time add;
	Time sub;
	Time mul;

	cout << " planning time= ";
	planning.Show();
	cout << endl;

	cout << " coding time= ";
	coding.Show();
	cout << endl;

	cout << " fixing time= ";
	fixing.Show();
	cout << endl;

	//total = coding.Sum(fixing);
	//cout << "coding.Sum(fixing) = ";
	add = coding + fixing;
	cout << " coding+fixing =";
	add.Show();
	cout << endl;

	Time morefixing(11, 20);
	cout << "morefixing =";
	morefixing.Show();
	cout << endl;

	add = add + morefixing;
	cout << " total+ morefixing: ";
	add.Show();

	sub = fixing - coding;
	cout << " fixing - coding :";
	sub.Show();
	cout << endl;

	mul = 5*coding;
	cout << " fixing * 5 :";
	cout << mul;
	/*mul.Show();
	cout << endl;*/

	system("pause");
}
