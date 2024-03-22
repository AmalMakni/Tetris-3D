#ifndef PODIUMUI_H
#define PODIUMUI_H

#include <wx/wx.h>

class PodiumUI :wxFrame
{
public:
    PodiumUI(void);
    void setBest1Score(wxString bs);
    void setBest2Score(wxString bs);
    void setBest3Score(wxString bs);
private:
    wxPanel* panel1=NULL, * panel2 = NULL, * panel21 = NULL, * panel22 = NULL, * panel23 = NULL, * panel3 = NULL;
    wxStaticText* best1Label = NULL, * best2Label = NULL, * best3Label = NULL;
    wxBitmapButton* podiumHighButton = NULL;
};

#endif // PODIUMUI_H


