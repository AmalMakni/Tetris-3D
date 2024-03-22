#pragma once
#ifndef HELPUI_H
#define HELPUI_H

#include <wx/wx.h>


class HelpUI:wxFrame
{
public:
private:
    wxPanel* panel1 = NULL, * panel2 = NULL, * panel21 = NULL, * panel22 = NULL, * panel23 = NULL, * panel3 = NULL;
    wxStaticText* best1Label = NULL, * best2Label = NULL, * best3Label = NULL;
    wxBitmapButton* podiumHighButton = NULL;
};

#endif // HELPUI_H

