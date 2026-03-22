#include<stdio.h>
#include<GL/glut.h>

float cube[8][3]={
{-2,-2,-2},{2,-2,-2},{2,2,-2},{-2,2,-2},
{-2,-2,2},{2,-2,2},{2,2,2},{-2,2,2}
};

void drawCube()
{
    glBegin(GL_LINE_LOOP);
    glVertex3fv(cube[0]); glVertex3fv(cube[1]);
    glVertex3fv(cube[2]); glVertex3fv(cube[3]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3fv(cube[4]); glVertex3fv(cube[5]);
    glVertex3fv(cube[6]); glVertex3fv(cube[7]);
    glEnd();

    glBegin(GL_LINES);
    for(int i=0;i<4;i++)
    {
        glVertex3fv(cube[i]);
        glVertex3fv(cube[i+4]);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    /* CAMERA VIEW */
    gluLookAt(8,8,8,   // eye
              0,0,0,   // look at
              0,1,0);  // up vector

    glColor3f(0,0,1);
    drawCube();

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60,1,1,50);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(700,700);

    glutCreateWindow("3D Viewing Transformation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}