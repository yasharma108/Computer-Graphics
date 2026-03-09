#include<stdio.h>
#include<GL/glut.h>

float sx,sy,sz;

void drawCube()
{
    glutWireCube(2);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glScalef(sx,sy,sz);

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
    glTranslatef(0,0,-10);
}

int main(int argc,char**argv)
{
    printf("Enter scaling factors sx sy sz: ");
    scanf("%f%f%f",&sx,&sy,&sz);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(700,700);

    glutCreateWindow("3D Scaling");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
}