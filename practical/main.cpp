#include<stdlib.h>
#include<windows.h>
#include<GL/glut.h>

void tri()
{
   glutWireOctahedron();
    glFlush();

}
void init()
{
    glMatrixMode(GL_PROJECTION);
     gluOrtho2D(0.0,500.0,0.0,500.0);
     glLoadIdentity();


}
GLfloat x,y,z;

void display()
{glViewport(200,200,650,550);
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(x,0,0.1,0.0);
     glRotatef(y,0,0.0,0.1);
      glRotatef(z,0.1,0.0,0.0);
    tri();

        glViewport(0,0,200,200);
    glutSolidSphere(0.3,60,60);
    glutPostRedisplay();
}

void ani()
{
    x+=0.000002;
    y+=0.000003;
    z+=0.000004;
    display();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(650,550);
    glutInitWindowPosition(100,100);
    init();
    glutCreateWindow("Pramid");
    glutDisplayFunc(display);
    glutIdleFunc(ani);
    glutMainLoop();
    return 0;
}
