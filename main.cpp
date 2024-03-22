#pragma once

#include <wx/wx.h>
#include "GameMusicBox.h"
#include <wx/glcanvas.h>
#include <wx/stdpaths.h>

#include <math.h>

#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "podium.h"
#include "helpUI.h"
#include "ElemCube.h"
#include "LongPiece.h"
#include "Grid.h"
#include "T.h"
#include "S.h"
#include "O.h"
#include "L.h"
#include "GameOverFrame.h"
#include "Menu.h"

//Mange Sound with the audio console
GameMusicBox* gmb;

//Ptr to enable interaction with GLFW from Wx UI  
GLFWwindow* window;


//by Amal
//3D Tetris POC - openGL

#define SCREEN_WIDTH 1500//640*2
#define SCREEN_HEIGHT 1080//480*2
#define WAIT_TIME 3
#define MAX_LOADSTRING 100
#define GRID_SPACING 75

class Menu {
public:
    void drawPauseMenu();
};

void Menu::drawPauseMenu() {
    GLfloat centerX = SCREEN_WIDTH / 2.0f;
    GLfloat centerY = SCREEN_HEIGHT / 2.0f;

    // Calculate half-width and half-height for convenience
    float halfWidth = 500.0f / 2.0f;
    float halfHeight = 200.0f / 2.0f;

    // Define vertices for the rectangle
    float vertices[] = {
        centerX - halfWidth, centerY - halfHeight, 0.0f, // Bottom-left
        centerX + halfWidth, centerY - halfHeight, 0.0f, // Bottom-right
        centerX + halfWidth, centerY + halfHeight, 0.0f, // Top-right
        centerX - halfWidth, centerY + halfHeight, 0.0f  // Top-left
    };

    // Set color for lines (white)
    glColor3f(1, 1, 1);
    glLineWidth(2.0f);

    // Draw lines of the rectangle
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 4);  // Corrected: Use 4 vertices for a rectangle
    glDisableClientState(GL_VERTEX_ARRAY);

    // Set the fill color with alpha for the entire rectangle
    glColor4f(0, 0, 0, 0.5f);

    // Enable blending for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Draw filled faces of the rectangle
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 4);  // Corrected: Use 4 vertices for a rectangle
    glDisableClientState(GL_VERTEX_ARRAY);

    // Disable blending after drawing
    glDisable(GL_BLEND);

    // Draw two thin rectangles side by side (pause sign)
    float halfRectWidth = 15.0f;
    float rectHeight = 80.0f;
    float rectOffset = 30.0f;

    // Define vertices for the first rectangle
    float rect1Vertices[] = {
        centerX - halfRectWidth - rectOffset, centerY - rectHeight / 2.0f, 0.0f, // Bottom-left
        centerX + halfRectWidth - rectOffset, centerY - rectHeight / 2.0f, 0.0f, // Bottom-right
        centerX + halfRectWidth - rectOffset, centerY + rectHeight / 2.0f, 0.0f, // Top-right
        centerX - halfRectWidth - rectOffset, centerY + rectHeight / 2.0f, 0.0f  // Top-left
    };

    // Define vertices for the second rectangle
    float rect2Vertices[] = {
        centerX - halfRectWidth + rectOffset, centerY - rectHeight / 2.0f, 0.0f, // Bottom-left
        centerX + halfRectWidth + rectOffset, centerY - rectHeight / 2.0f, 0.0f, // Bottom-right
        centerX + halfRectWidth + rectOffset, centerY + rectHeight / 2.0f, 0.0f, // Top-right
        centerX - halfRectWidth + rectOffset, centerY + rectHeight / 2.0f, 0.0f  // Top-left
    };

    // Draw the first rectangle
    glColor3f(1, 1, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, rect1Vertices);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Draw the second rectangle
    glColor3f(1, 1, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, rect2Vertices);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

//For GLFW Window
int main1(void);

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;
GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;
int rotationCount = 0;

//Current piece & grid
GLfloat yCube = halfScreenHeight + ((B_HIGHT - 1) * GRID_SPACING) * 0.5 + 2 * GRID_SPACING;
Tetramino* currentPiece = new LongPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
Grid* g = new Grid(halfScreenWidth, halfScreenHeight, -500, GRID_SPACING);
bool pause = 0;
bool gameOver = 0;
int nbPlanes =0;

