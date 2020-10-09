#define GL_SILENCE_DEPRECATION
#include <OPenGl/gl.h>
#include <OPenGl/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <math.h>
///<<<<<<<<<<<<<<<<<<<<< Prototypes >>>>>>>>>>>>>>>>>>
    void exit(int) ;
///--------------- setWindow ---------------------
void setWindow(double left, double right, double bottom, double top)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(left, right, bottom, top, -1.0, 1.0);
}
///---------------- setViewport ------------------
void setViewport(int left, int right, int bottom, int top)
{
glViewport(left, bottom, right - left, top - bottom);
}
///<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
 void myInit(void)
 {
        glClearColor(1.0,1.0,1.0,0.0);       // set white background color
        glColor3f(0.0f, 1.0f, 0.0f);          // set the drawing color (changed to green)
     glLineWidth(4.0);               // a ?line? is 4 pixels
}
///<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
    setWindow(-9.0, 9.0, -0.3, 1.0);            // set the window
    setViewport(0, 800, 0, 600);            // set the viewport
    glBegin(GL_LINE_STRIP);
        for(GLfloat x = -8.0; x < 8.0; x += 0.1)     // draw the plot
            glVertex2f(x, cos((3.14159/2) - (3.14159)*x) / (3.14159 * x)); //changed this
    glEnd();
    glFlush();          // send all output to display
}
///<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>
void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
    switch(theKey)
    {
        case 'Q':
        case 'q':
            exit(-1); //terminate the program
        default:
        break; // do nothing
    }
}
///<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int     main(int argc, char** argv)
{
    glutInit(&argc, argv);          // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
    glutInitWindowSize(800,600);     // set window size
    glutInitWindowPosition(100, 150); // set window position on screen
    glutCreateWindow("Cosc Plot - Type q or Q to quit"); // open the screen window
    glutDisplayFunc(myDisplay);     // register redraw function
        glutKeyboardFunc(myKeyboard); // register the keyboard action function
    myInit();
    glutMainLoop();              // go into a perpetual loop
}


