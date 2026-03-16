#include<stdio.h>
#include<GL/glut.h>

float cube[8][3]={
{-2,-2,-2},{2,-2,-2},{2,2,-2},{-2,2,-2},
{-2,-2,2},{2,-2,2},{2,2,2},{-2,2,2}
};

float d=5;

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
    float p_cube[8][3];

    for(int i=0;i<8;i++)
    {
        p_cube[i][0]=cube[i][0]/(1+cube[i][2]/d);
        p_cube[i][1]=cube[i][1]/(1+cube[i][2]/d);
        p_cube[i][2]=cube[i][2];
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);

    drawCube(p_cube);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glOrtho(-10,10,-10,10,-10,10);
}

int main(int argc,char**argv)
{
    printf("Enter distance d: ");
    scanf("%f",&d);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);

    glutCreateWindow("Perspective Projection");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}