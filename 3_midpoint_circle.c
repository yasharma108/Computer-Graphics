#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
int xc, yc, r;

void drawPixel(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}
void plotCirclePoints(int x, int y)
{
    drawPixel(xc + x, yc + y);
    drawPixel(xc - x, yc + y);
    drawPixel(xc + x, yc - y);
    drawPixel(xc - x, yc - y);

    drawPixel(xc + y, yc + x);
    drawPixel(xc - y, yc + x);
    drawPixel(xc + y, yc - x);
    drawPixel(xc - y, yc - x);
}
void drawGrid()
{
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_LINES);
    for(int i=-50; i<=50; i++)
    {
        glVertex2f(i, -50);
        glVertex2f(i, 50);

        glVertex2f(-50, i);
        glVertex2f(50, i);
    }
    glEnd();
}
void drawAxes()
{
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-50, 0);
        glVertex2f(50, 0);
        glVertex2f(0, -50);
        glVertex2f(0, 50);
    glEnd();
}
void MidpointCircle()
{
    int x=0;
    int y=r;
    int p=1-r;

    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawAxes();
    glColor3f(1,0,0);
    while(x<=y)
    {
        
        plotCirclePoints(x, y);
        x++;
        if(p<0)
        {
            p+=2*x+1;
        }
        else
        {
            y--;
            p+=(2*x)+1-(2*y);
        }
    }
    glFlush();

}
void init()
{
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(2);
    gluOrtho2D(-50,50,-50,50);
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    printf("Enter the center coordinates x and y: ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the radius r: ");
    scanf("%d", &r);
    int ws1, ws2;
    printf("Enter the window size: ");
    scanf("%d %d", &ws1, &ws2);
    glutInitWindowSize(ws1, ws2);
    glutCreateWindow("Midpoint Circle drawing using GLUT");

    init();
    glutDisplayFunc(MidpointCircle);
    glutMainLoop();
    return 0;
}