#include <fstream>  
#include <string>  
#include <iostream>  
#include <stdlib.h> 
#include <time.h> 
using namespace std;  
  
int main()  
{  
    ifstream in("E:\\�о���ѧϰ\\�ؼ���1.txt");  
    string filename;  
    string line[100];  
	int i=1,j=1,k;
    if(in) // �и��ļ�  
    {  
        while (getline (in, line[i++])) // line�в�����ÿ�еĻ��з�  
        {   
            cout << line[--i] << '\t';; 
			j++;
			if(j>=100)
				break;
        } 
		cout<<"\nһ����"<<j<<"���ؼ���\n";
    }  
    else // û�и��ļ�  
    {  
        cout <<"no such file" << endl;  
    }  

	srand((unsigned)time(NULL));  
	for( k = 0; k < 100;k++ )  
		cout << rand()%150 << '\t';  
	//cout << rand()/double(RAND_MAX) << '\t';	
	cout << "һ����"<<k<<"��Ȩֵ";
	system("pause");
    return 0;  
}  