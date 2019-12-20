//Code: LinagBarsky Line Clipping
#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

double xmin, xmax, ymin, ymax;    //(x, y)
int n;
double arr_x[100];
double arr_y[100];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    //Window
    glBegin(GL_LINE_LOOP);
    glVertex2d(xmin, ymin);
    glVertex2d(xmax, ymin);
    glVertex2d(xmax, ymax);
    glVertex2d(xmin, ymax);
    glVertex2d(xmin, ymin);
    glEnd();

    glBegin(GL_LINES);
    for(int i=0; i<n*2; i+=2)
    {
        glColor3f(0,0,1);
        //Drawing Input Lines
        glVertex2d(arr_x[i], arr_y[i]);
        glVertex2d(arr_x[i+1], arr_y[i+1]);
        double p[4], q[4];
        p[1]=arr_x[i+1] - arr_x[i]; //x2-x1
        p[0]=-p[1];
        p[3]=arr_y[i+1] - arr_y[i];  //y2-y1
        p[2]=-p[3];

        q[0]=arr_x[i] - xmin;
        q[1]=xmax - arr_x[i];
        q[2]=arr_y[i] - ymin;
        q[3]=ymax - arr_y[i];

        bool flag=false;
        for(int j=0; j<4; j++)
        {
            if(p[j]==0 && q[j]<0)
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
            continue;

        double u1=0, u2=1;
        for(int j=0; j<4; j++)
        {
            if(p[j]<0)
                u1=max(u1,q[j]/p[j]);
            else if(p[j]>0)
                u2=min(u2,q[j]/p[j]);
        }

        if(u1>u2)
            continue;

        glColor3f(1,0,0);
        //Drawing Clipped lines
        glVertex2d(arr_x[i]+p[1]*u1, arr_y[i]+p[3]*u1);
        glVertex2d(arr_x[i]+p[1]*u2, arr_y[i]+p[3]*u2);
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    cout<< "Enter Xmin, Ymin : ";
    cin>>xmin>>ymin;
    cout<< "Enter Xmax, Ymax : ";
    cin>>xmax>>ymax;

    cout<< "Number of lines: ";
    cin>> n;
    cout<< "Lines:" <<endl;
    for(int i=0; i<n*2; i+=2)
    {
        cin>> arr_x[i] >> arr_y[i];
        cin>> arr_x[i+1] >> arr_y[i+1];
    }
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Liang Barsky Algorithm");
    glClearColor(1,1,1,1);
    glOrtho(-100, 400, -150, 350, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
/*
0 0
300 200
10
70 249 -50 219
40 66 -80 -280
45 -70 65 270
97 -50 62 100
82 -100 104 230
104 25 104 0
-144 0 156 227
156 -20 150 230
176 100 196 238
16 -50  222 260
*/
