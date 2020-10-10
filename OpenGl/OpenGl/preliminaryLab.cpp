
//------PRELIMINARY LAB----------//
//110855	Joel Odhiambo	Group B
//111758	Asmaa Hargura	Group B
//111759	Trevor Ikky	Group B
//110740	Dalton Mwandaware	Group B
//N.B TO VIEW A SHAPE COMMENT OUT THE GIVEN DISPLAY FUNCTION
#include <Windows.h>
#include <GL\glew.h>
#include<GL\glut.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);//window color is white
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);//Define the cartesian(x min, x max,y min, y max)

}

//Draw Squares
void squares()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.5, 0.0);//Drawing a orange line
	glPointSize(5.0);//Set the width of the line

	//Start by drawing inner square
	glBegin(GL_LINES);
	glVertex2i(35.0, 135.0);
	glVertex2i(135.0, 135.0);
	glVertex2i(135.0, 135.0);
	glVertex2i(135.0, 35.0);
	glVertex2i(135.0, 35.0);
	glVertex2i(35.0, 35.0);
	glVertex2i(35.0, 35.0);
	glVertex2i(35.0, 135.0);

	glEnd();

	//Draw outer square
	glBegin(GL_LINES);
	glVertex2i(20.0, 150.0);
	glVertex2i(150.0, 150.0);
	glVertex2i(150.0, 150.0);
	glVertex2i(150.0, 20.0);
	glVertex2i(150.0, 20.0);
	glVertex2i(20.0, 20.0);
	glVertex2i(20.0, 20.0);
	glVertex2i(20.0, 150.0);


	glEnd();
	glFlush();//Allows fast execution of the statements
}

//Draw Triangles
void triangles() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.5, 0.0);
	glPointSize(5.0);

	glBegin(GL_LINES);
	glVertex2i(100, 100);
	glVertex2i(150, 200);
	glVertex2i(150, 200);
	glVertex2i(200, 100);
	glVertex2i(200, 100);
	glVertex2i(100, 100);

	glEnd();

	glBegin(GL_LINES);
	glVertex2i(100, 170);
	glVertex2i(200, 170);
	glVertex2i(200, 170);
	glVertex2i(150, 70);
	glVertex2i(150, 70);
	glVertex2i(100, 170);

	glEnd();
	glFlush();

}

// Draw Circles
void circles()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(5.0);
	int i;
	int x = 60;// Midpoint of circle
	int y = 60;//Midpoint of circle
	int radius = 50;
	int lineAmount = 100; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * 3.14159265358979323846;

	glBegin(GL_LINE_LOOP);//Circle 1
	for (i = 0; i <= lineAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / lineAmount)),
			y + (radius * sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);//Circle 2
	for (i = 0; i <= lineAmount; i++) {
		x = 130;
		y = 60;
		radius = 50;
		glVertex2f(
			x + (radius * cos(i * twicePi / lineAmount)),
			y + (radius * sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);//Circle 3
	for (i = 0; i <= lineAmount; i++) {
		x = 90;
		y = 130;
		radius = 50;
		glVertex2f(
			x + (radius * cos(i * twicePi / lineAmount)),
			y + (radius * sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
	glFlush();//Allows fast execution of the statements
}

//Draw Arc Section

const double RADIUS = 200;
const double OFFSET = (double)RADIUS;
const int POINT_COUNT = 360;

const double PI() {
	return std::acos(-1); //get value of PI from arc cosine
}
void draw_arc() {

	glClear(GL_COLOR_BUFFER_BIT); //Clear buffer
	glColor3f(0.0, 0.0, 1.0); //define point color
	glPointSize(4.0); //define point size
	glBegin(GL_POINTS);

	for (int i = 0; i < POINT_COUNT; i++)
	{
		double angle = 2.0f * PI() * (double)i / POINT_COUNT; //get angle in radians to calculate x,y coordinates
		double deg_angle = (angle * 57.29578); //convert rad to degrees
		std::cout << deg_angle << std::endl;

		if (deg_angle >= 150 && deg_angle <= 320) { //define where the points should not be drawn
			continue;
		}
		else {
			double x_coord = RADIUS * cos(angle) + 100 + OFFSET; //calculate x coordinate from angle in rad and add offset to center the arc
			double y_coord = RADIUS * sin(angle) + 100 + OFFSET; //calculate x coordinate from angle in rad and add offset to center the arc
			glVertex2d(x_coord, y_coord); //create a 2d point
		}
	}


	glEnd();
	glFlush();
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);//top left
	glutInitWindowSize(500, 500);
	glutCreateWindow("Preliminary Lab");
	
	init();
	
	glutDisplayFunc(squares);
	//glutDisplayFunc(triangles);
	//glutDisplayFunc(draw_arc);
	//glutDisplayFunc(circles);
	
	
	glutMainLoop();
	return 0;
}