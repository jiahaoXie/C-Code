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

// ���ù��λ��
void JWindowsBase::SetCursorPos(SHORT x, SHORT y)
{}

// ˢ�´���
void JWindowsBase::Refresh()
{}

// �����������
void JWindowsBase::FillRect(JRECT rect)
{}

// �����ı���x, y����ڱ����ڵ�λ�ã������������������̨���ڵ�λ�ã�
void JWindowsBase::DrawText(SHORT x, SHORT y, const std::string& text)
{}

// �ڴ������м�����ı�
void JWindowsBase::DrawText(const std::string& text)
{}

// ��ˮƽλ�û���
void JWindowsBase::DrawHLine(SHORT y, SHORT x1, SHORT x2, char ch)
{}

// �ڴ�ֱλ�û���
void JWindowsBase::DrawVLine(SHORT x, SHORT y1, SHORT y2, char ch)
{}

// �������
void JWindowsBase::ClearWindow()
{}
