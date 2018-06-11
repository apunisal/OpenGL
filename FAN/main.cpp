

#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
using namespace std;

void tri()
{ float a=0.001;
    glRotatef(a+0.01,0,0,1.0);

   glBegin(GL_POLYGON);
   glVertex2d(0.2,0.2);
    glColor3f(0.0,0.0,0.5);
   glVertex2d(0.5,0.7);
   glVertex2d(0.8,0.8);
    glColor3f(0.0,0.0,0.5);
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
    glutPostRedisplay();
   glEnd();
}

void mid()
{ float b=0.009;
    glRotatef(b+0.09,0,0,1.0);
     glBegin(GL_LINE_LOOP);
   glVertex2d(0.0,0.2);
   glVertex2d(-0.2,-0.2);
   glVertex2d(0.2,-0.2);

   glEnd();
}


void display()
{

    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    tri();

    glFlush();
    mid();

}


int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(600,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("translate");
    //glutDisplayFunc(display);
     cout<<"hi........";
    glutMainLoop();
    return 0;
}

