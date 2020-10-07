#include"student.h"
int Student::NoOfStudents=0;

void fn()
{
	Student s1;
	Student s2;
	cout<<Student::number()<<endl;
}
void main()
{
	fn();
	cout<<Student::number()<<endl;
}