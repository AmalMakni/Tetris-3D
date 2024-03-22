#include "HelpFrm.h"

HelpFrm::HelpFrm() : wxFrame(nullptr, wxID_ANY, "Help now") {
    SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX | wxMINIMIZE_BOX));
    // Obtenir les dimensions de l'écran
    // Définir la taille et la position de la fenêtre
       // Obtenir les dimensions de l'écran
    int screenWidth = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);
    int screenHeight = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);

    int windowWidth = 800;
    int windowHeight = 800;
    int posX = (screenWidth - windowWidth) / 2;
    int posY = (screenHeight - windowHeight) / 2;
    SetSize(windowWidth, windowHeight);
    SetPosition(wxPoint(posX, posY));
    //windowHeight = 260; windowWidth = 380;


        //Add controls
    wxBitmap bitmap; wxImage image;

    //Creation GUI
    // Dimensions des panneaux
    // Création et positionnement des panneaux individuellement
    panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(GetSize().GetWidth(), GetSize().GetHeight()));
    panel1->SetPosition(wxPoint(0, 0));
    panel1->SetBackgroundColour(wxColor(0, 0, 0));
    

    bitmap.LoadFile("Ressources/Images/sHelpguide.bmp", wxBITMAP_TYPE_BMP);
    if (!bitmap.IsOk()) return;
    image = bitmap.ConvertToImage();
    image.Rescale(350, 300, wxIMAGE_QUALITY_HIGH);
    hButton = new wxBitmapButton(panel1, -1, image, wxPoint(0, 0), wxSize(panel1->GetSize().GetWidth(), panel1->GetSize().GetHeight()), wxCenter);
    hButton->SetToolTip("helps");
   
}

