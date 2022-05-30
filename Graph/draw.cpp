#include "draw.h"
#include "GL/glut.h"
#include <cmath>
#include <random>
#include <ctime>
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

void display(){
    srand(time(NULL));
    glClearColor(0.941, 0.973, 1.000, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    int shift = 250;
    int x = 100;
    int y = 100;
    int R = 30;
    const int vertexCount = 7;
    drawFillCircle(x, y, R);
    x += shift;
    drawFillCircle(x, y, R);


    glEnd();
    glutSwapBuffers();
}

static void drawLine(int x1, int y1, int x2, int y2) {
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

static void drawFillCircle(int x, int y, int R) {
    glColor3f(1.0, 1.0, 1.0);
    float x1, y1;
    glBegin(GL_POLYGON);
    for (int i = 0; i <= R; i++) {
        for (int t = 0; t <= 1440; t++) {
            x1 = static_cast<float> (i * std::sin(t) + x);
            y1 = static_cast<float> (i * std::cos(t) + y);
            glVertex2f(x1, y1);
        }
    }
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (int i = R - 1; i <= R; i++) {
        for (int t = 0; t <= 1440; t++) {
            x1 = static_cast<float> (R * std::sin(t) + x);
            y1 = static_cast<float> (R * std::cos(t) + y);
            glVertex2f(x1, y1);
        }
    }
    glEnd();
}