#include<stdio.h>
#include<GL/glut.h>
#include<unistd.h>

int fillR = 1, fillG = 0, fillB = 0;      
int boundR = 0, boundG = 0, boundB = 0;   

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void getPixel(int x, int y, float *color)
{
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

void boundaryFill(int x, int y)
{
    float color[3];
    getPixel(x, y, color);

    if((color[0] != boundR || color[1] != boundG || color[2] != boundB) &&
       (color[0] != fillR  || color[1] != fillG  || color[2] != fillB))
    {
        glColor3f(fillR, fillG, fillB);
        drawPixel(x, y);
        glFlush();

        usleep(500);  

        boundaryFill(x+1, y);
        boundaryFill(x-1, y);
        boundaryFill(x, y+1);
        boundaryFill(x, y-1);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(200,200);
        glVertex2i(400,200);
        glVertex2i(400,400);
        glVertex2i(200,400);
    glEnd();

    boundaryFill(300,300);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glPointSize(2);
    gluOrtho2D(0,600,0,600);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600,600);
    glutCreateWindow("Boundary Fill - Smooth");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}