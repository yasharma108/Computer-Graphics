#include<stdio.h>
#include<GL/glut.h>

float cube[8][3]={
{-2,-2,-2},{2,-2,-2},{2,2,-2},{-2,2,-2},
{-2,-2,2},{2,-2,2},{2,2,2},{-2,2,2}
};

void drawCube(float v[8][3])
{
    glBegin(GL_LINE_LOOP);
    glVertex3f(v[0][0], v[0][1], v[0][2]);
    glVertex3f(v[1][0], v[1][1], v[1][2]);
    glVertex3f(v[2][0], v[2][1], v[2][2]);
    glVertex3f(v[3][0], v[3][1], v[3][2]);
    glEnd();

    glBegin(GL_LINES);
    for(int i=0; i<4; i++)
    {
        glVertex3f(v[i][0], v[i][1], v[i][2]);
        glVertex3f(v[i+4][0], v[i+4][1], v[i+4][2]);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 0, 1);
    drawCube(cube);
    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-10, 10, -10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0, 0, -5);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Parallel Projection");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}