Menu m;

//Time variables
double prevTime = 0.0;
double crntTime = 0.0;
double timeDiff;
double startTime = glfwGetTime();

int currentTetraminos = 1;
int nextTetraminos = rand() % 5 + 1;

int main1(void)
{
    g->setLevel(0); 
    srand(time(NULL));
    nextTetraminos = rand() % 5 + 1;
    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_FALSE);


    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris 3D", NULL, NULL);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
  

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glViewport(0.0f, 0.0f, screenWidth, screenHeight); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment



    //bool b=g.isMovementPossibe(cube, 0, 0, -GRID_SPACING);
    //bool b2 = g.isRotationPossible(cube, 5);
    //std::cout << b2;
    while (!glfwWindowShouldClose(window))
    {
        if (g->isGameOver()) {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            // Clear the color buffer to black
            glClear(GL_COLOR_BUFFER_BIT);
            // Swap front and back buffers
            glfwSwapBuffers(window);
            // Poll for and process events
            glfwPollEvents();
        }
        else if (pause) {
            //std::this_thread::sleep_for(std::chrono::milliseconds(100));
            glClear(GL_COLOR_BUFFER_BIT);
            glPushMatrix();
            glTranslatef(halfScreenWidth, halfScreenHeight, -500);
            glRotatef(0, 1, 0, 0);
            glRotatef(0, 0, 1, 0);
            glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);
            m.drawPauseMenu();
            glPopMatrix();

            // Swap front and back buffers
            glfwSwapBuffers(window);

            // Poll for and process events
            glfwPollEvents();
        }
        else {

            if (!g->isMovementPossibe(*currentPiece, 0, -GRID_SPACING, 0) && !g->isGameOver()) {
                g->storePiece(*currentPiece, currentTetraminos);
                currentTetraminos = nextTetraminos;
                nextTetraminos = rand() % 5 + 1;
                switch (currentTetraminos) {
                case 1:
                    currentPiece = new LongPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
                    break;
                case 2:
                    currentPiece = new LPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
                    break;
                case 3:
                    currentPiece = new TPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
                    break;
                case 4:
                    currentPiece = new SPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
                    break;
                case 5:
                    currentPiece = new OPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
                    break;
                }
            }

            crntTime = glfwGetTime();
            timeDiff = crntTime - prevTime;
            if (timeDiff > (WAIT_TIME - 0.25 * g->getLevel()) && g->isMovementPossibe(*currentPiece, 0, -GRID_SPACING, 0)) {
                currentPiece->moveDown(GRID_SPACING);
                prevTime = crntTime;
            }
            glClear(GL_COLOR_BUFFER_BIT);
            glClearDepth(1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_DEPTH_TEST);
            glDepthMask(GL_TRUE);
            glDepthFunc(GL_LEQUAL);
            glDepthRange(0.0f, 1.0f);
            //glUniform3f(offsetUniform, 0.0f, 0.0f, -0.75f);
            glPushMatrix();
            glTranslatef(halfScreenWidth, halfScreenHeight, -500);
            glRotatef(rotationX, 1, 0, 0);
            glRotatef(rotationY, 0, 1, 0);
            glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);
            g->draw();
            
            nbPlanes=g->deletePlane();
            if (nbPlanes > 0) {
                gmb->start(nbPlanes + 2, g->getLevel());
            }
            g->drawBlocks();
            currentPiece->draw();
            glPopMatrix();

            // Swap front and back buffers
            glfwSwapBuffers(window);

            // Poll for and process events
            glfwPollEvents();
        }
    }

    glfwTerminate();
    return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    const GLfloat rotationSpeed = 10;
    // actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_W:
            rotationX -= rotationSpeed;
            break;
        case GLFW_KEY_X:
            rotationX += rotationSpeed;
            break;
        case GLFW_KEY_D:
            rotationY += rotationSpeed;
            break;
        case GLFW_KEY_A:
            rotationY -= rotationSpeed;
            break;
        case GLFW_KEY_KP_ADD:
            rotationCount++;
            while (!(g->isRotationPossible(*currentPiece, rotationCount % 20))) {
                currentPiece->setRotation(rotationCount % 20);
                rotationCount++;
            }
            currentPiece->setRotation(rotationCount % 20);
            break;
        case GLFW_KEY_UP:
            if (g->isMovementPossibe(*currentPiece, 0, 0, -GRID_SPACING))
                currentPiece->moveBackward(GRID_SPACING);
            break;
        case GLFW_KEY_DOWN:
            if (g->isMovementPossibe(*currentPiece, 0, 0, GRID_SPACING))
                currentPiece->moveForward(GRID_SPACING);
            break;
        case GLFW_KEY_RIGHT:
            if (g->isMovementPossibe(*currentPiece, GRID_SPACING, 0, 0))
                currentPiece->moveRight(GRID_SPACING);
            break;
        case GLFW_KEY_LEFT:
            if (g->isMovementPossibe(*currentPiece, -GRID_SPACING, 0, 0))
                currentPiece->moveLeft(GRID_SPACING);
            break;
        case GLFW_KEY_M:
            if (g->isMovementPossibe(*currentPiece, 0, -GRID_SPACING, 0))
                currentPiece->moveDown(GRID_SPACING);
            break;
        }
    }
}

