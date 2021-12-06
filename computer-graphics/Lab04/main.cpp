#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "headers/robo.h"
#include "headers/alvo.h"
#define INC_KEY 1
#define INC_KEYIDLE 0.08

//Key status
int keyStatus[256];

// Window dimensions
const GLint Width = 700;
const GLint Height = 700;

// Viewing dimensions
const GLint ViewingWidth = 500;
const GLint ViewingHeight = 500;

//Controla a animacao do robo
int animate = 0;

//Componentes do mundo virtual sendo modelado
Robo robo; //Um rodo
Tiro * tiro = NULL; //Um tiro por vez
Alvo alvo(0, 200); //Um alvo por vez

int atingido = 0;
static char str[1000];
void * font = GLUT_BITMAP_9_BY_15;

void ImprimePlacar(GLfloat x, GLfloat y)
{
    glColor3f(1.0, 1.0, 1.0);
    //Cria a string a ser impressa
    char *tmpStr;
    sprintf(str, "Atingido: %d", atingido );
    //Define a posicao onde vai comecar a imprimir
    glRasterPos2f(x, y);
    //Imprime um caractere por vez
    tmpStr = str;
    while( *tmpStr ){
        glutBitmapCharacter(font, *tmpStr);
        tmpStr++;
    }
}

void renderScene(void)
{
     // Clear the screen.
     glClear(GL_COLOR_BUFFER_BIT);
 
     robo.Desenha();
     
     if (tiro) tiro->Desenha();
     
     alvo.Desenha();

     ImprimePlacar(-240, -240);

     glutSwapBuffers(); // Desenha the new frame of the game.

}

void keyPress(unsigned char key, int x, int y)
{
    switch (key)
    {
        case '1':
             animate = !animate;
             break;
        case 'a':
        case 'A':
             keyStatus[(int)('a')] = 1; //Using keyStatus trick
             break;
        case 'd':
        case 'D':
             keyStatus[(int)('d')] = 1; //Using keyStatus trick
             break;
        case 'f':
        case 'F':
             robo.RodaBraco1(-INC_KEY);   //Without keyStatus trick
             break;
        case 'r':
        case 'R':
             robo.RodaBraco1(+INC_KEY);   //Without keyStatus trick
             break;
        case 'g':
        case 'G':
             robo.RodaBraco2(-INC_KEY);   //Without keyStatus trick
             break;
        case 't':
        case 'T':
             robo.RodaBraco2(+INC_KEY);   //Without keyStatus trick
             break;
        case 'h':
        case 'H':
             robo.RodaBraco3(-INC_KEY);   //Without keyStatus trick
             break;
        case 'y':
        case 'Y':
             robo.RodaBraco3(+INC_KEY);   //Without keyStatus trick
             break;
        case ' ':
             if (!tiro)
                tiro = robo.Atira();
             break;
        case 27 :
             exit(0);
    }
    glutPostRedisplay();
}

void keyup(unsigned char key, int x, int y)
{
    keyStatus[(int)(key)] = 0;
    glutPostRedisplay();
}

void ResetKeyStatus()
{
    int i;
    //Initialize keyStatus
    for(i = 0; i < 256; i++)
       keyStatus[i] = 0; 
}

void init(void)
{
    ResetKeyStatus();
    // The color the windows will redraw. Its done to erase the previous frame.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black, no opacity(alpha).
 
    glMatrixMode(GL_PROJECTION); // Select the projection matrix    
    glOrtho(-(ViewingWidth/2),     // X coordinate of left edge             
            (ViewingWidth/2),     // X coordinate of right edge            
            -(ViewingHeight/2),     // Y coordinate of bottom edge             
            (ViewingHeight/2),     // Y coordinate of top edge             
            -100,     // Z coordinate of the “near” plane            
            100);    // Z coordinate of the “far” plane
    glMatrixMode(GL_MODELVIEW); // Select the projection matrix    
    glLoadIdentity();
      
}

void idle(void)
{
    // for(int i = 0; i < 9000000; i++);
    static GLdouble previousTime = glutGet(GLUT_ELAPSED_TIME);
    GLdouble currentTime, timeDiference;
    //Pega o tempo que passou do inicio da aplicacao
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    // Calcula o tempo decorrido desde de a ultima frame.
    timeDiference = currentTime - previousTime;
    //Atualiza o tempo do ultimo frame ocorrido
    previousTime = currentTime;

    double inc = INC_KEYIDLE;
    //Treat keyPress
    if(keyStatus[(int)('a')])
    {
        robo.MoveEmX(-inc, timeDiference);
    }
    if(keyStatus[(int)('d')])
    {
        robo.MoveEmX(inc, timeDiference);
    }
    
    //Trata o tiro (soh permite um tiro por vez)
    //Poderia usar uma lista para tratar varios tiros
    if(tiro){
        tiro->Move(timeDiference);

        //Trata colisao
        if (alvo.Atingido(tiro)){
            alvo.Recria(rand()%500 - 250, 200);
            atingido++;
        }

        if (!tiro->Valido()){ 
            delete tiro;
            tiro = NULL;
        }
    }
    
    
    //Control animation
    if (animate){
        static int dir = 1;
        if (robo.ObtemX() > (ViewingWidth/2)){
            dir *= -1;
        }
        else if (robo.ObtemX() < -(ViewingWidth/2)){
            dir *= -1;
        }
        robo.MoveEmX(dir*INC_KEYIDLE, timeDiference);
    }
    
    glutPostRedisplay();
}


 
int main(int argc, char *argv[])
{
    // Initialize openGL with Double buffer and RGB color without transparency.
    // Its interesting to try GLUT_SINGLE instead of GLUT_DOUBLE.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 
    // Create the window.
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(150,50);
    glutCreateWindow("Tranformations 2D");
 
    // Define callbacks.
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(keyPress);
    glutIdleFunc(idle);
    glutKeyboardUpFunc(keyup);
    
    init();
 
    glutMainLoop();
 
    return 0;
}