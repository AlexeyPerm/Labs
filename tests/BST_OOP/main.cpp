#include "Node.h"
#include "Menu.h"
#include "GL/glut.h"
#include <iostream>

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

void init() {
    glLoadIdentity();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
}

void Reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(250, 450);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(250, 150);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(550, 150);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(550, 450);
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char* argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Binary Search Tree Visualization");
    init();

    glutReshapeFunc(Reshape);
    glutDisplayFunc(display);
//    glutKeyboardFunc(handleKeypress);
//    glutDisplayFunc(mainLoop);
//    glutIdleFunc(mainLoop);
    glutMainLoop();

    return 0;
}

