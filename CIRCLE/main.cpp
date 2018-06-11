


#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

void heart();
void cir();
void display()
{
    glClearColor(1.0,1.0,1.0,0.0);

    glClear(GL_COLOR_BUFFER_BIT);

   // float a=0,b=0;
    {//glTranslatef(a=a+0.00001,b=b+0.0001,0.0);
    cir();//point();
    }
    heart();
    //glutPostRedisplay();
    glFlush();

}


int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("translate");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void cir()
{{glColor3f(1.0,1.0,0.0);
glPushMatrix();
glTranslatef(-0.5,0.0,0.0);
glutSolidSphere(0.3,80,80);
glPopMatrix();
/*GLfloat x=-0.5; GLfloat y=-0.0; GLfloat radius=0.3;
int i;
int triangleAmount = 100; //# of triangles used to draw circle
//GLfloat radius = 0.8f; //radius
GLfloat twicePi = 2.0f * 3.141592;
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x, y); // center of circle
for(i = 0; i <= triangleAmount;i++) {
glVertex2f(
x + (radius * cos(i * twicePi / triangleAmount)),
y + (radius * sin(i * twicePi / triangleAmount))
);
}
glEnd();*/
 {glColor3f(0.0,0.0,0.0);
{float x=-0.0,y=-0.0;

glPushMatrix();
for(int i=240;i<300;i++)
 {glPointSize(2.0);
glBegin(GL_POINTS);

 x=cos((2*i*3.14)/360) * .2;
 y=sin((2*i*3.14)/360) * .2;
 glVertex2f(x-0.5,y+0.1);
// glTranslatef(x-0.5,y+0.1,0);
// glutSolidSphere(0.01,10,10);
 glEnd();

 }
 glPopMatrix();

glPushMatrix();
glTranslatef(-0.6,0.08,00);
glColor3f(0.4,0.0,0.0);
glutSolidTorus(0.005,0.08,100,100);
glColor3f(0.0,0.0,0.0);
glutSolidSphere(0.04,100,100);
glPopMatrix();
glPushMatrix();
glTranslatef(-0.4,0.08,00);
glColor3f(0.4,0.0,0.0);
glutSolidTorus(0.005,0.08,1000,1000);
glColor3f(0.0,0.0,0.0);
glutSolidSphere(0.04,100,100);
glPopMatrix();
 /*glPointSize(10.0);
 glBegin(GL_POINTS);
 glVertex2f(-0.6,0.08);
 glVertex2f(-0.4,.08);
 glEnd();*/
}
}
}
}

void heart()
{   glScalef(0.8,0.8,0.0);
    glColor3f(0.8,0.0,0.0);
    glPushMatrix();
    glTranslatef(-0.08,0.0,0.0);
    glutSolidSphere(0.1,80,80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.08,0.0,0.0);
    glutSolidSphere(0.1,80,80);
    glPopMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(-0.18,-0.040);
    glVertex2f(0.18,-0.040);
    glVertex2f(0.0,-0.2);
    glEnd();
}


