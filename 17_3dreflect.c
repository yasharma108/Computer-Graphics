#include<stdio.h>
#include<GL/glut.h>

float cube[8][3]={
{-2,-2,-2},{2,-2,-2},{2,2,-2},{-2,2,-2},
{-2,-2,2},{2,-2,2},{2,2,2},{-2,2,2}
};

int choice;

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
    float r_cube[8][3];

    for(int i=0;i<8;i++)
    {
        if(choice==1) // XY plane
        {
            r_cube[i][0]=cube[i][0];
            r_cube[i][1]=cube[i][1];
            r_cube[i][2]=-cube[i][2];
        }

        if(choice==2) // YZ plane
        {
            r_cube[i][0]=-cube[i][0];
            r_cube[i][1]=cube[i][1];
            r_cube[i][2]=cube[i][2];
        }

        if(choice==3) // ZX plane
        {
            r_cube[i][0]=cube[i][0];
            r_cube[i][1]=-cube[i][1];
            r_cube[i][2]=cube[i][2];
        }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,0,0);   // original cube
    drawCube(cube);

    glColor3f(0,0,1);   // reflected cube
    drawCube(r_cube);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60,1,1,50);

    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0,0,-15);
}

int main(int argc,char**argv)
{
    printf("1 Reflection about XY plane\n");
    printf("2 Reflection about YZ plane\n");
    printf("3 Reflection about ZX plane\n");
    printf("Enter choice: ");

    scanf("%d",&choice);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(700,700);

    glutCreateWindow("3D Reflection");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}