//End by Amal
//3D Tetris POC - openGL

//Prepare the sound box for the game
void audioRessoucesByGameStates(Game*);

//UI wxWidgets
class controlFrm : public wxFrame {
public:
    controlFrm() : wxFrame(NULL, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize,
        wxFRAME_NO_TASKBAR | wxNO_BORDER | wxMAXIMIZE_BOX | wxSYSTEM_MENU) {
        SetSize(wxSystemSettings::GetMetric(wxSYS_SCREEN_X), wxSystemSettings::GetMetric(wxSYS_SCREEN_Y));
                
        //Redimentionnement du Frame Pricipal
        int screen_Width = 1920;
        int screen_Height = 1080;
        // Dimensions des panneaux
        int panelWidth = 400;
        int panelHeight = 200;

        wxImage image;

        SetSize(panelWidth, screen_Height);
        SetPosition(wxPoint(screen_Width - panelWidth, 0));
        SetBackgroundColour(wxColour(232, 180, 138));

        // Création et positionnement des panneaux individuellement
        panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(panelWidth, panelHeight));
        panel1->SetPosition(wxPoint(0, 0));
        panel1->SetBackgroundColour(wxColor(232, 180, 138));

        panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(panelWidth, panelHeight));
        panel2->SetPosition(wxPoint(0, panelHeight));
        panel2->SetBackgroundColour(wxColor(232, 180, 138));

        panel21 = new wxPanel(panel2, wxID_ANY, wxDefaultPosition, wxSize(panelWidth, panelHeight / 3));
        panel21->SetPosition(wxPoint(0, 0));
        panel21->SetBackgroundColour(wxColor(232, 180, 138));

        panel22 = new wxPanel(panel2, wxID_ANY, wxDefaultPosition, wxSize(panelWidth, panelHeight / 3));
        panel22->SetPosition(wxPoint(0, panelHeight / 3));
        panel22->SetBackgroundColour(wxColor(232, 180, 138));

        panel23 = new wxPanel(panel2, wxID_ANY, wxDefaultPosition, wxSize(panelWidth, panelHeight / 3));
        panel23->SetPosition(wxPoint(0, 2 * panelHeight / 3));
        panel23->SetBackgroundColour(wxColor(232, 180, 138));

        panel3 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(panelWidth, panelHeight));
        panel3->SetPosition(wxPoint(0, 2 * panelHeight));
        panel3->SetBackgroundColour(wxColor(232, 180, 138));

        panel31 = new wxPanel(panel3, wxID_ANY, wxDefaultPosition, wxSize(panelWidth / 2, panelHeight));
        panel31->SetBackgroundColour(wxColor(232, 180, 138));

        panel32 = new wxPanel(panel3, wxID_ANY, wxDefaultPosition, wxSize(50, panelHeight));
        panel32->SetBackgroundColour(wxColor(232, 180, 138));

        panel33 = new wxPanel(panel3, wxID_ANY, wxDefaultPosition, wxSize(panelWidth - 250, panelHeight));
        panel33->SetBackgroundColour(wxColor(232, 180, 138));

        panel31->SetPosition(wxPoint(0, 0)); // Positionnement de panel31 au coin supérieur gauche de panel3
        panel32->SetPosition(wxPoint(panelWidth / 2, 0)); // Positionnement de panel32 juste à droite de panel31
        panel33->SetPosition(wxPoint(panelWidth / 2 + 50, 0)); // Positionnement de panel33 juste à droite de panel33

        panel4 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(panelWidth, panelHeight));
        panel4->SetPosition(wxPoint(0, 3 * panelHeight));
        panel4->SetBackgroundColour(wxColor(232, 180, 138));

        panel41 = new wxPanel(panel4, wxID_ANY, wxDefaultPosition, wxSize(200, panelHeight));
        panel41->SetBackgroundColour(wxColor(232, 180, 138));

        panel42 = new wxPanel(panel4, wxID_ANY, wxDefaultPosition, wxSize(panelWidth - 200, panelHeight));
        panel42->SetBackgroundColour(wxColor(232, 180, 138));

        panel41->SetPosition(wxPoint(0, 0));
        panel42->SetPosition(wxPoint(200, 0));

        panel5 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(panelWidth, panelHeight));
        panel5->SetPosition(wxPoint(0, 4 * panelHeight));
        panel5->SetBackgroundColour(wxColor(232, 180, 138));

        panel51 = new wxPanel(panel5, wxID_ANY, wxDefaultPosition, wxSize(200, panelHeight));
        panel51->SetBackgroundColour(wxColor(232, 180, 138));

        panel52 = new wxPanel(panel5, wxID_ANY, wxDefaultPosition, wxSize(panelWidth - 200, panelHeight));
        panel52->SetBackgroundColour(wxColor(232, 180, 138));

        panel51->SetPosition(wxPoint(0, 0));
        panel52->SetPosition(wxPoint(200, 0));

        //welcomeButton 
        if (imageToButton("Ressources/Images/sWelcomeTetris.bmp", &image, wxSize(panelWidth, panelHeight))) { wxLog; };
        // Création du bouton image
        welcomeButton = new wxBitmapButton(panel1, -1, image, wxPoint(0, 0), wxSize(panelWidth, panelHeight), 0);

        wxFont* font2 = new wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial"));
        gameTimeLabel = new wxStaticText(panel21, wxID_ANY, "Game time : 0", wxDefaultPosition, wxSize(panelWidth, panelHeight / 3), wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);
        gameTimeLabel->SetFont(*font2);
        gameTimeLabel->SetForegroundColour(wxColour(1, 1, 1));
        gameTimeLabel->SetPosition(wxPoint(0, 0));
        gameTimeLabel->SetBackgroundColour(wxColour(232, 180, 138));
        gameTimeLabel->SetSize(wxSize(panelWidth, panelHeight / 3));

        //Next Tetramino
        if (!imageToButton("Ressources/Images/s0.bmp", &bitmaps[0], wxSize(150, 150))) { wxLog; };
        if (!imageToButton("Ressources/Images/s1.bmp", &bitmaps[1], wxSize(150, 150))) { wxLog; };
        if (!imageToButton("Ressources/Images/s2.bmp", &bitmaps[2], wxSize(150, 150))) { wxLog; };
        if (!imageToButton("Ressources/Images/s3.bmp", &bitmaps[3], wxSize(150, 150))) { wxLog; };
        if (!imageToButton("Ressources/Images/s4.bmp", &bitmaps[4], wxSize(150, 150))) { wxLog; };
        if (!imageToButton("Ressources/Images/s5.bmp", &bitmaps[5], wxSize(150, 150))) { wxLog; };
        nextTetraminosButton = new wxBitmapButton(panel33, -1, bitmaps[0], wxPoint(0, 0), wxSize(150, 200), wxBORDER_NONE);
        nextTetraminosButton->SetBackgroundColour(wxColour(232, 180, 138));

        //welcomeButton 
        if (imageToButton("Ressources/Images/sWelcomeTetris.bmp", &image, wxSize(panelWidth, panelHeight))) { wxLog; };
        // Création du bouton image
        welcomeButton = new wxBitmapButton(panel1, -1, image, wxPoint(0, 0), wxSize(panelWidth, panelHeight), 0);
        
        gameScoreLabel = new wxStaticText(panel22, wxID_ANY, "Game score : 0", wxDefaultPosition, wxSize(panelWidth, panelHeight / 3), wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);
        gameScoreLabel->SetFont(*font2);
        gameScoreLabel->SetForegroundColour(wxColour(1, 1, 1));
        gameScoreLabel->SetBackgroundColour(wxColour(232, 180, 138));
        gameScoreLabel->SetPosition(wxPoint(0, 0));
        gameScoreLabel->SetSize(wxSize(panelWidth, panelHeight / 3));
        //how to align vertically the text

        gameLevelLabel = new wxStaticText(panel23, wxID_ANY, "Game level  : 0", wxDefaultPosition, wxSize(panelWidth, panelHeight / 3), wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);
        gameLevelLabel->SetFont(*font2);
        gameLevelLabel->SetForegroundColour(wxColour(1, 1, 1));
        gameLevelLabel->SetBackgroundColour(wxColour(232, 180, 138));
        gameLevelLabel->SetPosition(wxPoint(0, 0));
        gameLevelLabel->SetSize(wxSize(panelWidth, panelHeight / 3));

        //muteUnmuteButton 
        if (imageToButton("Ressources/Images/sSoundOff.bmp", &image, wxSize(200, 200))) {};
        // Création du bouton image
        muteUnmuteButton = new wxBitmapButton(panel31, -1, image, wxPoint(0, 0), wxSize(200, 200), wxALIGN_CENTER_HORIZONTAL + wxALIGN_CENTER_VERTICAL);
        // Ajout du tooltip initial
        muteUnmuteButton->SetToolTip("OnMusic");

        // Initialisation de la slider de volume
        audioVolume = new wxSlider(panel32, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxSize(50, 200), wxSL_LABELS + wxSL_VERTICAL);
        audioVolume->SetBackgroundColour(wxColour(232, 180, 138));
        audioVolume->Refresh();

        // closeButton
        if (imageToButton("Ressources/Images/sExit.bmp", &image, wxSize(200, panelHeight))) {};
        closeButton = new wxBitmapButton(panel52, -1, image, wxPoint(0, 0), wxSize(200, panelHeight), 0);
        closeButton->SetToolTip("Exit");

        //pauseButton
        if (imageToButton("Ressources/Images/sPause.bmp", &image, wxSize(200, panelHeight))) {};
        pauseButton = new wxBitmapButton(panel51, -1, image, wxPoint(0, 0), wxSize(200, panelHeight), 0);
        pauseButton->SetToolTip("Pause");

        //about Button
        if (imageToButton("Ressources/Images/slevelUp.bmp", &image, wxSize(200, 200))) {};
        levelUpButton = new wxBitmapButton(panel41, -1, image, wxPoint(0, 0), wxSize(200, 200), 0);
        levelUpButton->SetToolTip("About");

        //helpButton
        if (imageToButton("Ressources/Images/shelp.bmp", &image, wxSize(200, 200))) {};
        helpButton = new wxBitmapButton(panel42, -1, image, wxPoint(0, 0), wxSize(200, 200), 0);
        helpButton->SetToolTip("Help");


        levelUpButton->Bind(wxEVT_BUTTON, &controlFrm::OnLevelUpClick, this, levelUpButton->GetId());
        helpButton->Bind(wxEVT_BUTTON, &controlFrm::OnHelpButtonClick, this, helpButton->GetId());
        pauseButton->Bind(wxEVT_BUTTON, &controlFrm::OnPauseButtonClick, this, pauseButton->GetId());
        muteUnmuteButton->Bind(wxEVT_BUTTON, &controlFrm::OnMuteUnmuteButtonClick, this);
        myTimer.Bind(wxEVT_TIMER, &controlFrm::OnTimer, this);
        gameTimer.Bind(wxEVT_TIMER, &controlFrm::OnGameTimer, this);
        closeButton->Bind(wxEVT_BUTTON, &controlFrm::OnCloseButtonClick, this, closeButton->GetId());
        audioVolume->Bind(wxEVT_SCROLL_THUMBRELEASE, &controlFrm::OnVolumeChanged, this);
        // Liaison de l'événement de montrer/afficher à la méthode OnFrameShow
        Bind(wxEVT_SHOW, &controlFrm::OnFrameShow, this);

        //Règle la position de l'interface 
        myTimer.Start(timerInterval);
        //chronomètre du jeu
        gameTimer.Start(gameTimerInterval);
    }
    void resizeMyControls() {
        
        //Redimentionnement du Frame Pricipal
        int screen_Width = 1920;
        int screen_Height = 1080;
        // Dimensions des panneaux
        int panelWidth = 400;
        int panelHeight = 200;

        SetSize(panelWidth, screen_Height);
        SetPosition(wxPoint(screen_Width - panelWidth, 0));
        SetBackgroundColour(wxColor(232, 180, 138));

        // Positionnement des panneaux individuellement
        panel1->SetPosition(wxPoint(0, 0));
        panel1->SetSize(wxSize(panelWidth, panelHeight));
        panel1->SetBackgroundColour(wxColor(232, 180, 138));

        panel2->SetPosition(wxPoint(0, panelHeight));
        panel2->SetSize(wxSize(panelWidth, panelHeight));
        panel2->SetBackgroundColour(wxColor(232, 180, 138));

        panel21->SetSize(wxSize(panelWidth, panelHeight / 3));
        panel21->SetPosition(wxPoint(0, 0));
        panel21->SetBackgroundColour(wxColor(232, 180, 138));

        panel22->SetSize(wxSize(panelWidth, panelHeight / 3));
        panel22->SetPosition(wxPoint(0, panelHeight / 3));
        panel22->SetBackgroundColour(wxColor(232, 180, 138));
    }

