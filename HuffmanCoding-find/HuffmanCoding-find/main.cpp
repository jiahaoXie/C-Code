#include"hcf.h"

int n;
int main()
{
	HufTree Tree;
	//cout<<"������"<<LEAFNUM<<"��(Ȩֵ,����):"<<endl;
	
	cout<<"please input n=";
	cin>>n;
	Tree.SetHuf(n);
	Tree.CreatHuf(n);     //������������
	Tree.Find_Root_and_Print(n);           //������������
	system("pause");
	return 0;
}