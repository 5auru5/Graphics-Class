#define GL_SILENCE_DEPRECATION
#include <OPenGl/gl.h>
#include <OPenGl/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
const int screenHeight = 480; // window height is 480
const int screenWidth = 640 ; //window width is 640
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
    glOrtho(0.0, 640.0, 0.0, 480.0, -1.0, 1.0);
}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
    //glBegin(GL_POINTS);
    //glBegin(GL_LINE_STRIP) ;
    glBegin(GL_LINE_LOOP) ;
    glBegin(GL_POLYGON);
    glVertex2i(289, 190);        // Dubhe
    glVertex2i(320,  128) ;        // Merak
    glVertex2i(239,  67) ;        // Phecda
    glVertex2i(194,  101) ;       // Megrez
    glVertex2i(129,  83) ;       // Alioth
    glVertex2i(75,  73) ;       // Mizar
    glVertex2i(74,  74) ;       // Alcor
    glEnd();
    glFlush();          // send all output to display
}
//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>
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
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int     main(int argc, char** argv)
{
    glutInit(&argc, argv);          // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
    glutInitWindowSize(640,480);     // set window size
    glutInitWindowPosition(100, 150); // set window position on screen
    glutCreateWindow("Big Deep - Type Q or q to quit") ; // open the screen window
    glutDisplayFunc(myDisplay);     // register redraw function
        glutKeyboardFunc(myKeyboard); // register the keyboard action function
    myInit();
    glutMainLoop();              // go into a perpetual loop
}