private:
    // Controls
    wxSlider* audioVolume; 
    wxBitmapButton* closeButton;
    wxBitmapButton* welcomeButton;
    wxBitmapButton* pauseButton;
    wxBitmapButton* muteUnmuteButton;
    wxPanel* panel1, * panel2, * panel3, * panel4, * panel5, * panel31, * panel32, * panel33, * panel51, * panel52, * panel21, * panel22, * panel23, * panel41, * panel42;
    wxStaticText* gameTimeLabel;
    wxStaticText* gameScoreLabel;
    wxStaticText* gameLevelLabel;
    wxBitmapButton* nextTetraminosButton;
    wxBitmapButton* podiumButton;
    wxBitmapButton* levelUpButton;
    wxBitmapButton* helpButton;
    wxImage bitmaps[6];

    GameOverFrame* gameOverframe = new GameOverFrame("Game Over", g->getScore());

    wxTimer myTimer;
    wxTimer gameTimer;
    static const int timerInterval = 100;
    static const int gameTimerInterval = 2000;
    
    bool imageToButton(wxString fileName, wxImage* wxI, wxSize wxS) {
        wxBitmap bitmap;

        // // Chargement de l'image
        bitmap.LoadFile(fileName, wxBITMAP_TYPE_BMP);
        if (!bitmap.IsOk()) return false;
        // Redimensionnement de l'image à la taille spécifiée
        *wxI = bitmap.ConvertToImage();
        wxI->Rescale(wxS.GetWidth(), wxS.GetHeight(), wxIMAGE_QUALITY_HIGH);
        return true;
    }
    
    //Handler des evts
    void OnHelpButtonClick(wxCommandEvent& event) {
        //OnPauseButtonClick(event);
        HelpFrm* myHelpFrm;
        myHelpFrm = new HelpFrm();
        myHelpFrm->Show();
    }

    void OnFrameShow(wxShowEvent& event) {
        //Mettre le slider sur le volume actuel
        if (gmb != NULL) {
            audioVolume->SetValue(gmb->getVolume());
        }
    }

    void OnVolumeChanged(wxScrollEvent& event) {
        // Récupérer la nouvelle valeur du slider
        gmb->setVolume(audioVolume->GetValue());

        glfwFocusWindow(window);
    }
    
    void OnLevelUpClick(wxCommandEvent& event) {

        g->setLevel( 1 + g->getLevel() % 10);
        std::string labelText = "Level " + std::to_string(g->getLevel());
        gameLevelLabel->SetLabel(labelText);
        gmb->start(0, g->getLevel() );
    }

    void OnPodiumButtonClick(wxCommandEvent& event) {

        //Pause pour le jeu
        //gameTimer.Stop();


        Podium* p;
        p = new Podium();
        gmb->start(1, 5);
        //Afficher le podium
        p->render();
    }

    void OnPauseButtonClick(wxCommandEvent& event) {
        if (pauseButton->GetToolTip()->GetTip() == "Pause") {
            //pause game
            pauseButton->SetToolTip("Reprise");
            pause = 1;
            // Chargement de l'image
            wxBitmap bitmap;
            bitmap.LoadFile("Ressources/Images/sstart.bmp", wxBITMAP_TYPE_BMP);
            if (!bitmap.IsOk()) return;
            // Redimensionnement de l'image à la taille spécifiée
            wxImage image = bitmap.ConvertToImage();
            image.Rescale(200, 200, wxIMAGE_QUALITY_HIGH); // Redimensionner l'image à 200x200
            // Pour bouton changement image
            pauseButton->SetBitmap(wxBitmap(image));
            gmb->stop();
            //pauseButton = new wxBitmapButton(panel5, -1, image, wxPoint(0, 0), wxSize(200, 200), 0);
        }
        else {
            //reprise game
            pauseButton->SetToolTip("Pause");
            pause = 0;
            
            // Chargement de l'image
            wxBitmap bitmap;
            bitmap.LoadFile("Ressources/Images/spause.bmp", wxBITMAP_TYPE_BMP);
            if (!bitmap.IsOk()) return;
            // Redimensionnement de l'image à la taille spécifiée
            wxImage image = bitmap.ConvertToImage();
            image.Rescale(200, 200, wxIMAGE_QUALITY_HIGH); // Redimensionner l'image à 200x200
            // Pour bouton changement image
            pauseButton->SetBitmap(wxBitmap(image));
            
            //glfwSetWindowPos(window, 0, 0);
            gmb->start(0, g->getLevel());
            // Redonner le focus à la fenêtre GLFW
        }
        glfwFocusWindow(window);
        
    }

    void OnCloseButtonClick(wxCommandEvent& event) {
        int answer = wxMessageBox("Are you sure you want to exit?", "Confirm", wxYES_NO | wxICON_QUESTION);   
        if (answer == wxYES) {
            // Disable events for the frame itself
            SetEvtHandlerEnabled(false);
            gameTimer.Stop();            
            gmb->stop();            
            //delete gmb;
            // Set the close flag for the window
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            
            /*wxMessageBox("le score est : " + std::to_string(g->getScore()) + " le niveau : " + std::to_string(g->getLevel()));*/
            if (g->isGameOver())              
                gameOverframe->Close();
            
            this->Close(); // Close the frame and exit the application
            wxExit();
            //exit;
        } else
            // If user selects No, do nothing
            glfwFocusWindow(window);
    }
    
    void OnMuteUnmuteButtonClick(wxCommandEvent& event) {

        if (muteUnmuteButton->GetToolTip()->GetTip() == "onMusic") {
            //pause game
            muteUnmuteButton->SetToolTip("offMusic");

            // Chargement de l'image
            wxBitmap bitmap;
            bitmap.LoadFile("Ressources/Images/sSoundoff.bmp", wxBITMAP_TYPE_BMP);
            if (!bitmap.IsOk()) return;
            // Redimensionnement de l'image à la taille spécifiée
            wxImage image = bitmap.ConvertToImage();
            image.Rescale(200, 200, wxIMAGE_QUALITY_HIGH); // Redimensionner l'image à 200x200
            // Pour bouton changement image
            muteUnmuteButton->SetBitmap(wxBitmap(image));
            //pauseButton = new wxBitmapButton(panel5, -1, image, wxPoint(0, 0), wxSize(200, 200), 0);

        }
        else {
            //reprise game
            muteUnmuteButton->SetToolTip("onMusic");

            // Chargement de l'image
            wxBitmap bitmap;
            bitmap.LoadFile("Ressources/Images/sSoundon.bmp", wxBITMAP_TYPE_BMP);
            if (!bitmap.IsOk()) return;
            // Redimensionnement de l'image à la taille spécifiée
            wxImage image = bitmap.ConvertToImage();
            image.Rescale(200, 200, wxIMAGE_QUALITY_HIGH); // Redimensionner l'image à 200x200
            // Pour bouton changement image
            muteUnmuteButton->SetBitmap(wxBitmap(image));
        }

        if (gmb->getState() == GMB_Stop)
            //specify step level
            gmb->start(0, g->getLevel());
        else
            gmb->stop();

        glfwFocusWindow(window);
    }
   
    void OnTimer(wxTimerEvent&)
    {
        //Called only one time
        //To adjust screen sizes and positions
        int screen_Width = 1920;//wxSystemSettings::GetMetric(wxSYS_SCREEN_X);
        int screen_Height = 1080;//wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);
        int panelsWidth = 400;
        //wxFrame
        SetSize(panelsWidth, screen_Height);
        SetPosition(wxPoint(screen_Width- panelsWidth, 0));
        resizeMyControls();
        //Glfw window
        glfwSetWindowSize(window, screen_Width -panelsWidth, screen_Height);
        glfwSetWindowPos(window, 0, 0);
        // Redonner le focus à la fenêtre GLFW
        glfwFocusWindow(window);
        std::string labelText = "Score : " + std::to_string(g->getScore());
        gameScoreLabel->SetLabel(labelText);
        
        nextTetraminosButton->SetBitmap(bitmaps[nextTetraminos]);

        //Soigner l'affichage
        Refresh();

        myTimer.Stop();

        glfwFocusWindow(window);
    };

    void OnGameTimer(wxTimerEvent&)
    {
        wxString myStr;
        double gameTime = glfwGetTime() - startTime;
     
        myStr.Printf(wxT("%.0f"), gameTime);
        
        gameTimeLabel->SetLabel("Game time : " + myStr);
        std::string labelText = "Score : " + std::to_string(g->getScore());
        gameScoreLabel->SetLabel(labelText);
        
        if (!g->isGameOver()) nextTetraminosButton->SetBitmap(bitmaps[nextTetraminos]);
        else
            nextTetraminosButton->SetBitmap(bitmaps[0]);
        glfwFocusWindow(window);
        if (g->isGameOver()) {
            
            gmb->stop();
            gmb->start(1, 8);
            gameTimer.Stop();
 
            GameOverFrame* gameOverframe = new GameOverFrame("Game Over", g->getScore());
            gameOverframe->Show(true);

            //Proposer un nouveau score apres GameOver
            //Charger les score du podium
            Podium* p;
            wxString userName;
            p = new Podium();
            BestScore* bs;          
            //Si ce score doit figurer ds le podium alors l'ajouter
            if (p->isPodiumScore(g->getScore())) {
                wxTextEntryDialog dialog(this, wxT("Congrants you win"), wxT("Your name"));
                if (dialog.ShowModal() == wxID_OK)
                {
                    userName = dialog.GetValue();
                }
                bs = new BestScore(userName.ToStdString(), g->getScore(), "");
                p->addPodium(*bs); 
                
                //Afficher le podium
                p->render();
            }
        }
    };
};

