

#include<stdlib.h>
#include<windows.h>
#include<GL/glut.h>
void tri()
{ float a=0.001;
    glRotatef(a+0.01,0,0,1.0);

  {

   glBegin(GL_POLYGON);
   glVertex2d(0.2,0.2);
   glVertex2d(0.5,0.7);
   glVertex2d(0.8,0.8);
   glVertex2d(0.7,0.5);
   glEnd();

   glBegin(GL_POLYGON);
   glVertex2d(-0.2,0.2);
   glVertex2d(-0.5,0.7);
   glVertex2d(-0.8,0.8);
   glVertex2d(-0.7,0.5);

   glEnd();

   glBegin(GL_POLYGON);
   glVertex2d(0.2,-0.2);
   glVertex2d(0.5,-0.7);
    glVertex2d(0.8,-0.8);
    glVertex2d(0.7,-0.5);
   glEnd();

   glBegin(GL_POLYGON);
   glVertex2d(-0.2,-0.2);
   glVertex2d(-0.5,-0.7);
   glVertex2d(-0.8,-0.8);
    glVertex2d(-0.7,-0.5);
   glEnd();
  }

glutPostRedisplay();


}
void cir()
{
    glutSolidSphere(0.2,60,60);

}


void display()
{ glClear(GL_COLOR_BUFFER_BIT);
  tri();
  cir();

glFlush();
}

void menu(int i)
{

    switch(i)
    {   case 0:exit(0);break;
        case 1:glColor3f(1.0,0.9,0.0);glClearColor(0.2, 0.0, 0.00,0.0);break;
        case 2:glColor3f(0.8,0.7,0.0);glClearColor(0.0, 0.200, 0.0,0.0);break;
        case 3:glColor3f(1.0, 0.0, 0.522);glClearColor(0.01, 0.00, 0.09,0.0);break;
    }
    glutPostRedisplay();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(600,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("pop");

    int v=glutCreateMenu(menu);
    glutAddMenuEntry("Red",1);
    glutAddMenuEntry("Green",2);
    glutAddMenuEntry("Blue",3);
    glutCreateMenu(menu);
    glutAddSubMenu("Background colours ",v);

    glutAddMenuEntry("Quit",0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}

