#include<windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

// Function to draw a line using DDA algorithm
void drawLineDDA(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps = max(abs(dx), abs(dy));

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1, y = y1;

    glBegin(GL_POINTS);
    glVertex2i(round(x), round(y));

    for (int i = 1; i <= steps; i++)
    {
        x += xIncrement;
        y += yIncrement;

        glVertex2i(round(x), round(y));
    }

    glEnd();
}

// Function to draw a line using Bresenham's algorithm
void drawLineBresenham(float x1, float y1, float x2, float y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x, y;

    if (dx >= dy)
    {
        int decision = 2 * dy - dx;

        glBegin(GL_POINTS);
        glVertex2i(x1, y1);

        for (x = x1, y = y1; x < x2; x++)
        {
            if (decision > 0)
            {
                y += (y2 > y1 ? 1 : -1);
                decision -= 2 * dx;
            }

            decision += 2 * dy;
            glVertex2i(x + 1, y);
        }

        glEnd();
    }
    else
    {
        int decision = 2 * dx - dy;

        glBegin(GL_POINTS);
        glVertex2i(x1, y1);

        for (x = x1, y = y1; y < y2; y++)
        {
            if (decision > 0)
            {
                x += (x2 > x1 ? 1 : -1);
                decision -= 2 * dy;
            }

            decision += 2 * dx;
            glVertex2i(x, y + 1);
        }

        glEnd();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // Red color for the lines

    float x1, y1, x2, y2;

    cout << "Enter the coordinates of the first point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of the second point (x2 y2): ";
    cin >> x2 >> y2;

    // Draw line using DDA algorithm
    glColor3f(1.0, 0.0, 0.0); // Red color for DDA line
    drawLineDDA(x1, y1, x2, y2);

    // Draw line using Bresenham's algorithm
   // glColor3f(0.0, 1.0, 0.0); // Green color for Bresenham's line
 //   drawLineBresenham(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Drawing Algorithms");

    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
