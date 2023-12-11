
#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

class Color {
public:
    float r;
    float g;
    float b;

    
};

void draw_dda(Point p1, Point p2)
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float x1 = p1.x;
    float y1 = p1.y;
    float step = 0;
    if(abs(dx)>abs(dy))
    {

        step=abs(dx);
    }
    else
    {
        step = abs(dy);

    }

    float xInc = dx / step;
    float yInc = dy / step;

    for(float i = 1;i<=step;i++)
    {
        glVertex2i(x1,y1);
        x1 += xInc;
        y1 += yInc;
    }
}

void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,640,0,480);

}
Color getPixelColor(int x, int y)
{
    Color color;
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,&color);

    return color;

}
void setPixelColor(int x, int y, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void floodFill(int x,int y, Color oldColor, Color newColor)
{
    Color color;
    color = getPixelColor(x,y);
    if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
    {
        setPixelColor(x,y,newColor);
        floodFill(x+1,y,oldColor,newColor);
        floodFill(x,y+1,oldColor,newColor);
        floodFill(x-1,y,oldColor,newColor);
        floodFill(x,y-1,oldColor,newColor);
    }
    return;
}
void onMouseClick(int button, int state, int x,int y)
{
    Color newColor = {1.0f,0.0f,0.0f};
    Color oldColor = {1.0f,1.0f,1.0f};

    floodFill(101,199,oldColor,newColor);

}
void display(void)
{
    Point p1 = {100,100}, p2 = {200,100}, p3={200,200}, p4={100,200};

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    draw_dda(p1,p2);
    draw_dda(p2,p3);
    draw_dda(p3,p4);
    draw_dda(p4,p1);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Open GL");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(onMouseClick);
    glutMainLoop();
    return 0;

}

