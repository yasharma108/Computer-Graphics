#include <GL/glut.h>
#include<math.h>
#include <unistd.h>   // for usleep()

/* Boundary = Blue */
float boundaryColor[3] = {0,0,1};

/* Fill = Yellow */
float fillColor[3] = {1,1,0};


/* Get pixel color */
void getPixel(int x,int y,float color[3])
{
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}


/* Draw pixel */
void setPixel(int x,int y)
{
    glColor3f(1,1,0);   // Yellow

    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();

    glFlush();

    usleep(2000);   // Slow animation
}


/* Compare colors */

int sameColor(float a[3], float b[3])
{
    float tolerance = 0.1;

    return (fabs(a[0]-b[0]) < tolerance &&
            fabs(a[1]-b[1]) < tolerance &&
            fabs(a[2]-b[2]) < tolerance);
}


/* Boundary Fill 4-connected */

void boundaryFill4(int x,int y)
{
    float current[3];

    getPixel(x,y,current);

    if(!sameColor(current,boundaryColor) &&
       !sameColor(current,fillColor))
    {

        setPixel(x,y);

        boundaryFill4(x+1,y); // East
        boundaryFill4(x-1,y); // West
        boundaryFill4(x,y+1); // North
        boundaryFill4(x,y-1); // South
    }
}


/* Draw Square */

void drawSquare()
{
    glColor3f(0,0,1);  // Blue boundary

    glLineWidth(3);

    glBegin(GL_LINE_LOOP);

    glVertex2i(15,15);
    glVertex2i(35,15);
    glVertex2i(35,35);
    glVertex2i(15,35);

    glEnd();
}


/* Display */

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    drawSquare();

    glFlush();

    /* Seed point */

    boundaryFill4(25,25);

}


/* Init */

void init()
{
    glClearColor(1,1,1,1);

    glPointSize(2);

    gluOrtho2D(0,50,0,50);
    glReadBuffer(GL_FRONT);
}


/* Main */

int main(int argc,char** argv)
{

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowSize(600,600);

    glutCreateWindow("Boundary Fill Animation");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

}