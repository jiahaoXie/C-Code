#include<iostream>
using namespace std;
 
class Student
{
public:
	Student(int StudentNo=0)
	{
		cout<<"create one student"<<endl;
		NoOfStudents++;
		StudentNo=100+NoOfStudents;
		cout<<"StudentNo	"<<StudentNo<<endl;
		
	}
	~Student()
	{
		cout<<"destruct one student"<<endl;
		NoOfStudents--;

	}
	static int number()
	{
		return NoOfStudents;
	}
private:
	static int NoOfStudents;
	int StudentNo;
};