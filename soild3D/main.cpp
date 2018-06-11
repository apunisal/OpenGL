#include <windows.h>
#include <GL/glut.h>
#include<stdlib.h>
#include <Math.h>
#include<mmsystem.h>
#define PI 3.14159265f
// Global variables

GLfloat ballRadius = 0.3f;   // Radius of the smiley
GLfloat ballX = 0.0f;         // smiley's center (x, y) position
GLfloat ballY = -0.5f;
GLfloat ballXMax, ballXMin, ballYMax, ballYMin; // smiley's center (x, y) bounds
GLfloat xSpeed = 0.020f;      // smiley's speed in x and y directions
GLfloat ySpeed = 0.040f;

// Projection clipping area
GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

//////////////////////////////////////////////////////

GLfloat diffuseMaterial[4] = { 1, 1,0, 0.0 };
void init(void)
{
    GLfloat ambient[] = { 1.0, 0.843 , 0.0, 0.0 };
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 1.0, 0.0, 1.0, 0.0 };
   glShadeModel (GL_SMOOTH);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}
///////////////////////////////////////////////////////////

void Osmiley()
{
   glPushMatrix();
   glPushMatrix();                   //face of first smiley
   glColor3f(1.0,1.0,0.0);            //yellow
   glutSolidSphere(ballRadius,80,80);
   glPopMatrix();

   glPushMatrix();                 //Eyes of smiley
    glColor3f(0.0,0.0,0.0);        //black
    glTranslatef(0.1,0.10,0.0);
    glutSolidSphere(0.03,80,80);
    glPopMatrix();

    glPushMatrix();                 //Eyes of smiley
    init();
        glColor3f(0.0,0.0,0.0);         //black
    glTranslatef(-0.1,0.10,0.0);
    glutSolidSphere(0.03,80,80);
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();                 //mouth of smiley
    glTranslatef(0.0,-0.15,0.0);
    glColor3f(0.0,0.0,0.0);         //black
    glutSolidSphere(0.06,80,80);
    glPopMatrix();
    glPopMatrix();

}

void Csmiley()
{
    /*Face of second smiley*/
     glPushMatrix();                   //face of first smiley
   glColor3f(1.0,1.0,0.0);
   glTranslatef(-0.5,0.0,0.0);           //yellow
   glutSolidSphere(ballRadius,80,80);
   glPopMatrix();

  /*code for smile*/
    glColor3f(0.0,0.0,0.0);     //color of mouth
    float x=-0.0,y=-0.0;
    glPushMatrix();
    glTranslatef(0.0,-0.05,0.0);
    for(int i=240;i<300;i++)
 {  glPointSize(3.0);
    glBegin(GL_POINTS);
    x=cos((2*i*3.14)/360) * .2;
    y=sin((2*i*3.14)/360) * .2;
    glVertex2f(x-0.5,y+0.1);
    glEnd();
}
 glPopMatrix();


 glColor3f(0.4,0.0,0.0);           //code for stick of spectacles
    glPushMatrix();
    glTranslatef(0.0,-0.2,0.0);
    for(int i=265;i<275;i++)
 {  glPointSize(3.0);
    glBegin(GL_POINTS);
    x=-cos((2*i*3.14)/360) * .2;
    y=-sin((2*i*3.14)/360) * .2;
    glVertex2f(x-0.5,y+0.1);
    glEnd();
}
 glPopMatrix();

glPushMatrix();                 //code for eyes of second smiley
glTranslatef(-0.6,0.08,00);
glColor3f(0.4,0.0,0.0);
glutSolidTorus(0.005,0.08,100,100);     //spectacles of smiley
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
}

