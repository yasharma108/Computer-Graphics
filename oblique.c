#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

float cube[8][3]={
{0, 0, 0},{1, 0, 0},{1, 1, 0},{0, 1, 0},
{0, 0, 1},{1, 0, 1},{1, 1, 1},{0, 1, 1}
};

float proj[8][3];

float L;
float angle;

void drawCube(float v[8][3])
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

    float rad = angle * (M_PI/180);

    for(int i=0;i<8;i++)
    {
        proj[i][0] = cube[i][0] + L * cube[i][2] * cos(rad);
        proj[i][1] = cube[i][1] + L * cube[i][2] * sin(rad);
        proj[i][2] = 0;
    }

    glColor3f(0,0,1);
    drawCube(proj);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
}

int main(int argc,char**argv)
{
    printf("Enter angle (30 or 45): ");
    scanf("%f",&angle);

    printf("Enter L factor (1 for Cavalier, 0.5 for Cabinet): ");
    scanf("%f",&L);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,700);

    glutCreateWindow("Oblique Projection");

    init();
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}