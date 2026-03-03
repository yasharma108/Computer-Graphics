#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int xc, yc;
int a, b;

void drawPixel(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void plotEllipsePoints(int x, int y)
{
    drawPixel(xc + x, yc + y);
    drawPixel(xc - x, yc + y);
    drawPixel(xc + x, yc - y);
    drawPixel(xc - x, yc - y);
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

void MidpointEllipse()
{
    int x = 0;
    int y = b;

    float p1;
    float p2;

    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawAxes();

    glColor3f(1, 0, 0);

    // REGION 1
    p1 = (b*b) - (a*a*b) + (0.25*a*a);

    while((2*b*b*x) < (2*a*a*y))
    {
        plotEllipsePoints(x, y);

        x++;

        if(p1 < 0)
        {
            p1 += 2*b*b*x + b*b;
        }
        else
        {
            y--;
            p1 += 2*b*b*x - 2*a*a*y + b*b;
        }
    }

    // REGION 2
    p2 = (b*b*(x+0.5)*(x+0.5)) +
         (a*a*(y-1)*(y-1)) -
         (a*a*b*b);

    while(y >= 0)
    {
        plotEllipsePoints(x, y);

        y--;

        if(p2 > 0)
        {
            p2 -= 2*a*a*y + a*a;
        }
        else
        {
            x++;
            p2 += 2*b*b*x - 2*a*a*y + a*a;
        }
    }

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glPointSize(2);
    gluOrtho2D(-500,500,-500,500);
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    printf("Enter center (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter semi-major axis a: ");
    scanf("%d", &a);

    printf("Enter semi-minor axis b: ");
    scanf("%d", &b);

    int ws1, ws2;
    printf("Enter window size: ");
    scanf("%d %d", &ws1, &ws2);

    glutInitWindowSize(ws1, ws2);
    glutCreateWindow("Midpoint Ellipse Drawing");

    init();
    glutDisplayFunc(MidpointEllipse);
    glutMainLoop();

    return 0;
}