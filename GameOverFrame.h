#pragma once
#include <wx/wx.h>
#include <wx/glcanvas.h>
#include <wx/stdpaths.h>

class GameOverFrame : public wxFrame {
private:
    int displayedScore;
public:
    void setDisplayedScore(int s) { 
        displayedScore = s; 
    };
    GameOverFrame(const wxString& title, int score)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 200),
            wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX | wxMINIMIZE_BOX)) {
        wxPanel* panel = new wxPanel(this);
        panel->SetBackgroundColour(wxColour(0, 0, 0)); // Set background color to black

        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        wxStaticText* gameOverText = new wxStaticText(panel, wxID_ANY, "Game Over", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
        gameOverText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        gameOverText->SetForegroundColour(wxColour(255, 255, 255)); // Set text color to white
        sizer->Add(gameOverText, 0, wxEXPAND | wxALL, 20);

        panel->SetSizer(sizer);
        Centre();
    }
};