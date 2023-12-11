#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>


using namespace std;

double ax1,ax2,ay1,ay2;

void display(void){
	double steps,dx,dy,x,y,xinc,yinc;

	dx= ax2-ax1;
	dy= ay2-ay1;
	//d= max(dx,dy);

	if (abs(dx)> abs(dy))
		steps= abs(dx);
	else
		steps=abs(dy);

	xinc= dx/steps;
	yinc=dy/steps;

	x= ax1;
	y= ay1;

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();

	for(int i=0 ; i<=steps; i++){
		x+=xinc;
		y+=yinc;
		glColor3f(0.7,0.1,0.44);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
}
glFlush();
}

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
}

int main(int argc, char *argv[])
{
	cout<<"Enter x1 and y1 :";
	cin>>ax1>>ay1;
	cout<<"Enter x2 and y2 :";
	cin>>ax2>>ay2;


	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("DDA Line Generation");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
return 0;
}
