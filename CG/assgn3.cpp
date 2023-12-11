
#include<GL/glut.h>
#include<bits/stdc++.h>


using namespace std;
int val = 0;

class shapes {
public:
     int r1 = 100, r2 = 50;
     float l = 200;
     float b = 300;
     float cx = l / 2, cy = (b / 2) + 4, r = (l / 4) * pow(2, 0.7);
     void plot(int a, int b, int c = 0) {
          glBegin(GL_POINTS);
          glColor3f(c, 0, 0);
          glVertex2i(a, b);
          glEnd();
     }
     void line(float x1, float y1, float x2, float y2) {

          float stp;
          float dx = x2 - x1;
          float dy = y2 - y1;
          stp=max(abs(dx),abs(dy));
          float xinc = dx / stp;
          float yinc = dy / stp;
          float x = x1;
          float y = y1;
          plot(x,y);
          int k;
          for (k = 1;k <= stp;k++)
          {
               x = x + xinc;
               y = y + yinc;

               glBegin(GL_POINTS);

               glColor3f(1.0, 0.0, 0.0);
               glVertex2i(x, y);
               glEnd();

          }

     }
     void circle(int x1, int y1, int r)
     {
          float x, y, p;
          p = 5 / 4 - r;
          x = 0;
          y = r;

          while (x <= y)
          {
               if (p < 0)
               {
                    p += 2 * x + 3;
                    x += 1;
               }
               else if (p >= 0)
               {
                    p += 2 * (x - y) + 5;
                    x += 1;
                    y -= 1;
               }

               plot(x + x1, y + y1, 1);
               plot(x + x1, -y + y1, 1);
               plot(-x + x1, y + y1, 1);
               plot(-x + x1, -y + y1, 1);
               plot(y + x1, x + y1, 1);
               plot(-y + x1, x + y1, 1);
               plot(y + x1, -x + y1, 1);
               plot(-y + x1, -x + y1, 1);
          }

     }

     void createPattern1() {
          glClear(GL_COLOR_BUFFER_BIT);
          line(0, 100, 2 * 25 * sqrt(3), -50);
          line(-2 * 25 * sqrt(3), -50, 2 * 25 * sqrt(3), -50);
          line(0, 100, -2 * 25 * sqrt(3), -50);
          circle(0, 0, 100);
          circle(0, 0, 50);
     }

     void createPattern2() {
          glClear(GL_COLOR_BUFFER_BIT);
          float x = 0;
          float y = 10;
          float l = 200;
          float b = 300;
          line(x, y, x + l, y);

          line(x, y, x, y + l + 100);

          line(x + l, y, x + l, y + b);

          line(x, y + b, x + l, y + b);

          //diamond
          line((x + l) / 2, y, x, (y + b) / 2);
          line(x, (y + b) / 2, (x + l) / 2, y + b);
          line((x + l) / 2, y + b, (x + l), (y + b) / 2);
          line((x + l) / 2, y, x + l, (y + b) / 2);

          //circle
          float cx = l / 2, cy = (b / 2) + 4, r = (l / 4) * pow(2, 0.7);
          circle(cx, cy, r);
     }

     void pattern3() {
          glClear(GL_COLOR_BUFFER_BIT);
          line(0, 0, 240, 0);
          line(0, 0, 0, 160);
          line(0, 160, 240, 160);
          line(240, 0, 240, 160);
          line(60, 40, 60, 120);
          line(60, 40, 180, 40);
          line(180, 40, 180, 120);
          line(60, 120, 180, 120);
          line(0, 80, 120, 160);
          line(120, 160, 240, 80);
          line(240, 80, 120, 0);
          line(120, 0, 0, 80);
     }


};

shapes sp;



void keyboard(unsigned char key, int x, int y)
{
     if (key == 27)               // Esc key
          exit(0);
     else if (key == 'D' || key == 'd') {
          val = 1;
     }
     else if (key == 'B' || key == 'b') {
          val = 2;
     }
     else if (key == 'M' || key == 'm') {
          val = 3;
     }

     glutPostRedisplay();
}

void init()
{
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-500, 500, -500, 500);
}

void display(void)
{
     //glClear(GL_COLOR_BUFFER_BIT);
     if (val == 1) {
          sp.createPattern1();

     }
     else if (val == 2) {
          sp.createPattern2();

     }
     else if (val == 3) {
          sp.pattern3();

     }
     glFlush();
}

int main(int argc, char** argv)
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(500, 500);
     glutInitWindowPosition(100, 100);
     glutCreateWindow("Pattern");
     glutDisplayFunc(display);
     glutKeyboardFunc(keyboard);
     init();
     glutMainLoop();
}