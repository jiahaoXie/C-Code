#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
using namespace std;  

//����һ ����rand()��������Ϊ���������ĳ����Ϊ��׼ �������������ֵ��
int main() 
{  
	srand((unsigned)time(NULL));  
	for(int i = 0; i < 100;i++ )  
		cout << rand()%150 << '\t';  
	//cout << rand()/double(RAND_MAX) << '\t';	
	cout << endl; 
	system("pause");
	return 0; 
}
/*
int main(){
	int i,a[100];
	for(i=0; i<=99; ++i) a[i]=i;
	for(i=99; i>=1; --i) swap(a[i], a[rand()%i]);
	for(i=0;i<=99;i++)
		cout<<a[i]<<'\t';
	system("pause");
}*/
