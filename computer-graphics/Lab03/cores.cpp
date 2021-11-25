#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <iostream>
#include <math.h>
#define TAMANHO_JANELA 500

//Pontos do triangulo
float pRx = 0.1;
float pRy = 0.1;
float pGx = 0.9;
float pGy = 0.1;
float pBx = 0.5;
float pBy = 0.9;


class Point { 
    public: 
    const float x; 
    const float y; 
    Point(float x=0.0, float y=0.0): x(x), y(y) { 
    }; 
    // passing lhs by value helps optimize chained a+b+c 
    // otherwise, both parameters may be const references 
    friend Point operator-(Point a, const Point& b) { 
        return Point(a.x-b.x, a.y-b.y); // return the result by value (uses move constructor) 
    } 
 
}; 
 
// determinant 
float det(Point a, Point b){ 
    return a.x*b.y - a.y*b.x; 
} 
 
 
class Line { 
    public: 
    const Point a; 
    const Point b; 
    Line(Point a, Point b): a(a), b(b) { 
    } 
};

//Controle dos arrastes
int draggingPointR = 0, draggingPointG = 0, draggingPointB = 0, choosingColor = 0;

//Cor
float gR = 0., gG = 0., gB = 0.;

//Ponto do clique da cor
float pCliqueX = 0, pCliqueY = 0;
//Pronto do clique projetado
float pProjX = 0, pProjY = 0;

        
void display(void)
{
   //Define a cor do fundo
   glClearColor (gR, gG, gB, 0.0);

   /* Limpar todos os pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
   /* Desenhar um polígono branco (retângulo) */
   glBegin(GL_POLYGON);
      glColor3f (1.0, 0.0, 0.0);
      glVertex3f (pRx, pRy, 0.0);
      glColor3f (0.0, 1.0, 0.0);
      glVertex3f (pGx, pGy, 0.0);
      glColor3f (0.0, 0.0, 1.0);
      glVertex3f (pBx, pBy, 0.0);
   glEnd();

   /* Desenha o ponto de clique. */
   glPointSize(5.0);
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_POINTS);
        glVertex3f(pCliqueX, pCliqueY, 0.0);
   glEnd();

   /* Desenha o ponto projetado. */
   glPointSize(5.0);
   glColor3f(1.0, 1.0, 1.0);
   glBegin(GL_POINTS);
        glVertex3f(pProjX, pProjY, 0.0);
   glEnd();
   
   /* Desenhar no frame buffer! */
   glutSwapBuffers(); //Funcao apropriada para janela double buffer
}

void init (void) 
{
  /* selecionar cor de fundo (preto) */
  glClearColor (0.0, 0.0, 0.0, 0.0);

  /* inicializar sistema de visualizacao */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

// https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
 
Point lineIntersection(Line l1, Line l2){ 
    Point l1Diff = l1.a - l1.b; 
    Point l2Diff = l2.a - l2.b; 
 
    Point xDiff(l1Diff.x, l2Diff.x); 
    Point yDiff(l1Diff.y, l2Diff.y); 
 
    Point dets = Point(det(l1.a, l1.b), det(l2.a,l2.b)); 
    float denominator = det(xDiff, yDiff); 
 
    float x = det(dets, xDiff) / denominator; 
    float y = det(dets, yDiff) / denominator; 
 
    return Point(x,y); 
}

float distance(float x1, float y1, float x2, float y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}

void calculateBlueColor(Point P, Point C) {
    gB = (1.0 - distance(C.x, C.y, pBx, pBy) / distance(P.x, P.y, pBx, pBy) );
    std::cout << "Blue: " << gB << std::endl;
}

void calculateGreenColor(Point P, Point C) {
    gG = ( 
    ((distance(P.x, P.y, pRx, pRy) / distance(pGx, pGy, pRx, pRy))
    *
    (distance(C.x, C.y, pBx, pBy) / distance(P.x, P.y, pBx, pBy)))
    );
    std::cout << "Red: " << gR << std::endl;
}

void calculateRedColor(Point P, Point C) {
    gR = ( 
    ((distance(P.x, P.y, pGx, pGy) / distance(pGx, pGy, pRx, pRy))
    *
    (distance(C.x, C.y, pBx, pBy) / distance(P.x, P.y, pBx, pBy)))
    );
    std::cout << "Green: " << gG << std::endl;
}


void motion(int x, int y){
    //Corrige a posicao do mouse para a posicao da janela de visualizacao
    y = TAMANHO_JANELA - y;
    GLfloat fX = (GLfloat)x/TAMANHO_JANELA;
    GLfloat fY = (GLfloat)y/TAMANHO_JANELA;
    
    if (choosingColor){
        //Atualiza posicao do clique
        pCliqueX = fX;
        pCliqueY = fY;

		/**
			COLOQUE SEU CODIGO AQUI
		**/

        Line line1(Point(pBx, pBy), Point(fX, fY)); 
        Line line2(Point(pRx, pRy), Point(pGx, pGy)); 
 
        Point projection = lineIntersection(line1, line2); 
        pProjX = projection.x; 
        pProjY = projection.y;

        std::cout << "Ponto de projeção: (" << pProjX << "," << pProjY << ")" << std::endl;
        Point C = Point(fX, fY);

        calculateBlueColor(projection, C);
        calculateRedColor(projection, C);
        calculateGreenColor(projection, C);

    } else if (draggingPointR){
        pRx = (GLfloat)x/TAMANHO_JANELA;
        pRy = (GLfloat)y/TAMANHO_JANELA;
    } else if (draggingPointG){
        pGx = (GLfloat)x/TAMANHO_JANELA;
        pGy = (GLfloat)y/TAMANHO_JANELA;
    } else if (draggingPointB){
        pBx = (GLfloat)x/TAMANHO_JANELA;
        pBy = (GLfloat)y/TAMANHO_JANELA;
    }
    
    glutPostRedisplay();
}


void mouse(int button, int state, int x, int y){
    //Corrige a posicao do mouse para a posicao da janela de visualizacao
    GLfloat fX = (GLfloat)x/TAMANHO_JANELA;
    GLfloat fY = (GLfloat)(TAMANHO_JANELA - y)/TAMANHO_JANELA;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        choosingColor = 1;
    }else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        if (    (pRx-fX)*(pRx-fX) +
                (pRy-fY)*(pRy-fY) < 
                    (30.0/TAMANHO_JANELA)*(30.0/TAMANHO_JANELA) ){
            draggingPointR = 1;
        } else if (     (pGx-fX)*(pGx-fX) +
                        (pGy-fY)*(pGy-fY) < 
                            (30.0/TAMANHO_JANELA)*(30.0/TAMANHO_JANELA) ){
            draggingPointG = 1;
        } else if (     (pBx-fX)*(pBx-fX) +
                        (pBy-fY)*(pBy-fY) < 
                            (30.0/TAMANHO_JANELA)*(30.0/TAMANHO_JANELA) ){
            draggingPointB = 1;
        }

    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        choosingColor = 0;
    }else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP){
        draggingPointR = draggingPointG = draggingPointB = 0;
    }
    
    motion(x, y);
}
    
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (TAMANHO_JANELA, TAMANHO_JANELA); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Cores");
    init ();
    glutDisplayFunc(display); 
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}
