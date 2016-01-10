//#include <stdio.h>
//#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glaux.h>

#include "Card.h"

void display();
 
Card card(0,0,0,0.25,0.5,0.05,25,25,0);

void display()
{
 card.draw();
}

void timer(int = 0)
{
	display();
	glutTimerFunc(10, timer, 0);
}

int main(int argc, char* argv[]){

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("Card");
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  glutDisplayFunc(display);
  glutTimerFunc(10, timer, 0);
  glutMainLoop();
 
  return 0;
 
}
