#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

#define MAX 20

int n;
int x[MAX], y[MAX];

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void drawGrid()
{
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_LINES);
    for(int i=-50;i<=50;i++)
    {
        glVertex2f(i,-50);
        glVertex2f(i,50);
        glVertex2f(-50,i);
        glVertex2f(50,i);
    }
    glEnd();
}

void drawAxes()
{
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(-50,0);
        glVertex2f(50,0);
        glVertex2f(0,-50);
        glVertex2f(0,50);
    glEnd();
}

void ScanlineFill()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawAxes();

    glColor3f(0,0,0);

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++)
        glVertex2i(x[i],y[i]);
    glEnd();

    int ymin=50, ymax=-50;

    for(int i=0;i<n;i++)
    {
        if(y[i]<ymin) ymin=y[i];
        if(y[i]>ymax) ymax=y[i];
    }

    glColor3f(1,0,0);

    for(int scan=ymin; scan<=ymax; scan++)
    {
        int interX[MAX], count=0;

        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;

            if((y[i]>scan)!=(y[j]>scan))
            {
                interX[count++] =
                x[i] + (scan-y[i])*(x[j]-x[i])/(y[j]-y[i]);
            }
        }

        for(int i=0;i<count-1;i+=2)
        {
            for(int px=interX[i]; px<=interX[i+1]; px++)
                drawPixel(px,scan);
        }
    }

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glPointSize(2);
    gluOrtho2D(-10,10,-10,10);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Vertex %d: ",i+1);
        scanf("%d %d",&x[i],&y[i]);
    }

    glutInitWindowSize(500,500);
    glutCreateWindow("Scanline Polygon Fill");

    init();
    glutDisplayFunc(ScanlineFill);
    glutMainLoop();
}