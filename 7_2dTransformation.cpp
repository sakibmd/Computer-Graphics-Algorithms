#include <windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

double how_many_point,V1,V2,theta;
double arr_initial_x[100];
double arr_initial_y[100];
double arr_final_x[100];
double arr_final_y [100];
double pi = 3.1416;
void translation()
{
    cout << "Enter your points : ";
    for(int i=0; i<how_many_point; i++)
    {
        cin >> arr_initial_x[i];
        cin >> arr_initial_y[i];
    }
    cout <<  "Enter Vertex : ";
    cin >> V1 >> V2;

    for(int i=0; i<how_many_point; i++)
    {
        arr_final_x[i] =  arr_initial_x[i]+V1;
        arr_final_y[i] =  arr_initial_y[i]+V2;
    }
}

void rotation()
{
    cout << "Enter your points : ";
    for(int i=0; i<how_many_point; i++)
    {
        cin >> arr_initial_x[i];
        cin >> arr_initial_y[i];
    }
    cout <<  "Enter Theta : ";
    cin >> theta;
    theta = (theta*pi) / 180;
    for(int i=0; i<how_many_point; i++)
    {
        arr_final_x[i] =  ((arr_initial_x[i])*(cos(theta))) - ((arr_initial_y[i])*(sin(theta)));
        arr_final_y[i] =  ((arr_initial_x[i])*(sin(theta))) + ((arr_initial_y[i])*(cos(theta)));
    }

}

void scalling()
{
    cout << "Enter your points : ";
    for(int i=0; i<how_many_point; i++)
    {
        cin >> arr_initial_x[i];
        cin >> arr_initial_y[i];
    }
    cout <<  "Enter Scalling Point : ";
    cin >> V1 >> V2;

    for(int i=0; i<how_many_point; i++)
    {
        arr_final_x[i] =  arr_initial_x[i]*V1;
        arr_final_y[i] =  arr_initial_y[i]*V2;
    }
}

void mirror()
{
    cout << "Enter your points : ";
    for(int i=0; i<how_many_point; i++)
    {
        cin >> arr_initial_x[i];
        cin >> arr_initial_y[i];
    }
    cout <<  "Enter Mirror Point (X-axis = 1, Y-axis = 0): ";
    cin >> V1;

    if(V1==1)
    {
        for(int i=0; i<how_many_point; i++)
        {
            arr_final_x[i] =  arr_initial_x[i];
            arr_final_y[i] =  arr_initial_y[i]*(-1);
        }
    }

    if(V1==0)
    {
        for(int i=0; i<how_many_point; i++)
        {
            arr_final_x[i] =  arr_initial_x[i]*(-1);
            arr_final_y[i] =  arr_initial_y[i];
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2d(0,200);
    glVertex2d(0,-200);
    glVertex2d(200,0);
    glVertex2d(-200,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    for(int i=0; i<how_many_point; i++)
    {
        glVertex2d(arr_initial_x[i],arr_initial_y[i]);
    }
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    for(int i=0; i<how_many_point; i++)
    {
        glVertex2d(arr_final_x[i],arr_final_y[i]);
    }
    glEnd();


    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    cout << "Press 1 for Translation" << endl;
    cout << "Press 2 for Rotation" << endl;
    cout << "Press 3 for Scalling" << endl;
    cout << "Press 4 for Mirror" << endl;
    int n;
    cout << "Choose your Algorithn : ";
    cin >> n;

    if(n==1)
    {
        cout << "How many points : ";
        cin >> how_many_point;
        translation();
    }
    else if(n==2)
    {
        cout << "How many points : ";
        cin >> how_many_point;
        rotation();
    }
    else if(n==3)
    {
        cout << "How many points : ";
        cin >> how_many_point;
        scalling();
    }
    else if(n==4)
    {
        cout << "How many points : ";
        cin >> how_many_point;
        mirror();
    }
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hello OpenGL");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-200,200,-200,200,-9,9);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
// 10 10 100 10 100 100 10 100
