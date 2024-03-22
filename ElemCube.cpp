#include "ElemCube.h"
#include <GLFW/glfw3.h>
#include <iostream>

void ElemCube::drawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength, GLfloat c1, GLfloat c2, GLfloat c3) {
    GLfloat halfSideLength = edgeLength * 0.5f;




    GLfloat vertices[] =
    {
        // front face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

        // back face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom left

        // left face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

        // right face
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

        // top face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // bottom left

        // top face
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength  // bottom left
    };


    // Set color for lines (white)
    glColor3f(0, 0, 0);
    glLineWidth(1.0f);
    // Draw lines of the cube
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Set the fill color with alpha for the entire cube
    glColor4f(c1, c2, c3, 0.5f);

    // Enable blending for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Draw filled faces of the cube
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Disable blending after drawing
    glDisable(GL_BLEND);
}