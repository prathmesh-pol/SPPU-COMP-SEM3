#include <GL/glut.h>
#include <iostream>

using namespace std;

// Function to draw a circle using DDA algorithm
void drawCircleDDA(int xc, int yc, int radius)
{
    glBegin(GL_POINTS);

    float x = radius;
    float y = 0;
    float epsilon = 1e-5;

    while (x > y + epsilon)
    {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);

        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        y++;

        if (radius * radius - x * x < y * y)
            x--;
    }

    glEnd();
}

// Function to draw a circle using Midpoint algorithm
void drawCircleMidpoint(int xc, int yc, int radius)
{
    glBegin(GL_POINTS);

    int x = radius;
    int y = 0;
    int error = 1 - radius;

    while (x >= y)
    {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);

        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        y++;

        if (error < 0)
            error += 2 * y + 1;
        else
        {
            x--;
            error += 2 * (y - x) + 1;
        }
    }

    glEnd();
}

// Function to draw a circle using Bresenham's algorithm
void drawCircleBresenham(int xc, int yc, int radius)
{
    glBegin(GL_POINTS);

    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);

        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        x++;

        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // Red color for DDA circle
    drawCircleDDA(200, 200, 100);

    glColor3f(0.0, 1.0, 0.0); // Green color for Midpoint circle
    drawCircleMidpoint(400, 200, 100);

    glColor3f(0.0, 0.0, 1.0); // Blue color for Bresenham circle
    drawCircleBresenham(300, 400, 100);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Circle Drawing Algorithms");

    gluOrtho2D(0, 600, 0, 600);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}