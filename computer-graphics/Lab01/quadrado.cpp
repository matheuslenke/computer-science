#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

#define TAMANHO_JANELA 1000

float gX = 0;
float gY = 0;
float squareSize = 0.1;
int keyStatus[256];
float moveDistance = 0.005;
bool isSquareMoving = false;
float mouseDiffX = 0;
float mouseDiffY = 0;

void display(void)
{
   /* Limpar todos os pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
   glColor3f (0, 0.5, 0.7);
   /* Desenhar um polígono branco (retângulo) */
   glBegin(GL_POLYGON);
      glVertex3f (gX, gY, 0.0);
      glVertex3f (gX + squareSize, gY, 0.0);
      glVertex3f (gX + squareSize, gY + squareSize, 0.0);
      glVertex3f (gX, gY + squareSize, 0.0);
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

   // for (int i = 0; i<=256; i++) {
   //    keyStatus[i] = 0;
   // }
}

 /* Callback de tecla pressionada */
void keyPress(unsigned char key, int x, int y) {
   // std::cout << "Entrou" << std::endl;

   if (key == 'w') {
      // gY += 0.01;
      keyStatus[int('w')] = 1;
      // glutPostRedisplay();
   }
   if (key == 'a') {
      // gY += 0.01;
      keyStatus[int('a')] = 1;
      // glutPostRedisplay();
   }
   if (key == 's') {
      // gY += 0.01;
      keyStatus[int('s')] = 1;
      // glutPostRedisplay();
   }
   if (key == 'd') {
      // gY += 0.01;
      keyStatus[int('d')] = 1;
      // glutPostRedisplay();
   }

}

   /* Callback de tecla solta */
void keyUp(unsigned char key, int x, int y) {
   if (key == 'w') {
      // gY += 0.01;
      keyStatus[int('w')] = 0;
      // glutPostRedisplay();
   }
   if (key == 'a') {
      // gY += 0.01;
      keyStatus[int('a')] = 0;
      // glutPostRedisplay();
   }
   if (key == 's') {
      // gY += 0.01;
      keyStatus[int('s')] = 0;
      // glutPostRedisplay();
   }
   if (key == 'd') {
      // gY += 0.01;
      keyStatus[int('d')] = 0;
      // glutPostRedisplay();
   }
}

void idle (void) {

   if (keyStatus[int('w')] == 1) {
      gY += moveDistance;
   }
   if (keyStatus[int('a')] == 1) {
      gX -= moveDistance;
   }
   if (keyStatus[int('s')] == 1) {
      gY -= moveDistance;
   }
   if (keyStatus[int('d')] == 1) {
      gX += moveDistance;
   }
   glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {
   y = TAMANHO_JANELA - y;
   std::cout << x << ' ' << state << std::endl;

   // Tarefa 3.2
   float relativeX = (float) x / (float) TAMANHO_JANELA;
   float relativeY = (float) y / (float) TAMANHO_JANELA;
   // glutPostRedisplay();

   // Tarefa 3.3
   if (state == 0) {
      if(relativeX >= gX && relativeX <= gX + squareSize) {
         if (relativeY >= gY && relativeY <= gY + squareSize) {

            isSquareMoving = true;
            std::cout << "gX:" << gX << " mouseX: " << x << std::endl;
            // Calculando posição do mouse em relação ao eixo inicial do quadrado
            mouseDiffX = relativeX - gX; 
            mouseDiffY = relativeY - gY;
            std::cout << "X:" << mouseDiffX << " Y:" << mouseDiffY << std::endl;
         }
      }
   } else {
      isSquareMoving = false;
   }
}

void mouseMove(int x, int y) {
   y = TAMANHO_JANELA - y;
   float relativeX = (float) x / (float) TAMANHO_JANELA;
   float relativeY = (float) y / (float) TAMANHO_JANELA;

   if (isSquareMoving) {
      gX = relativeX - mouseDiffX;
      gY = relativeY - mouseDiffY;
   }
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (TAMANHO_JANELA, TAMANHO_JANELA); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Square game");
   init ();
   glutDisplayFunc(display); 

   // Registrar keyUp
   glutKeyboardFunc(keyPress);
   glutKeyboardUpFunc(keyUp);
   glutIdleFunc(idle);
   glutMouseFunc(mouseClick);
   glutMotionFunc(mouseMove);
   glutMainLoop();

   return 0;
}
