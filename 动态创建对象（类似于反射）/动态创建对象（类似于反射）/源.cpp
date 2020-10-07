//��̬�������󣨼����Ϊͨ��һ���ַ����õ�һ���ࣩ �е�������Java�ķ��似��
//����ʱ��̬��ȡ������Ϣ�����������ԣ�
//
//��̬��������
//��̬���ö���ķ���
//��̬�������������
//
//��Ҫ��ÿ�������Ԫ����
//
//��̬��������
//��ԭ�е��಻���κθ��ģ�ֻ��Ҫ����һ�������ʵ�ֶ�̬����
//ע������Ϊ������if else
//�����ڳ�ʼ����̬��Ա����ǰ�����__declspec(selectany) ��
		//�������������Զ��޳��Ըþ�̬��Ա���ظ����塣

#include "Shape.h"  
#include "DynBase.h"  
#include <iostream>  
#include <vector>  
#include <string>  
using namespace std;



void DrawAllShapes(const vector<Shape*>& v)
{
	vector<Shape*>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		(*it)->Draw();
	}
}

void DeleteAllShapes(const vector<Shape*>& v)
{
	vector<Shape*>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		delete(*it);
	}
}


int main(void)
{
	vector<Shape*> v;

	Shape* ps;
	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Circle"));
	v.push_back(ps);
	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Square"));
	v.push_back(ps);
	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Rectangle"));
	v.push_back(ps);

	DrawAllShapes(v);
	DeleteAllShapes(v);

	system("pause");
	return 0;
}