#include<stdio.h>
#include<GL/glut.h>

float angle;
int axis;

void drawCube()
{
    glutWireCube(2);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    if(axis==1)
        glRotatef(angle,1,0,0);

    if(axis==2)
        glRotatef(angle,0,1,0);

    if(axis==3)
        glRotatef(angle,0,0,1);

    glColor3f(0,0,0);

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
    printf("Enter rotation angle: ");
    scanf("%f",&angle);

    printf("1 → X axis\n2 → Y axis\n3 → Z axis\nChoose axis: ");
    scanf("%d",&axis);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(700,700);

    glutCreateWindow("3D Rotation");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
}