#include <ctype.h>
#include <iostream>
using namespace std;
int main()
{
	int i;
	char str[] = "123c     @# FD\tsP[e?\n";
	for (i = 0; str[i] != 0; i++)
	{
		//if (isspace(str[i]))//Êä³ö¿Õ¸ñ
		//	printf("str[%d] is a white-space character:%d\n", i, str[i]);
		if (!isspace(str[i]))
			cout << str[i];
	}
	cout << endl;
	system("pause");
}