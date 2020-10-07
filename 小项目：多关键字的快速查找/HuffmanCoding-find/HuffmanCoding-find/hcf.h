#include <iostream>
using namespace std;
#define LEAFNUM 500        //Ҷ�ӽڵ�����Ҳ����Ȩֵ��
#define HUFNUM 2*LEAFNUM
#define MAXWEIGHT 999.9
//*********�洢�ṹ***********
class HufTree;
//***** Node**********
class NODE
{
private:
	//char Data;          //�ڵ��������
	double Weight;   //�ڵ��Ȩֵ��
	int Lchild,Rchild,Parent;   //�ڵ�������Һ��Ӽ�˫����
public:
	NODE()            //���캯��
	{
		//Data = '\0';
		Weight = 0;
		Lchild = -1;
		Rchild = -1;
		Parent = -1;        //���ڵ�����ݳ�ʼ��
	}
	string Data;
	int Re_L(){return Lchild;}
	int Re_R(){return Rchild;}
	//char Re_Data(){return Data;}
	double Re_Weight(){return Weight;}
	friend class HufTree;     //������Ԫ
};//Node

//********HufTree��**********
class HufTree
{
private:
	int NodeNum;
	NODE HufArry[HUFNUM];//���������
public:
	HufTree(){NodeNum = 0;}
	//void SetHuf(int,double,char);   //����Ȩֵ��������
	void SetHuf(int);
	void CreatHuf(int );          //������������
	void SelectMin(int,int&,int&);   //���ҹ�������������Ȩֵ��С����
	void Find_Root_and_Print(int);       //���������ڵ�λ��
	void PrintHuf(unsigned int,string);          //������������
};//huftree