void heart()
{
     glPushMatrix();                      //code for heart
    glTranslatef(-0.25,0.25,0);
    glScalef(0.5,0.5,0.0);
    glColor3f(0.8,0.0,0.0);
    glPushMatrix();
    glTranslatef(-0.08,0.0,0.0);
    glColor3f(0.8,0.0,0.0);
    glutSolidSphere(0.1,80,80);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.08,0.0,0.0);
    glutSolidSphere(0.1,80,80);
    glColor3f(0.8,0.0,0.0);
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(-0.18,-0.040);
    glVertex2f(0.18,-0.040);
    glVertex2f(0.0,-0.2);
    glPopMatrix();
    glEnd();
    glPopMatrix();
   glPopMatrix();
}

/* Callback handler for window re-paint event */
void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear the color buffer
   glMatrixMode(GL_MODELVIEW);    // To operate on the model-view matrix
   glLoadIdentity();              // Reset model-view matrix

  {glTranslatef(ballX, ballY, 0.0f);  // Translate to (xPos, yPos)
   // Use triangular segments to form a circle
   {glPushMatrix();
   Osmiley();
   Csmiley();
   heart();
   glPopMatrix();
   }

   glutSwapBuffers();  // Swap front and back buffers (of double buffered mode)
// Animation Control - compute the location for the next refresh
   ballX += xSpeed;
   ballY += ySpeed;
   // Check if the smiley exceeds the edges
  {if (ballX > ballXMax) {
      ballX = ballXMax;
      xSpeed = -xSpeed;
   } else if (ballX < ballXMin) {
      ballX = ballXMin;
      xSpeed = -xSpeed;
   }
   if (ballY > ballYMax) {
      ballY = ballYMax;
      ySpeed = -ySpeed;
   } else if (ballY < ballYMin) {
      ballY = ballYMin;
      ySpeed = -ySpeed;
   }
   glutPostRedisplay();
  }
  }
}

/* Call back when the windows is re-sized */
void reshape(GLsizei width, GLsizei height) {
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (width >= height) {
      clipAreaXLeft   = -1.0 * aspect;
      clipAreaXRight  = 1.0 * aspect;
      clipAreaYBottom = -1.0;
      clipAreaYTop    = 1.0;
   } else {
      clipAreaXLeft   = -1.0;
      clipAreaXRight  = 1.0;
      clipAreaYBottom = -1.0 / aspect;
      clipAreaYTop    = 1.0 / aspect;
   }
   gluOrtho2D(clipAreaXLeft-0.5, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
   ballXMin = clipAreaXLeft + ballRadius;
   ballXMax = clipAreaXRight - ballRadius;
   ballYMin = clipAreaYBottom + ballRadius;
   ballYMax = clipAreaYTop - ballRadius;

}

/* Called back when the timer expired */
void Timer(int value)
{ glutTimerFunc(50, Timer, 300); // subsequent timer call at milliseconds
glutPostRedisplay();    // Post a paint request to activate display()
}
   /*Called back when Mouse button is clicked*/
void mouse(int btn,int state,int x,int y)       //mouse click function
{
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_UP)
    { exit(0); }
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
    { exit(0);            }
}
  /*Called back when key of keyboard is pressed*/
void keyboardkey(unsigned char key,int x,int y)          //keyboard function
{
    switch(key)
    {
        case 27:exit(0);             //esc key
        break;
        case 32:exit(0);             // spacebar key
        break;
        case 13:exit(0);             //enter key
        break;
    }

}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutCreateWindow("Screen Saver");// Create window with given title
   glutFullScreen();
   //init();
   glutDisplayFunc(display);     // Register callback handler for window re-paint
   glutReshapeFunc(reshape);     // Register callback handler for window re-shape
   glutTimerFunc(0, Timer, 0);   // First timer call immediately
   glutKeyboardFunc(keyboardkey);
   glutMouseFunc(mouse);                   // Our own OpenGL initialization
   PlaySound(TEXT("C://a.wav"), NULL ,SND_ASYNC|SND_FILENAME|SND_LOOP);
   glutMainLoop();               // Enter event-processing loop
   return 0;
}
