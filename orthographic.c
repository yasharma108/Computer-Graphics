#include<stdio.h>
#include<GL/glut.h>

float cube[8][3]={
{0, 0, 0},{1, 0, 0},{1, 1, 0},{0, 1, 0},
{0, 0, 1},{1, 0, 1},{1, 1, 1},{0, 1, 1}
};

float iso[8][2];

void drawCube(float v[8][2])
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(v[0][0],v[0][1]);
    glVertex2f(v[1][0],v[1][1]);
    glVertex2f(v[2][0],v[2][1]);
    glVertex2f(v[3][0],v[3][1]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(v[4][0],v[4][1]);
    glVertex2f(v[5][0],v[5][1]);
    glVertex2f(v[6][0],v[6][1]);
    glVertex2f(v[7][0],v[7][1]);
    glEnd();

    glBegin(GL_LINES);
    for(int i=0;i<4;i++)
    {
        glVertex2f(v[i][0],v[i][1]);
        glVertex2f(v[i+4][0],v[i+4][1]);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i=0;i<8;i++)
    {
        float x = cube[i][0];
        float y = cube[i][1];
        float z = cube[i][2];

        iso[i][0] = x - z;
        iso[i][1] = y + (x + z)/2;
    }

    glColor3f(0,0,1);

    drawCube(iso);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10,10,-10,10);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(700,700);

    glutCreateWindow("Isometric Projection");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}