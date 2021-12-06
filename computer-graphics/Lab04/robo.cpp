#include "headers/robo.h"
#include <math.h>
#include <iostream>

void Robo::DesenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B)
{
   /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
   glColor3f (R, G, B);
   /* Desenhar um polígono branco (retângulo) */
   glBegin(GL_POLYGON);
      glVertex3f (0 , 0, 0.0);
      glVertex3f (width / 2 , 0, 0.0);
      glVertex3f (width / 2 , height, 0.0);
      glVertex3f (- width / 2, height, 0.0);
      glVertex3f (- width / 2, 0, 0.0);
      glVertex3f (0, 0, 0.0);
   glEnd();
}

void Robo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
    glColor3f(R, G, B);
    glPointSize(3);
    int numsegments = 25;

    glBegin(GL_POINTS);
      for(int ii = 0; ii < numsegments; ii++)
      {
        float theta = 2.0f * 3.1415926f * float(ii) / float(numsegments);//get the current angle

        float x = radius * cosf(theta);//calculate the x component
        float y = radius * sinf(theta);//calculate the y component

        glVertex2f(x, y);//output vertex
      }


    glEnd();
}

void Robo::DesenhaRoda(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat R, GLfloat G, GLfloat B)
{
    glPushMatrix();

    glTranslatef(x, y, 0);
    glRotatef(thetaWheel, 0, 0, 1);
    DesenhaCirc(radiusWheel, R, G, B);

    glPopMatrix();
}

void Robo::DesenhaBraco(GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
    glPushMatrix();

    // Primeira haste azul
    glTranslatef(x, y, 0);
    glRotatef(theta1, 0, 0, 1);
    DesenhaRect(paddleHeight, paddleWidth, 0, 0, 1);

    // Segunda haste amarela
    glPushMatrix();
    glTranslatef(0, paddleHeight, 0);
    glRotatef(theta2, 0, 0, 1);
    DesenhaRect(paddleHeight, paddleWidth, 1, 1, 0);

    // Terceira Haste
    glPushMatrix();
    glTranslatef(0, paddleHeight, 0);
    glRotatef(theta3, 0, 0, 1);
    DesenhaRect(paddleHeight, paddleWidth, 1, 0, 1);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void Robo::DesenhaRobo(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
    // std::cout << x << "," << y << std::endl;
    glPushMatrix();
    glTranslatef(x, y, 0);

    DesenhaRect(baseHeight, baseWidth, 1, 0, 0);
    DesenhaBraco(0, baseHeight, theta1, theta2, theta3);

    DesenhaRoda(-baseWidth / 2, 0, thetaWheel, 0.5, 0.2, 0.8);
    DesenhaRoda(baseWidth / 2, 0, thetaWheel, 0.5, 0.2, 0.8);

    glPopMatrix();

}

void Robo::RodaBraco1(GLfloat inc)
{
    this->gTheta1 += inc;
}

void Robo::RodaBraco2(GLfloat inc)
{
    this->gTheta2 += inc;
}

void Robo::RodaBraco3(GLfloat inc)
{
    this->gTheta3 += inc;
}

void Robo::MoveEmX(GLfloat dx, GLdouble timeDiff)
{
    this->gX += dx * timeDiff;
    this->gThetaWheel -= (180 * dx) / (M_PI * radiusWheel) * timeDiff;
}

//Funcao auxiliar de rotacao
void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut){
    yOut = y + paddleHeight*sin (angle*M_PI/180);
    xOut = x + paddleHeight*cos (angle*M_PI/180);
}

void TranslatePoint(GLfloat x, GLfloat y, GLfloat incx, GLfloat incy, GLfloat &xOut, GLfloat &yOut) {
    xOut = x + incy;
    yOut = y + incy;
}

Tiro* Robo::Atira()
{

    // // Ponta da haste
    // GLfloat xP = 0.0;
    // GLfloat yP = paddleHeight;
    // // Base da haste
    // GLfloat xB = 0.0;
    // GLfloat yB = 0.0;

    // // Calculando a posição da ponta da Haste -> Transformacoes
    // RotatePoint(xP, yP, gTheta3, xP, yP);
    // TranslatePoint(xP, yP, 0, paddleHeight, xP, yP);
    // RotatePoint(xP, yP, gTheta2, xP, yP);
    // TranslatePoint(xP, yP, 0, paddleHeight, xP, yP);
    // RotatePoint(xP, yP, gTheta1, xP, yP);
    // TranslatePoint(xP, yP, 0, baseHeight, xP, yP);

    // // xP += gX;
    // yP += gY;

    // // // Calculando posição da Base da Haste -> Transformações
    // RotatePoint(xB, yB, gTheta3, xB, yB);
    // TranslatePoint(xB, yB, 0, paddleHeight, xB, yB);
    // RotatePoint(xB, yB, gTheta2, xB, yB);
    // TranslatePoint(xB, yB, 0, paddleHeight, xB, yB);
    // RotatePoint(xB, yB, gTheta1, xB, yB);
    // TranslatePoint(xB, yB, 0, baseHeight, xB, yB);

    // // xB += gX;
    // yB += gY;

    // std::cout << "Pontos: (" << xP << "," << yP << ")" << std::endl;


    // Tiro* tiro = new Tiro(xP, yP, 1.0);

    // GLfloat t1, t2;
    // tiro->GetPos(t1, t2);


    // return tiro;

    // tX = tiroX, tY = tiroY, tTheta = tiroTheta
    GLfloat tX = this->gX, tY = this->gY, tTheta = 90;
    tY += baseHeight;

    RotatePoint (tX, tY, tTheta += this->gTheta1, tX, tY);
    RotatePoint (tX, tY, tTheta += this->gTheta2, tX, tY);
    RotatePoint (tX, tY, tTheta += this->gTheta3, tX, tY);

    std::cout << "Ponto criado: (" <<  tX << "," << tY << ")" << std::endl;
    return new Tiro (tX, tY, tTheta);

}
