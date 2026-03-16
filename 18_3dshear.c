#include<stdio.h>
#include<GL/glut.h>

float cube[8][3] = {
{-2,-2,-2},{2,-2,-2},{2,2,-2},{-2,2,-2},
{-2,-2,2},{2,-2,2},{2,2,2},{-2,2,2}
};

float sh;
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
    float s_cube[8][3];

    for(int i=0;i<8;i++)
    {
        if(choice==1) // X shear
        {
            s_cube[i][0]=cube[i][0] + sh*cube[i][1];
            s_cube[i][1]=cube[i][1];
            s_cube[i][2]=cube[i][2];
        }

        if(choice==2) // Y shear
        {
            s_cube[i][0]=cube[i][0];
            s_cube[i][1]=cube[i][1] + sh*cube[i][0];
            s_cube[i][2]=cube[i][2];
        }

        if(choice==3) // Z shear
        {
            s_cube[i][0]=cube[i][0];
            s_cube[i][1]=cube[i][1];
            s_cube[i][2]=cube[i][2] + sh*cube[i][0];
        }
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    drawCube(cube);

    glColor3f(0,0,1);
    drawCube(s_cube);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glOrtho(-10,10,-10,10,-10,10);
}

int main(int argc,char**argv)
{
    printf("1 X Shear\n");
    printf("2 Y Shear\n");
    printf("3 Z Shear\n");
    printf("Enter choice: ");

    scanf("%d",&choice);

    printf("Enter shear factor: ");
    scanf("%f",&sh);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,700);

    glutCreateWindow("3D Shearing");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
}