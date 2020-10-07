#ifndef _JAPPLICATION_H
#define _JAPPLICATION_H
namespace JFC
{
	class  JWindow;
	//作为一种特殊的单例模式 
	class JApplication
	{
	public:
		JApplication();
		~JApplication();

		static JApplication* Instance() { return self_; }
		JWindow* GetCurrent() const { return current_; }
		JWindow* SetCurrent(JWindow* win) { current_ = win; }
		JWindow* Root() const { return root_; }

		int Exec();	//消息循环
	private:
		static JApplication* self_;
		JWindow* current_;		// 当前接收按键的窗口
		JWindow* root_;			// 根
	};

}
#define jApp JApplication::Instance()

#endif //_JAPPLICATION_H
