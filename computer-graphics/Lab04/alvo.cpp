#include "headers/alvo.h"
#include <math.h>
#include "headers/utils.h"
#include <iostream>

void Alvo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{   
    glColor3f(R, G, B);
    int numsegments = 20;

    glBegin(GL_POLYGON);
      for(int ii = 0; ii < numsegments; ii++)
      {
        float theta = 2.0f * 3.1415926f * float(ii) / float(numsegments);//get the current angle

        float x = radius * cosf(theta);//calculate the x component
        float y = radius * sinf(theta);//calculate the y component

        glVertex2f(x, y);//output vertex
      }
    glEnd();
}

void Alvo::DesenhaAlvo(GLfloat x, GLfloat y)
{
    glPushMatrix();
    glTranslatef(x, y, 0);

    switch (gColor) {
        case 0:
            DesenhaCirc(radiusAlvo, 1, 0, 0);
            break;
        case 1:
            DesenhaCirc(radiusAlvo, 0, 1, 0);
            break;
        case 2:
            DesenhaCirc(radiusAlvo, 0, 0, 1);
            break;
    }
    
    glPopMatrix();
}

void Alvo::Recria(GLfloat x, GLfloat y)
{

    this->gX = Utils::generateRandomNumberInRange(-240, 240);

    std::cout << "Alvo gerado em x: " << gX << std::endl;

    switch (gColor) {
        case 0:
            gColor++;
            break;
        case 1:
            gColor++;
            break;
        case 2:
            gColor = 0;
            break;
    }
}

bool Alvo::Atingido(Tiro *tiro)
{
    GLfloat tX, tY;
    tiro->GetPos(tX, tY);
    if(tX >= gX - radiusAlvo && tX <= gX + radiusAlvo
        && tY <= gY + radiusAlvo && tY >= gY - radiusAlvo) {
            return true;
    }
    return false;
}
