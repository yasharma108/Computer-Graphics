#include<stdio.h>
#include<GL/glut.h>

/* Window */
float wxmin=0, wymin=0, wxmax=100, wymax=100;

/* Viewport */
float vxmin=200, vymin=200, vxmax=400, vymax=400;

float polyX[4]={10,80,80,10};
float polyY[4]={10,10,80,80};

void drawOriginal()
{
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++)
        glVertex2f(polyX[i],polyY[i]);
    glEnd();
}

void drawViewport()
{
    glColor3f(0,0,1);

    glBegin(GL_LINE_LOOP);
        glVertex2f(vxmin,vymin);
        glVertex2f(vxmax,vymin);
        glVertex2f(vxmax,vymax);
        glVertex2f(vxmin,vymax);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawOriginal();
    drawViewport();

    /* Transform */
    glColor3f(0,0.6,0);
    glBegin(GL_LINE_LOOP);

    for(int i=0;i<4;i++)
    {
        float xv = vxmin + (polyX[i]-wxmin)*(vxmax-vxmin)/(wxmax-wxmin);
        float yv = vymin + (polyY[i]-wymin)*(vymax-vymin)/(wymax-wymin);

        glVertex2f(xv,yv);
    }

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);

    glutCreateWindow("2D Viewing Transformation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}