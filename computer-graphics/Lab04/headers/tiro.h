#ifndef TIRO_H
#define	TIRO_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#define radiusTiro 5

class Tiro {
    GLfloat gXInit; 
    GLfloat gYInit; 
    GLfloat gX; 
    GLfloat gY; 
    GLfloat gDirectionAng;
    GLfloat gVel;
private:
    void DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B);
    void DesenhaTiro(GLfloat x, GLfloat y);
public:
    Tiro(GLfloat x, GLfloat y, GLfloat directionAng){
        gXInit = x; 
        gYInit = y; 
        gX = x; 
        gY = y; 
        gDirectionAng = directionAng; 
        gVel = 0.5;
    };
    void Desenha(){ 
        DesenhaTiro(gX, gY);
    };
    void Move(GLdouble timeDifference);
    bool Valido();
    void GetPos(GLfloat &xOut, GLfloat &yOut){
        xOut = gX;
        yOut = gY;
    };
};

#endif	/* TIRO_H */
