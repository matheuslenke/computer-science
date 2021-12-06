#include "headers/tiro.h"
#include <math.h>
#include <iostream>
#define DISTANCIA_MAX 500

void Tiro::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
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

void Tiro::DesenhaTiro(GLfloat x, GLfloat y)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    // std::cout << "DesenhaTiro: " << x << "," << y << std::endl;
    DesenhaCirc(radiusTiro, 1, 1, 1);
    glPopMatrix();
}

void Tiro::Move(GLdouble timeDifference)
{
    float fx = gVel * cosf(gDirectionAng * M_PI / 180) * timeDifference;
    float fy = gVel * sinf(gDirectionAng * M_PI / 180) * timeDifference;
    // std::cout << fx << " " << fy << std::endl;
    gX += fx ;
    gY += fy ;
}

bool Tiro::Valido()
{
    float distance = sqrt(pow(gX - gXInit, 2) +
                pow(gY - gYInit, 2) * 1.0);
    if (distance >= DISTANCIA_MAX) {
        return false;
    }
    return true;
}
