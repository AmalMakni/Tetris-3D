#pragma once
#include <wx/wx.h>
class HelpFrm : public wxFrame
{
public:
	HelpFrm();
private:
	wxPanel* panel1 = NULL;
	wxBitmapButton* hButton = NULL;
};

