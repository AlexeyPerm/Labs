/*
	*	program to draw the tree on openGL
	*	Gets the tree root from main.cpp file
	*	Lines between nodes are drawn using Bresenham Line drawing and circular nodes are drawn using midpoint algorithm
*/

#include <Windows.h>
#include <stdio.h>
#include <gl/GLU.h>
#include "glut/glut.h"
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glu32.lib")

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <climits>
#include <queue>
#include <math.h>
using namespace std;

#define RADIUS 5									//radius of circle
#define SCALE 30									//coordinate scaling factor
#define WINDOW 600									//Size of Window
struct Node* mainroot = NULL;						//root of tree

//Initialize OpenGL
void init(void) {
	glClearColor(0, 0, 0, 0.0);						//set display-window background color to black
	glMatrixMode(GL_PROJECTION);					//set projection paramaters
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

//PlotPixel at given coordinate
void PlotPixel(GLint x, GLint y) {
	y = WINDOW / 2 - y;								//moving origin to top-left, default is bottom-left
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush(); 										//executes all OpenGL functions as quickly as possible
}

//Draw line based on Bresenham Line drawing algorithm
void draw_line(int x0, int y0, int x1, int y1, int dir) {
	//dir=1 for left child
	//printf("line:(%d,%d) to (%d,%d)\n", x0, y0, x1, y1);
	int dx = x1 - x0, dy = y1 - y0;
	int d = 2 * dy - dx;
	int incrE = 2 * dy, incrNE = 2 * (dy - dx);
	int x = x0, y = y0;
	PlotPixel(x, y);

	while (x < x1) {
		if (d <= 0) {								//choose E
			d = d + incrE;
			if (dir) y--;						//if left child decrement y
		}
		else {									//choose NE
			d = d + incrNE;
			if (!dir) y++;
		}
		x++;
		PlotPixel(x, y);
	}
}

//plot pixels based on a circle's symmetry
void draw_circle(int x0, int y0, int x, int y) {
	PlotPixel(x0 + x, y0 + y);
	PlotPixel(x0 + y, y0 + x);
	PlotPixel(x0 - y, y0 + x);
	PlotPixel(x0 - x, y0 + y);
	PlotPixel(x0 - x, y0 - y);
	PlotPixel(x0 - y, y0 - x);
	PlotPixel(x0 + y, y0 - x);
	PlotPixel(x0 + x, y0 - y);
}

//Draw circle using midpoint circle algorithm
void MidpointCircle(int x0, int y0) {
	//printf("Circle: (%d, %d)\n", x0, y0);
	int x = 0, y = RADIUS;
	int d = 1 - RADIUS;
	int deltaE = 3, deltaSE = -2 * RADIUS + 5;
	draw_circle(x0, y0, x, y);

	while (y > x) {
		if (d < 0) {								//select E
			d = d + deltaE;
			deltaE = deltaE + 2;
			deltaSE += 2;
		}
		else {									//select SE
			d = d + deltaSE;
			deltaE += 2;
			deltaSE += 4;
			y--;
		}
		x++;
		draw_circle(x0, y0, x, y);
	}
}

//function to convert integer to string
string to_string(int n) {
	string str;
	while (n) {
		str.push_back(n % 10 + 48);
		n = n / 10;
	}
	reverse(str.begin(), str.end());
	return str;
}

//Write the data inside the drawn node
void drawText(int data, int x0, int y0) {
	glColor3f(0.0, 1.0, 0.0);                                         //change data color to green
	GLvoid* font_style = GLUT_BITMAP_TIMES_ROMAN_24;
	y0 = WINDOW / 2 - y0 - RADIUS / 2;
	x0 = x0 - RADIUS / 2;                                             //bring str to center of circle
	string str = to_string(data);
	glRasterPos2f(x0, y0);
	for (int i = 0; i < str.size(); i++) {
		glutBitmapCharacter(font_style, str[i]);
		//cout<<"print"<<str[i]<<" ";
	}
	//cout<<endl;
	glColor3f(1.0, 0.0, 0.0);											//change drawing color back to red
}

//Function to remove part of line that lies inside node's circle
pair<pair<int, int>, pair<int, int> > removeRad(float x0, float y0, float x1, float y1) {
	float delx = x1 - x0, dely = y1 - y0;
	float mod = sqrt(delx * delx + dely * dely);
	delx = delx / mod * RADIUS;
	dely = dely / mod * RADIUS;

	x0 = x0 + delx;
	x1 = x1 - delx;
	y0 = y0 + dely;
	y1 = y1 - dely;
	return make_pair(make_pair(x0, y0), make_pair(x1, y1));
}

//Function to process the tree and call appropriate line and circle drawing functions at appropriate coordinates 
void draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);

	struct Node* root = mainroot, * current;
	queue<struct Node*> Q;
	pair<pair<int, int>, pair<int, int> > p;
	Q.push(root);
	int x0, y0, x1, y1;
	while (!Q.empty()) {							//BFS of tree
		root = Q.front();
		Q.pop();
		x0 = SCALE * (root->x + 1);
		y0 = SCALE * (root->y + 1);
		MidpointCircle(x0, y0);					//draw circle
		drawText(root->data, x0, y0);			//draw node value
		if (root->left) {							//if left exists
			current = root->left;
			Q.push(current);
			x1 = SCALE * (current->x + 1);
			y1 = SCALE * (current->y + 1);

			p = removeRad(x0, y0, x1, y1);
			int x02 = p.first.first;
			int y02 = p.first.second;
			x1 = p.second.first;
			y1 = p.second.second;

			draw_line(x1, y1, x02, y02, 1);
		}
		if (root->right) {						//if right exists
			current = root->right;
			Q.push(current);
			x1 = SCALE * (current->x + 1);
			y1 = SCALE * (current->y + 1);

			p = removeRad(x0, y0, x1, y1);
			int x02 = p.first.first;
			int y02 = p.first.second;
			x1 = p.second.first;
			y1 = p.second.second;

			draw_line(x02, y02, x1, y1, 0);
		}
	}
	PlotPixel(WINDOW, WINDOW);
}

void draw_main(struct Node* root, int height, int argc, char* argv[]) {
	mainroot = root;

	//glut functions
	glutInit(&argc, argv);																//initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);										//initialize display mode
	glutInitWindowSize(WINDOW, WINDOW);
	glutInitWindowPosition(50, 50);														//Position of top-left corner
	glutCreateWindow("Binary trees");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();																		//display everything and wait

}