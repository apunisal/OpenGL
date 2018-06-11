#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>



void cir()
{
    glColor3f(1.0,0.0,0.0);
    glutSolidSphere(0.2,60,60);

}
int main(int argc,char **argv)
{ glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow("pol");
  glutDisplayFunc(cir);
  glutMainLoop();
  return 0;
}

