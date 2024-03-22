#include "Grid.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "ElemCube.h"
#include "Tetramino.h"
using namespace std;


Grid::Grid(float x, float y, float z, float gridSpacing) : xPosCenter(x), yPosCenter(y), zPosCenter(z), gridSpacing(gridSpacing) {
    for (int i = 0; i < B_HIGHT; i++)
        for (int j = 0; j < B_WIDTH; j++)
            for (int k = 0; k < B_DEPTH; k++)
                matrix[i][j][k] = 0;
    score = 0;
};

void Grid::draw() {
    glPushMatrix();
    glTranslatef(xPosCenter, yPosCenter, zPosCenter); // Center the grid and adjust the depth

    //float gridSpacing = 100.0f;

    // Draw horizontal grid lines
    for (int i = -B_HIGHT / 2; i <= B_HIGHT / 2; ++i) {
        float yPos = i * gridSpacing;
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glLineWidth(1);
        glVertex3f(-B_WIDTH * gridSpacing / 2, yPos, -(B_WIDTH * gridSpacing) * 0.5);
        glVertex3f(B_WIDTH * gridSpacing / 2, yPos, -(B_WIDTH * gridSpacing) * 0.5);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glLineWidth(1);
        glVertex3f(-(B_WIDTH * gridSpacing) * 0.5, yPos, -B_WIDTH * gridSpacing / 2);
        glVertex3f(-(B_WIDTH * gridSpacing) * 0.5, yPos, B_WIDTH * gridSpacing / 2);
        glEnd();

    }

    // Draw vertical grid lines
    for (int i = -B_WIDTH / 2; i <= B_WIDTH / 2; ++i) {
        float xPos = i * gridSpacing;
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glLineWidth(1);
        glVertex3f(xPos, -B_HIGHT * gridSpacing / 2, -(B_WIDTH * gridSpacing) * 0.5);
        glVertex3f(xPos, B_HIGHT * gridSpacing / 2, -(B_WIDTH * gridSpacing) * 0.5);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glLineWidth(1.0f);
        glVertex3f(-(B_WIDTH * gridSpacing) * 0.5, -B_HIGHT * gridSpacing / 2, xPos);
        glVertex3f(-(B_WIDTH * gridSpacing) * 0.5, B_HIGHT * gridSpacing / 2, xPos);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glLineWidth(1);
        glVertex3f(xPos, -(B_HIGHT * gridSpacing) * 0.5, -B_WIDTH * gridSpacing / 2);
        glVertex3f(xPos, -(B_HIGHT * gridSpacing) * 0.5, B_WIDTH * gridSpacing / 2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glLineWidth(1);
        glVertex3f(-B_WIDTH * gridSpacing / 2, -(B_HIGHT * gridSpacing) * 0.5, xPos);
        glVertex3f(B_WIDTH * gridSpacing / 2, -(B_HIGHT * gridSpacing) * 0.5, xPos);
        glEnd();
    }

    glPopMatrix();
}

void Grid::drawBlocks() {
    //std::cout << "drawBlocks" << std::endl;
    for (int i = -5; i < 5; i++) {
        for (int j = -2; j < 2; j++) {
            //std::cout << "loop2" << std::endl;
            for (int k = -2; k < 2; k++) {
                if (matrix[i + B_HIGHT / 2][j + B_WIDTH / 2][k + B_DEPTH / 2] != 0) {
                    switch (matrix[i + B_HIGHT / 2][j + B_WIDTH / 2][k + B_DEPTH / 2]) {
                    case 1:
                        ElemCube::drawCube(xPosCenter + (j + 0.5) * gridSpacing,
                            yPosCenter + (i + 0.5) * gridSpacing,
                            zPosCenter + (k + 0.5) * gridSpacing, gridSpacing, 0.647f, 0.941f, 0.392f);
                        break;
                    case 2:
                        ElemCube::drawCube(xPosCenter + (j + 0.5) * gridSpacing,
                            yPosCenter + (i + 0.5) * gridSpacing,
                            zPosCenter + (k + 0.5) * gridSpacing, gridSpacing, 0.549f, 0.969f, 0.926f);
                        break;
                    case 3:
                        ElemCube::drawCube(xPosCenter + (j + 0.5) * gridSpacing,
                            yPosCenter + (i + 0.5) * gridSpacing,
                            zPosCenter + (k + 0.5) * gridSpacing, gridSpacing, 0.969f, 0.549f, 0.816f);
                        break;
                    case 4:
                        ElemCube::drawCube(xPosCenter + (j + 0.5) * gridSpacing,
                            yPosCenter + (i + 0.5) * gridSpacing,
                            zPosCenter + (k + 0.5) * gridSpacing, gridSpacing, 0.753f, 0.392f, 0.941f);
                        break;
                    case 5:
                        ElemCube::drawCube(xPosCenter + (j + 0.5) * gridSpacing,
                            yPosCenter + (i + 0.5) * gridSpacing,
                            zPosCenter + (k + 0.5) * gridSpacing, gridSpacing, 0.969f, 0.949f, 0.549f);
                        break;
                    }
                }
            }
        }
    }


}
bool Grid::isMovementPossibe(Tetramino t, float xMvt, float yMvt, float zMvt) {
    int xMvtBlocks = xMvt / gridSpacing;
    int yMvtBlocks = yMvt / gridSpacing;
    int zMvtBlocks = zMvt / gridSpacing;
    float xPosOrigin = xPosCenter - B_WIDTH * gridSpacing * 0.5;
    float yPosOrigin = yPosCenter - B_HIGHT * gridSpacing * 0.5;
    float zPosOrigin = zPosCenter - B_DEPTH * gridSpacing * 0.5;

    float xPrimeTetramino = t.getXPos() - xPosOrigin;
    float yPrimeTetramino = t.getYPos() - yPosOrigin;
    float zPrimeTetramino = t.getZPos() - zPosOrigin;

    int xPrimeTetraminoBlocks = xPrimeTetramino / gridSpacing;
    int yPrimeTetraminoBlocks = yPrimeTetramino / gridSpacing;
    int zPrimeTetraminoBlocks = zPrimeTetramino / gridSpacing;

    for (int i = -2; i < 3; i++)
        for (int j = -2; j < 3; j++)
            for (int k = -2; k < 3; k++) {
                if (t.getBlockType(j + 2, i + 2, k + 2) != 0) {
                    bool test1 = xPrimeTetraminoBlocks + xMvtBlocks + i >= B_WIDTH
                        || zPrimeTetraminoBlocks + zMvtBlocks + k >= B_DEPTH;
                    bool test2 = xPrimeTetraminoBlocks + xMvtBlocks + i < 0
                        || yPrimeTetraminoBlocks + yMvtBlocks + j < 0 || zPrimeTetraminoBlocks + zMvtBlocks + k < 0;
                    if (test1 || test2)
                        return 0;

                    /*std::cout << i + 2 << ":" << j + 2 << ":" << k + 2 << " " << xPrimeTetraminoBlocks + xMvtBlocks + j << ", "
                        << zPrimeTetraminoBlocks + zMvtBlocks + k << ", "
                        << yPrimeTetraminoBlocks + yMvtBlocks + i  << std::endl;*/
                        //std::cout << xPrimeTetraminoBlocks << ", " << yPrimeTetraminoBlocks << ", " << zPrimeTetraminoBlocks << std::endl;
                }
                if (j + yPrimeTetraminoBlocks + yMvtBlocks < B_HIGHT) {

                    if ((t.getBlockType(j + 2, i + 2, k + 2) != 0) &&
                        (matrix[j + yPrimeTetraminoBlocks + yMvtBlocks][i + xPrimeTetraminoBlocks + xMvtBlocks][k + zPrimeTetraminoBlocks + zMvtBlocks] != 0)) {
                        //std::cout << matrix[j + yPrimeTetraminoBlocks + yMvtBlocks][i + xPrimeTetraminoBlocks + xMvtBlocks][k + zPrimeTetraminoBlocks + zMvtBlocks] << std::endl;
                        return 0;

                    }
                }



            }

    //std::cout << xPrimeTetraminoBlocks<<", "<< yPrimeTetraminoBlocks<< ", "<< zPrimeTetraminoBlocks << std::endl;
    return 1;
}

bool Grid::isRotationPossible(Tetramino t, int r) {
    t.setRotation(r);

    float xPosOrigin = xPosCenter - B_WIDTH * gridSpacing * 0.5;
    float yPosOrigin = yPosCenter - B_HIGHT * gridSpacing * 0.5;
    float zPosOrigin = zPosCenter - B_DEPTH * gridSpacing * 0.5;

    float xPrimeTetramino = t.getXPos() - xPosOrigin;
    float yPrimeTetramino = t.getYPos() - yPosOrigin;
    float zPrimeTetramino = t.getZPos() - zPosOrigin;

    int xPrimeTetraminoBlocks = xPrimeTetramino / gridSpacing;
    int yPrimeTetraminoBlocks = yPrimeTetramino / gridSpacing;
    int zPrimeTetraminoBlocks = zPrimeTetramino / gridSpacing;

    for (int i = -2; i < 3; i++)
        for (int j = -2; j < 3; j++)
            for (int k = -2; k < 3; k++) {
                if (t.getBlockType(j + 2, i + 2, k + 2) != 0) {
                    bool test1 = xPrimeTetraminoBlocks + i >= B_WIDTH
                        || zPrimeTetraminoBlocks + k >= B_DEPTH;
                    bool test2 = xPrimeTetraminoBlocks + i < 0
                        || yPrimeTetraminoBlocks + j < 0 || zPrimeTetraminoBlocks + k < 0;
                    if (test1 || test2) {
                        return 0;
                    }


                    /*std::cout << i + 2 << ":" << j + 2 << ":" << k + 2 << " " << xPrimeTetraminoBlocks + j << ", "
                        << zPrimeTetraminoBlocks + k << ", "
                        << yPrimeTetraminoBlocks  + i  << std::endl;*/
                        //std::cout << xPrimeTetraminoBlocks << ", " << yPrimeTetraminoBlocks << ", " << zPrimeTetraminoBlocks << std::endl;
                }
                if (j + yPrimeTetraminoBlocks < B_HIGHT && j + yPrimeTetraminoBlocks >= 0)
                    if ((t.getBlockType(j + 2, i + 2, k + 2) != 0) &&
                        (matrix[j + yPrimeTetraminoBlocks][i + xPrimeTetraminoBlocks][k + zPrimeTetraminoBlocks] != 0)) {
                        //std::cout << j + yPrimeTetraminoBlocks << " " << i + xPrimeTetraminoBlocks  << " " << k + zPrimeTetraminoBlocks << std::endl;
                        return 0;
                    }


            }
    return 1;
};

void Grid::storePiece(Tetramino t, int tType) {

    float xPosOrigin = xPosCenter - B_WIDTH * gridSpacing * 0.5;
    float yPosOrigin = yPosCenter - B_HIGHT * gridSpacing * 0.5;
    float zPosOrigin = zPosCenter - B_DEPTH * gridSpacing * 0.5;

    float xPrimeTetramino = t.getXPos() - xPosOrigin;
    float yPrimeTetramino = t.getYPos() - yPosOrigin;
    float zPrimeTetramino = t.getZPos() - zPosOrigin;

    int xPrimeTetraminoBlocks = xPrimeTetramino / gridSpacing;
    int yPrimeTetraminoBlocks = yPrimeTetramino / gridSpacing;
    int zPrimeTetraminoBlocks = zPrimeTetramino / gridSpacing;

    for (int i = -2; i < 3; i++)
        for (int j = -2; j < 3; j++)
            for (int k = -2; k < 3; k++) {
                if (t.getBlockType(j + 2, i + 2, k + 2) != 0) {
                    matrix[j + yPrimeTetraminoBlocks][i + xPrimeTetraminoBlocks][k + zPrimeTetraminoBlocks] = tType;
                    //std::cout << matrix[j + yPrimeTetraminoBlocks][i + xPrimeTetraminoBlocks][k + zPrimeTetraminoBlocks] << std::endl;
                }
            }

    //cout << "piece stored" << endl;
    /*for (int l = 0; l<B_HIGHT; l++)
        for (int m=0; m<B_WIDTH; m++)
            for(int n=0; n<B_DEPTH; n++)
                cout << l << ", " << m << ", " << n << " " << matrix[l][m][n] << endl;*/
}






bool Grid::isGameOver() {
    for (int i = 0; i < B_WIDTH; i++)
        for (int k = 0; k < B_DEPTH; k++) {
            if (matrix[9][i][k] != 0)
                return 1;
        }
    return 0;
}

void Grid::upDatescore(int p) {
    score += p;
};

int Grid::deletePlane(void) {
    bool gap;
    int i, k, j = 0, points = 0, nbDeletedPlanes = 0;
    while (j < B_HIGHT - 1) {
        i = 0;

        gap = 0;
        while (i < B_WIDTH && !gap) {
            k = 0;
            while (k < B_DEPTH && !gap) {
                if (matrix[j][i][k] == 0)
                    gap = 1;
                k++;
            }
            i++;
        }

        //Effacer couche j
        if (!gap) {
            //cout << i << ", " << k << endl;
            for (int l = j; l < B_HIGHT - 1; l++)
                for (int m = 0; m < B_WIDTH; m++)
                    for (int n = 0; n < B_DEPTH; n++)
                    {
                        //cout << l << ", " << m << ", " << n << " " << matrix[l][m][n] << endl;
                        matrix[l][m][n] = matrix[l + 1][m][n];
                    }
            nbDeletedPlanes += 1;
        }
        else
            j++;
    }

    switch (nbDeletedPlanes) {
    case 1:
        upDatescore(40 * (level+1));
        break;
    case 2:
        upDatescore(120 * (level + 1));
        break;
    case 3:
        upDatescore(300 * (level + 1));
        break;
    case 4:
        upDatescore(1200 * (level + 1));
        break;
    }
    return nbDeletedPlanes;
}