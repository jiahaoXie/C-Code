#include <iostream>
using namespace std;
#define LEAFNUM 500        //叶子节点数，也就是权值树
#define HUFNUM 2*LEAFNUM
#define MAXWEIGHT 999.9
//*********存储结构***********
class HufTree;
//***** Node**********
class NODE
{
private:
	//char Data;          //节点的数据域
	double Weight;   //节点的权值域
	int Lchild,Rchild,Parent;   //节点的左孩子右孩子及双亲域
public:
	NODE()            //构造函数
	{
		//Data = '\0';
		Weight = 0;
		Lchild = -1;
		Rchild = -1;
		Parent = -1;        //给节点的数据初始化
	}
	string Data;
	int Re_L(){return Lchild;}
	int Re_R(){return Rchild;}
	//char Re_Data(){return Data;}
	double Re_Weight(){return Weight;}
	friend class HufTree;     //声明友元
};//Node

//********HufTree类**********
class HufTree
{
private:
	int NodeNum;
	NODE HufArry[HUFNUM];//类对象数组
public:
	HufTree(){NodeNum = 0;}
	//void SetHuf(int,double,char);   //设置权值与数据域
	void SetHuf(int);
	void CreatHuf(int );          //创建哈夫曼树
	void SelectMin(int,int&,int&);   //查找哈夫曼树种两个权值最小的树
	void Find_Root_and_Print(int);       //查找树根节点位置
	void PrintHuf(unsigned int,string);          //遍历哈夫曼树
};//huftree