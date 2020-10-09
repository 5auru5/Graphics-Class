//Arya Habibi s1 a_h862
#define GL_SILENCE_DEPRECATION
#include <OPenGl/gl.h>
#include <OPenGl/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <cmath>

const int screenHeight = 600; // window height is 480
const int screenWidth = 800 ; //window width is 640
//<<<<<<<<<<<<<<<<<<<<< Prototypes >>>>>>>>>>>>>>>>>>
    void exit(int) ;
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
     
    glClearColor(1.0,1.0,1.0,0.0);       // set white background color
    glColor3f(0.0f, 0.0f, 0.0f);          // set the drawing color
    glPointSize(4.0);               // a ?dot? is 4 by 4 pixels
    glLineWidth(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     glOrtho(-1.5,1.5,-1.5,1.5,-1.5,1.5);
}
void drawCube(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
      glBegin(GL_QUADS);
         glColor3f(1.0f, 1.0f, 0.0f);
         glVertex3f( 1.0f, 1.0f, -1.0f);
         glVertex3f(-1.0f, 1.0f, -1.0f);
         glVertex3f(-1.0f, 1.0f,  1.0f);
         glVertex3f( 1.0f, 1.0f,  1.0f);
         // Bottom face
         glVertex3f( 1.0f, -1.0f,  1.0f);
         glVertex3f(-1.0f, -1.0f,  1.0f);
         glVertex3f(-1.0f, -1.0f, -1.0f);
         glVertex3f( 1.0f, -1.0f, -1.0f);
         // Front face
         glVertex3f( 1.0f,  1.0f, 1.0f);
         glVertex3f(-1.0f,  1.0f, 1.0f);
         glVertex3f(-1.0f, -1.0f, 1.0f);
         glVertex3f( 1.0f, -1.0f, 1.0f);
         // Back face
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0);
        glVertex3f( 1.0f,  1.0f, -1.0f);
         // Left face
         glVertex3f(-1.0f,  1.0f,  1.0f);
         glVertex3f(-1.0f,  1.0f, -1.0f);
         glVertex3f(-1.0f, -1.0f, -1.0f);
         glVertex3f(-1.0f, -1.0f,  1.0f);
         // Right face
         glVertex3f(1.0f,  1.0f, -1.0f);
         glVertex3f(1.0f,  1.0f,  1.0f);
         glVertex3f(1.0f, -1.0f,  1.0f);
         glVertex3f(1.0f, -1.0f, -1.0f);
      glEnd();
    glFlush();
}
void drawPoint(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2f(0,0);
    glEnd();
    glFlush();
}
void drawNGon(int n)
{
    glClear(GL_COLOR_BUFFER_BIT);
    float deg, vertexX, vertexY, rotation, degToRad;
    rotation = 360/n;
    deg = rotation/2 +100;
    degToRad = 180/3.14159;
    glBegin(GL_POLYGON);
    for(int i = 0; i < n; i++,deg+= rotation)
    {
        vertexX = 0.5 * sin(deg/degToRad);
        vertexY = 0.5 * sin((90 - deg)/degToRad);
        glVertex3f(vertexX,vertexY,0);
    }
    glEnd();
    glFlush();
}
void drawLine(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    glVertex2i(-.5, .5);
    glVertex2i(1, 1);
    glEnd();
    glFlush();
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);    // clear the screen
    glBegin(GL_POLYGON);
    glEnd();
   //; glFlush();          // send all output to display
}
//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>
void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
    switch(theKey)
    {
        case 's': glColor3f(1, 1, 0);drawNGon(4);
            break;
        case 'S': glColor3f(1, 1, 0);drawNGon(4);
            break;
        case 'T': glColor3f(1, 0, 1);drawNGon(3);
            break;
        case 't': glColor3f(1, 0, 1);drawNGon(3);
            break;
        case 'l': glColor3f(1, .5, .5); drawLine();
            break;
        case 'L': glColor3f(1, .5, .5); drawLine();
            break;
        case 'p': glColor3f(0, 0, 0); drawPoint();
            break;
        case 'P':glColor3f(0, 0, 0);  drawPoint();
            break;
        case 'h': drawNGon(6);
            break;
        case 'H': drawNGon(6);
            break;
        case 'C':  drawNGon(30);
            break;
        case 'c': drawNGon(30);
            break;
        case 'u': drawCube();
            break;
        case 'U': drawCube();
            break;
        case 'Q': exit(-1); //terminate the program
        case 'q': exit(-1); //terminate the program
        default:
        break; // do nothing
    }
    glutPostRedisplay();
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int     main(int argc, char** argv)
{
    glutInit(&argc, argv);          // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
    glutInitWindowSize(800 ,600);     // set window size
    glutInitWindowPosition(100, 150); // set window position on screen
    glutCreateWindow("Type S:square p:point t:triangle h:hexagon c:circle u:cube or Type Q or q to quit") ; // open the screen window
    glutDisplayFunc(myDisplay);     // register redraw function
        glutKeyboardFunc(myKeyboard); // register the keyboard action function
    myInit();
    glutMainLoop();              // go into a perpetual loop
}


