#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int x_start,y_start,x_end,y_end;
float shx,shy;

void drawPixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void drawGrid()
{
    glColor3f(0.85,0.85,0.85);

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

void drawDDA(float x1,float y1,float x2,float y2)
{
    float dx=x2-x1;
    float dy=y2-y1;

    float steps=fabs(dx)>fabs(dy)?fabs(dx):fabs(dy);

    float x_inc=dx/steps;
    float y_inc=dy/steps;

    float x=x1,y=y1;

    for(int i=0;i<=steps;i++)
    {
        drawPixel(round(x),round(y));
        x+=x_inc;
        y+=y_inc;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGrid();
    drawAxes();

    glColor3f(1,0,0);
    drawDDA(x_start,y_start,x_end,y_end);

    glColor3f(0,0,1);

    drawDDA(x_start+shx*y_start,
            y_start+shy*x_start,
            x_end+shx*y_end,
            y_end+shy*x_end);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glPointSize(4);
    gluOrtho2D(-50,50,-50,50);
}

int main(int argc,char**argv)
{
    int ws;

    printf("Enter x1 y1: ");
    scanf("%d%d",&x_start,&y_start);

    printf("Enter x2 y2: ");
    scanf("%d%d",&x_end,&y_end);

    printf("Enter shear factors shx shy: ");
    scanf("%f%f",&shx,&shy);

    printf("Enter window size: ");
    scanf("%d",&ws);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(ws,ws);

    glutCreateWindow("DDA Shearing");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}