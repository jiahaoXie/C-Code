#ifndef _JWINDOW_H
#define _JWINDOW_H

namespace JFC
{
	class JEvent;

	class JWindow
	{
	public:
		JWindow();
		~JWindow();

		virtual void OnKeyEvent(JEvent* e);
	};
}


#endif	//_JWINDOW_H
