#include"hcf.h"

int n;
int main()
{
	HufTree Tree;
	//cout<<"请输入"<<LEAFNUM<<"对(权值,数据):"<<endl;
	
	cout<<"please input n=";
	cin>>n;
	Tree.SetHuf(n);
	Tree.CreatHuf(n);     //创建哈夫曼树
	Tree.Find_Root_and_Print(n);           //遍历哈夫曼树
	system("pause");
	return 0;
}