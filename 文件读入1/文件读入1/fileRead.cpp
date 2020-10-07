#include <fstream>  
#include <string>  
#include <iostream>  
#include <stdlib.h> 
#include <time.h> 
using namespace std;  
  
int main()  
{  
    ifstream in("E:\\研究生学习\\关键字1.txt");  
    string filename;  
    string line[100];  
	int i=1,j=1,k;
    if(in) // 有该文件  
    {  
        while (getline (in, line[i++])) // line中不包括每行的换行符  
        {   
            cout << line[--i] << '\t';; 
			j++;
			if(j>=100)
				break;
        } 
		cout<<"\n一共有"<<j<<"个关键字\n";
    }  
    else // 没有该文件  
    {  
        cout <<"no such file" << endl;  
    }  

	srand((unsigned)time(NULL));  
	for( k = 0; k < 100;k++ )  
		cout << rand()%150 << '\t';  
	//cout << rand()/double(RAND_MAX) << '\t';	
	cout << "一共有"<<k<<"个权值";
	system("pause");
    return 0;  
}  