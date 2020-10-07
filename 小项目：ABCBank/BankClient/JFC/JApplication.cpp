#include "JApplication.h"
#include"JWindow.h"
#include"JEvent.h"

#include<conio.h>
using namespace JFC;

JApplication* JApplication:: self_=0;
//静态成员初始化

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
	//while()循环 用来接收键盘事件
	while (1)
	{
		int key = _getch();	//_getch()需加入头文件<conio.h>
		if(current_)
		{//当窗口不为空时，将事件交给窗口来处理
			JEvent e(key, current_);
			current_->OnKeyEvent(&e);
		}

	}
	return 0;
}