#include <windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
int x,y,xc,yc,r;
double a=sqrt(2);
void display()
{
    cout << a;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex2d(xc, yc);
    for(x=0; x<=r/a; x++)
    {
        y=sqrt(pow(r,2) - pow(x,2));

        glVertex2d(x+xc, y+yc);
        glVertex2d(x+xc, -y+yc);
        glVertex2d(-x+xc, y+yc);
        glVertex2d(-x+xc, -y+yc);
        glVertex2d(y+xc, x+yc);
        glVertex2d(y+xc, -x+yc);
        glVertex2d(-y+xc, x+yc);
        glVertex2d(-y+xc, -x+yc);
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    cout << "Enter Xc : ";
    cin >> xc ;
    cout << "Enter Yc : ";
    cin >> yc;
    cout << "Enter r : ";
    cin >> r;
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hello OpenGL");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-200,200,-200,200,-9,9);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

// 20 20 50