//wx UI Program entry
class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        //Prepare data for GameMusicBox
        Game game;
        audioRessoucesByGameStates(&game);
        //Start Game Audio Box 
        gmb = new GameMusicBox(game);
        gmb->start(2, 8);
        //1st step of the game with lowest level
        gmb->start(0, g->getLevel());

        //Load wxFrame
        controlFrm* frame = new controlFrm();
        frame->Show();

        //Load Glfw Window
        main1();

        return true;
    }
};

wxIMPLEMENT_APP(MyApp);

//End UI wxWidgets

void audioRessoucesByGameStates(Game* game) {
    //For evry sate one audio file and one Mode
    game->nbSteps = 7;
    game->steps[0].FileName = "Ressources/Sounds/onPlaying.mp3";
    game->steps[0].Mode = MM_ASYNC_LOOP;
    game->steps[0].State = 0;

    game->steps[1].FileName = "Ressources/Sounds/ding.mp3";
    game->steps[1].Mode = MM_SYNC;
    game->steps[1].State = 1;

    game->steps[2].FileName = "Ressources/Sounds/18GameOver.mp3";
    game->steps[2].Mode = MM_SYNC;
    game->steps[2].State = 2;

    game->steps[3].FileName = "Ressources/Sounds/tetris1.mp3";
    game->steps[3].Mode = MM_SYNC;
    game->steps[3].State = 3;    
    
    game->steps[4].FileName = "Ressources/Sounds/tetris2.mp3";
    game->steps[4].Mode = MM_SYNC;
    game->steps[4].State = 4;    
    
    game->steps[5].FileName = "Ressources/Sounds/tetris3.mp3";
    game->steps[5].Mode = MM_SYNC;
    game->steps[5].State = 5;    
    
    game->steps[6].FileName = "Ressources/Sounds/tetris4.mp3";
    game->steps[6].Mode = MM_SYNC;
    game->steps[6].State = 6;

    game->nbLevel = 10;
}

