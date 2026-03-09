#include<stdio.h>
#include<GL/glut.h>

float tx,ty,tz;

void drawCube()
{
    glutWireCube(2); // cube of size 2
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(tx,ty,tz); // translation

    glColor3f(1,0,0);
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
    glTranslatef(0,0,-10);
}

int main(int argc,char**argv)
{
    printf("Enter translation factors tx ty tz: ");
    scanf("%f%f%f",&tx,&ty,&tz);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(700,700);

    glutCreateWindow("3D Translation");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
}