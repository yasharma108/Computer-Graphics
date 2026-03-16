#include<stdio.h>
#include<GL/glut.h>

float cube[8][3] = {
{-2,-2,-2},{2,-2,-2},{2,2,-2},{-2,2,-2},
{-2,-2,2},{2,-2,2},{2,2,2},{-2,2,2}
};

float tx,ty,tz;

void drawCube(float v[8][3])
{
    glBegin(GL_LINE_LOOP);
    glVertex3fv(v[0]); glVertex3fv(v[1]);
    glVertex3fv(v[2]); glVertex3fv(v[3]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3fv(v[4]); glVertex3fv(v[5]);
    glVertex3fv(v[6]); glVertex3fv(v[7]);
    glEnd();

    glBegin(GL_LINES);
    for(int i=0;i<4;i++)
    {
        glVertex3fv(v[i]);
        glVertex3fv(v[i+4]);
    }
    glEnd();
}

void display()
{
    float t_cube[8][3];

    for(int i=0;i<8;i++)
    {
        t_cube[i][0] = cube[i][0] + tx;
        t_cube[i][1] = cube[i][1] + ty;
        t_cube[i][2] = cube[i][2] + tz;
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    drawCube(cube);

    glColor3f(0,0,1);
    drawCube(t_cube);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glOrtho(-10,10,-10,10,-10,10);
}

int main(int argc,char**argv)
{
    printf("Enter tx ty tz: ");
    scanf("%f%f%f",&tx,&ty,&tz);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);

    glutCreateWindow("3D Translation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}