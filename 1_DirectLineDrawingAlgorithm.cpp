#include <windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

double X11,Y11,X22,Y22,X,Y,m,b;

int roundFunc(double point){
    if(point-int(point)>=0.5)
        return (int)point+1;
    else
        return int(point);
}

void display()
{

    m = (Y22-Y11)/(X22-X11);
    b= Y11 - (m*X11);

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(1,1,1);

    if(fabs(m)<1)
    {
        if(X11>X22)
        {
            swap(X11,X22);
            swap(Y11,Y22);
        }
        glVertex2d(X11,roundFunc(Y11));
        X = X11;
        while(X<X22)
        {
            X++;
            Y = (m*X) + b;
            glVertex2d(X,roundFunc(Y));
            printf("%lf %lf\n",X,Y);
        }
    }
    else
    {
        if(Y11>Y22)
        {
            swap(X11,X22);
            swap(Y11,Y22);
        }
        glVertex2d(roundFunc(X11),Y11);
        Y = Y11;
        while(Y<Y22)
        {
            Y++;
            X = (Y-b)/m;
            glVertex2d(roundFunc(X),Y);
            printf("%lf %lf\n",X,Y);
        }
    }


    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    cin >> X11 >> Y11 >> X22 >> Y22; //20 30 95 80
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hello OpenGL");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-200,200,-200,200,-9,9);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

