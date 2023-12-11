
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

class LineClippingApp {
private:
    int minX, minY, maxX, maxY;
    int fstX, fstY, sndX, sndY;
    int code1[4] = {0, 0, 0, 0};
    int code2[4] = {0, 0, 0, 0};
    bool isReject = false;

public:
    void display() {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0, 1.0, 0.0);
        glRecti(minX, minY, maxX, maxY);

        glColor3f(0.0, 0.0, 0.0);
        cohenSuth();

        glFlush();
    }
    LineClippingApp() {
        cout << "Enter Minimum window co-ordinates: ";
        cin >> minX >> minY;
        cout << "Enter Maximum window co-ordinates: ";
        cin >> maxX >> maxY;
        cout << "Enter co-ordinates of first point of line: ";
        cin >> fstX >> fstY;
        cout << "Enter co-ordinates of second point of the line: ";
        cin >> sndY >> sndX;

        
    }


    int getcode1(int x, int y) {
        int code1[4] = {0, 0, 0, 0};

        if (y > maxY) {
            code1[0] = 1;
        }

        if (y < minY) {
            code1[1] = 1;
        }

        if (x > maxX) {
            code1[2] = 1;
        }

        if (x < minX) {
            code1[3] = 1;
        }

        return code1[0] * 1000 + code1[1] * 100 + code1[2] * 10 + code1[3];
    }

    int getcode2(int x, int y) {
        int code2[4] = {0, 0, 0, 0};

        if (y > maxY) {
            code2[0] = 1;
        }

        if (y < minY) {
            code2[1] = 1;
        }

        if (x > maxX) {
            code2[2] = 1;
        }

        if (x < minX) {
            code2[3] = 1;
        }

        return code2[0] * 1000 + code2[1] * 100 + code2[2] * 10 + code2[3];
    }

    void drawLine(int x0, int y0, int x1, int y1) {
        glBegin(GL_LINES);
        glVertex2i(x0, y0);
        glVertex2i(x1, y1);
        glEnd();
    }

    void cohenSuth() {
        int codeRes1 = getcode1(fstX, fstY);
        int codeRes2 = getcode2(sndX, sndY);

        if (codeRes1 == 0 && codeRes2 == 0 && !isReject) {
            drawLine(fstX, fstY, sndX, sndY);
        } else {
            for (int i = 0; i < 4; i++) {
                if (code1[i] == code2[i] && code1[i] == 1) {
                    isReject = true;
                    break;
                }
            }

            if (isReject) {
                cout << "Both points rejected" << endl;
            } else {
                for (int i = 0; i < 4; i++) {
                    if (code1[i] == 1) {
                        switch (i) {
                            case 0:
                                fstY = maxY;
                                break;
                            case 1:
                                fstY = minY;
                                break;
                            case 2:
                                fstX = maxX;
                                break;
                            case 3:
                                fstX = minX;
                                break;
                        }
                    }

                    if (code2[i] == 1) {
                        switch (i) {
                            case 0:
                                sndY = maxY;
                                break;
                            case 1:
                                sndY = minY;
                                break;
                            case 2:
                                sndX = maxX;
                                break;
                            case 3:
                                sndX = minX;
                                break;
                        }
                    }
                }

                drawLine(fstX, fstY, sndX, sndY);
            }
        }
    }


};

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Clipping with Cohen-Sutherland algorithm");
    LineClippingApp app;
    app.display();
    myInit();
    glutMainLoop();
    return 0;
}
