#include<stdio.h>
#include<GL/glut.h>
#include<unistd.h>
#include<math.h>

void drawPixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void getPixel(int x,int y,float *color)
{
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}

int compareColor(float c1[3], float c2[3])
{
    float tolerance = 0.01;

    return (fabs(c1[0]-c2[0]) < tolerance &&
            fabs(c1[1]-c2[1]) < tolerance &&
            fabs(c1[2]-c2[2]) < tolerance);
}

void floodFill(int x,int y,float oldColor[3])
{
    float color[3];
    getPixel(x,y,color);

    if(compareColor(color, oldColor))
    {
        glColor3f(0,0,1);   
        glFlush();

        usleep(300);        

        floodFill(x+1,y,oldColor);
        floodFill(x-1,y,oldColor);
        floodFill(x,y+1,oldColor);
        floodFill(x,y-1,oldColor);
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

    float oldColor[3];
    getPixel(300,300,oldColor);   

    floodFill(300,300,oldColor);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glPointSize(2);
    gluOrtho2D(0,600,0,600);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutInitWindowSize(600,600);
    glutCreateWindow("Flood Fill - Corrected");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}