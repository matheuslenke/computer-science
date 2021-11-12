#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
#include <vector>
#define TAMANHO_JANELA 500

float size = 1.0;

//Pontos de controle da Spline

// vector <GLfloat[3]> ctrlpoints;
int maxPoints = 100;
int totalPoints = 4;
GLfloat ctrlpoints[100][3] = {
   { 0.1, 0.1, 0.0}, { 0.2, 0.8, 0.0}, 
   { 0.4, 0.1, 0.0}, { 0.8, 0.8, 0.0}};

int selectedPoint = -1;
bool isDraggingControlPoint = false; 

void init(void)
{
   // GLfloat P1[3] = { 0.1, 0.1, 0.0};
   // GLfloat P2[3] = {0.2, 0.8, 0.0};
   // GLfloat P3[3] = {0.4, 0.1, 0.0};
   // GLfloat P4[3] = {0.8, 0.8, 0.0};
   // ctrlpoints.push_back(P1);
   // ctrlpoints.push_back(P2);
   // ctrlpoints.push_back(P3);
   // ctrlpoints.push_back(P4);
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_MAP1_VERTEX_3);

   //Definicao do polinomio com os pontos de controle
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]); 
   
   //Muda para a matriz de projecao (aulas futuras)
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, size, 0, size, 0, size);
}

void drawCurve() {
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]); 
   /* Desenha a curva aproximada por n+1 pontos. */
   int i;
   int n = 30;
   glColor3f(1.0, 1.0, 1.0);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= n; i++){
        //Avaliacao do polinomio, retorna um vertice (equivalente a um glVertex3fv) 
        glEvalCoord1f((GLfloat) i/(GLfloat)n);
      }
   glEnd();
}

void display(void)
{
   int i;

   glClear(GL_COLOR_BUFFER_BIT);
   
   drawCurve();
   
   /* Desenha os pontos de controle. */
   glPointSize(5.0);
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_POINTS);
      for (i = 0; i < totalPoints; i++) 
         glVertex3fv(&ctrlpoints[i][0]);
   glEnd();
   
   glutSwapBuffers();
}

void reshape(int w, int h)
{
   //Define a porcao visivel da janela
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   
   //Muda para a matriz de projecao (aulas futuras)
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   //Controla o redimensionamento da janela mantendo o aspect ration do objeto
   if (w <= h)
      glOrtho(-size, size, -size*(GLfloat)h/(GLfloat)w, 
               size*(GLfloat)h/(GLfloat)w, -size, size);
   else
      glOrtho(-size*(GLfloat)w/(GLfloat)h, 
               size*(GLfloat)w/(GLfloat)h, -size, size, -size, size);
   
   //Muda para a matriz de trasformacoes (aulas futuras)
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouseClick(int button, int state, int x, int y) {
   y = TAMANHO_JANELA - y;
   std::cout << x << ' ' << state << std::endl;

   // Tarefa 3.2
   float relativeX = (float) x / (float) TAMANHO_JANELA;
   float relativeY = (float) y / (float) TAMANHO_JANELA;
   // glutPostRedisplay();

   float safeArea = 30.0 / (float) TAMANHO_JANELA;
   // Tarefa 3.3
   if (state == 0) {
      for (int i = 0; i< totalPoints; i++) {
         std::cout << "Ponto " << i << " " << safeArea << "X: " << ctrlpoints[i][0] << std::endl; 
         if(relativeX >= ctrlpoints[i][0] - safeArea && relativeX <= ctrlpoints[i][0] + safeArea ) {
            if (relativeY >= ctrlpoints[i][1] - safeArea && relativeY <= ctrlpoints[i][1] + safeArea) {
               std::cout << "Clicou no ponto de controle!" << std::endl;
                isDraggingControlPoint = true;
                selectedPoint = i;
            }
         }
      }
   } else {
      isDraggingControlPoint = false;
      selectedPoint = -1;
   }
}

void mouseMove(int x, int y) {
   y = TAMANHO_JANELA - y;
   float relativeX = (float) x / (float) TAMANHO_JANELA;
   float relativeY = (float) y / (float) TAMANHO_JANELA;

   if (isDraggingControlPoint) {
      ctrlpoints[selectedPoint][0] = relativeX;
      ctrlpoints[selectedPoint][1] = relativeY;
   }

   glutPostRedisplay();
}

 /* Callback de tecla pressionada */
void keyPress(unsigned char key, int x, int y) {
   // std::cout << "Entrou" << std::endl;
   if (key == '+') {
      ctrlpoints[totalPoints][0] = ctrlpoints[totalPoints - 1][0] + 0.01; 
      ctrlpoints[totalPoints][1] = ctrlpoints[totalPoints - 1][1] + 0.01; 
      ctrlpoints[totalPoints][2] = 0;
      totalPoints += 1;

      glutPostRedisplay();
   }
   if (key == '-') {
      // gY += 0.01;
      // glutPostRedisplay();
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (TAMANHO_JANELA, TAMANHO_JANELA);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutMouseFunc(mouseClick);
   glutMotionFunc(mouseMove);
   glutKeyboardFunc(keyPress);
   // glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
