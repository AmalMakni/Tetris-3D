#include "helpUI.h"

/*HelpUI::HelpUI(void) : wxFrame(nullptr, wxID_ANY, "High Scores Podium") {

    SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX | wxMINIMIZE_BOX));
    // Obtenir les dimensions de l'écran
    int screenWidth = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);
    int screenHeight = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);
    //int x = 1920, y = 1080; //GetClientSize(&x, &y);

    // Définir la taille et la position de la fenêtre
    int windowWidth = 800;
    int windowHeight = 600;
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
    panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(windowWidth, windowHeight / 3.0));
    panel1->SetPosition(wxPoint(0, 0));
    panel1->SetBackgroundColour(wxColor(0, 255, 255));

    best1Label = new wxStaticText(panel1, wxID_ANY, "le score :", wxDefaultPosition, wxSize(windowWidth / 3.0, windowHeight / 3.0), wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);
    best1Label->SetPosition(wxPoint(windowWidth / 3.0, 0));
    best1Label->SetLabelText("\n\n\nHadha\Eddamdoum\nFihom 3");

    panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(windowWidth, windowHeight / 3.0));
    panel2->SetPosition(wxPoint(0, windowHeight / 3.0));
    panel2->SetBackgroundColour(wxColor(0, 255, 255));

    panel21 = new wxPanel(panel2, wxID_ANY, wxDefaultPosition, wxSize(windowWidth / 3.0, windowHeight / 3.0));
    panel21->SetPosition(wxPoint(0, 0));
    panel21->SetBackgroundColour(wxColor(0, 255, 255));

    best2Label = new wxStaticText(panel21, wxID_ANY, "le score :", wxDefaultPosition, wxSize(windowWidth / 3.0, windowHeight / 3.0), wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);
    best2Label->SetPosition(wxPoint(0, 0));
    best2Label->SetLabelText("\n\n\nHadha\Lemzammar\nFihom 3");



    panel22 = new wxPanel(panel2, wxID_ANY, wxDefaultPosition, wxSize(windowWidth / 3.0, windowHeight / 3.0));
    panel22->SetPosition(wxPoint(windowWidth / 3.0, 0));
    panel22->SetBackgroundColour(wxColor(0, 255, 255));


    bitmap.LoadFile("Ressources/Images/podiumHaut.bmp", wxBITMAP_TYPE_BMP);
    if (!bitmap.IsOk()) return;
    image = bitmap.ConvertToImage();
    image.Rescale(windowWidth / 3.0, windowHeight / 3.0, wxIMAGE_QUALITY_HIGH);
    podiumHighButton = new wxBitmapButton(panel22, -1, image, wxPoint(0, 0), wxSize(windowWidth / 3.0, windowHeight / 3.0), 0);
    podiumHighButton->SetToolTip("Podium");


    panel23 = new wxPanel(panel2, wxID_ANY, wxDefaultPosition, wxSize(windowWidth / 3.0, windowHeight / 3.0));
    panel23->SetPosition(wxPoint(windowWidth * 2 / 3.0, 0));
    panel23->SetBackgroundColour(wxColor(0, 255, 255));


    best3Label = new wxStaticText(panel23, wxID_ANY, "le score :", wxDefaultPosition, wxSize(windowWidth / 3.0, windowHeight / 3.0), wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);
    best3Label->SetPosition(wxPoint(0, 0));
    best3Label->SetLabelText("\n\n\nHadha\Lemetwasset\nFihom 3");



    panel3 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(windowWidth, windowHeight / 3.0));
    panel3->SetPosition(wxPoint(0, windowHeight * 2 / 3.0));
    panel3->SetBackgroundColour(wxColor(0, 255, 255));


    bitmap.LoadFile("Ressources/Images/podiumBase.bmp", wxBITMAP_TYPE_BMP);
    if (!bitmap.IsOk()) return;
    image = bitmap.ConvertToImage();
    image.Rescale(windowWidth, windowHeight / 3.0, wxIMAGE_QUALITY_HIGH); // Redimensionner l'image à 200x200
    podiumHighButton = new wxBitmapButton(panel3, -1, image, wxPoint(0, 0), wxSize(windowWidth, windowHeight / 3.0), 0);
    podiumHighButton->SetToolTip("Podium");

    Show(true);
}*/
