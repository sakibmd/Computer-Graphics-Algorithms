#include <windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
int x=0,y,xc,yc,r;
int d;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,0);
    glBegin(GL_POINTS);
    y=r, d=3-(2*r);
    glVertex2d(xc,yc);
    while(x<=y)
    {
        glVertex2d(x+xc, y+yc);
        glVertex2d(x+xc, -y+yc);
        glVertex2d(-x+xc, y+yc);
        glVertex2d(-x+xc, -y+yc);
        glVertex2d(y+xc, x+yc);
        glVertex2d(y+xc, -x+yc);
        glVertex2d(-y+xc, x+yc);
        glVertex2d(-y+xc, -x+yc);

        if(d<0){
            d = d+ (4*x) + 6;
        }
        else{
            d = d + (4*(x-y)) + 10;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hello OpenGL");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-200,200,-200,200,-9,9);
    cout << "Enter Xc : ";
    cin >> xc ;
    cout << "Enter Yc : ";
    cin >> yc;
    cout << "Enter r : ";
    cin >> r;
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

// 20 20 50

