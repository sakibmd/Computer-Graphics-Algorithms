#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
using namespace std;

double X1,X2,Y11,Y22, X,Y,dx,dy, dT, dS, d, dP, dQ;
void gpx()
{
    dx = abs(X2-X1);
    dy = abs(Y22-Y11);

    dS = 2*dy;
    dT = 2*dy- 2*dx;

    dP = 2*dx;
    dQ = 2*dx - 2*dy;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,1);
    glBegin(GL_POINTS);
    if(abs(dy) < abs(dx))
    {
        if(X1>X2)
        {
            swap(X1,X2);
            swap(Y11,Y22);
        }
        d = 2*dy-dx;
        glVertex2d(X1,Y11);
        X=X1;
        Y=Y11;
        while(X<X2)
        {
            X++;
            if(d>=0)
            {
                d=d+dT;
                if(Y11>Y22)
                {
                    Y--;
                }
                else
                {
                    Y++;
                }

            }
            else
            {
                d=d+dS;
            }

            glVertex2d(X, Y);
        }
    }

    else
    {
        if(Y11>Y22)
        {
            swap(X1,X2);
            swap(Y11,Y22);
        }
        d = 2*dx - dy;
        glVertex2d(X1,Y11);
        X=X1;
        Y=Y11;
        while(Y<Y22)
        {
            Y++;
            if(d>=0)
            {
                d=d+dQ;
                if(X1>X2)
                {
                    X--;
                }
                else
                {
                    X++;
                }

            }
            else
                d=d+dP;


            glVertex2d(X, Y);
        }
    }

    glEnd();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    cin >> X1>> Y11;
    cin >> X2>> Y22;
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hello OpenGL");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-400,400,-400,400, -9, 9);
    glutDisplayFunc(gpx);
    glutMainLoop();

    return 0;
}

// 10 100 100 10
// 20 20 250 200
// 250 250 20 20