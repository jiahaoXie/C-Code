#include "JApplication.h"
#include"JWindow.h"
#include"JEvent.h"

#include<conio.h>
using namespace JFC;

JApplication* JApplication:: self_=0;
//��̬��Ա��ʼ��

JApplication::JApplication()
{
	if (self_)
		return;

	self_ = this;
	root_ = new JWindow;
	current_ = root_;
}


JApplication::~JApplication()
{
	delete root_;
}

int JApplication::Exec()
{
	//while()ѭ�� �������ռ����¼�
	while (1)
	{
		int key = _getch();	//_getch()�����ͷ�ļ�<conio.h>
		if(current_)
		{//�����ڲ�Ϊ��ʱ�����¼���������������
			JEvent e(key, current_);
			current_->OnKeyEvent(&e);
		}

	}
	return 0;
}