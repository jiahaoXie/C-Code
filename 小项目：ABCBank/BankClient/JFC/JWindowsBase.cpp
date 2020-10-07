#include "JWindowsBase.h"

using namespace JFC;

JWindowsBase::ScreenBUffer JWindowsBase::sb_;
JWindowsBase::JWindowsBase():x_(0),y_(0),width_(0),height_(0)
{

}
JWindowsBase::JWindowsBase(SHORT x,SHORT y,SHORT width,SHORT height) 
	:x_(x), y_(y), width_(width), height_(height),fColor_(FCOLOR_BLACK),bColor_(BCOLOR_WHITE)
{

}

JWindowsBase::~JWindowsBase()
{
}

// 设置光标位置
void JWindowsBase::SetCursorPos(SHORT x, SHORT y)
{}

// 刷新窗口
void JWindowsBase::Refresh()
{}

// 清除矩形区域
void JWindowsBase::FillRect(JRECT rect)
{}

// 绘制文本（x, y相对于本窗口的位置，并不是相对整个控制台窗口的位置）
void JWindowsBase::DrawText(SHORT x, SHORT y, const std::string& text)
{}

// 在窗口正中间绘制文本
void JWindowsBase::DrawText(const std::string& text)
{}

// 在水平位置画线
void JWindowsBase::DrawHLine(SHORT y, SHORT x1, SHORT x2, char ch)
{}

// 在垂直位置画线
void JWindowsBase::DrawVLine(SHORT x, SHORT y1, SHORT y2, char ch)
{}

// 清除窗口
void JWindowsBase::ClearWindow()
{}
