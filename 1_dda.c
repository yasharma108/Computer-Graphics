#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int x_start, y_start, x_end, y_end;
void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void drawGrid()
{
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_LINES);
    for(int i=-500; i<=500; i+=20)
    {
        glVertex2f(i, -500);
        glVertex2f(i, 500);

        glVertex2f(-500, i);
        glVertex2f(500, i);
    }
    glEnd();
}
void drawAxes()
{
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-500, 0);
        glVertex2f(500, 0);
        glVertex2f(0, -500);
        glVertex2f(0, 500);
    glEnd();
}
void drawDDA()
{
    float dx=x_end-x_start;
    float dy=y_end-y_start;
    float steps=fabs(dx)>fabs(dy) ? fabs(dx):fabs(dy);
    float x_inc=dx/steps;
    float y_inc=dy/steps;
    float x=x_start;
    float y=y_start;
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawAxes();
    glColor3f(1,0,0);
    for(int i=0; i<=steps; i++)
    {
        drawPixel(round(x), round(y));
        x+=x_inc;
        y+=y_inc;
    }
    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(2);
    gluOrtho2D(-500,500,-500,500);
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    printf("Enter the coordinates x1 and y1: ");
    scanf("%d %d", &x_start, &y_start);
    printf("Enter the coordinates x2 and y2: ");
    scanf("%d %d", &x_end, &y_end);
    int ws1, ws2;
    printf("Enter the window size: ");
    scanf("%d %d", &ws1, &ws2);
    glutInitWindowSize(ws1, ws2);
    glutCreateWindow("DDA line drawing using GLUT");

    init();
    glutDisplayFunc(drawDDA);
    glutMainLoop();
    return 0;
}