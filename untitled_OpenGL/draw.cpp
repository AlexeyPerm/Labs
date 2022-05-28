#include <cmath>
#include "draw.h"
#include "GL/glut.h"

int w_weight = 800;
int w_height = 600;

void draw_main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(150, 150);
    glutInitWindowSize(w_weight, w_height);
    glutCreateWindow("My First Window");
    glClearColor(.40, .42, .54, .0);
    glutReshapeFunc(reshape);
    glutDisplayFunc(draw);
    glutMainLoop();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    int radius = 30;
    for (int i = 0; i <= 360; i++) {
        float angle = 2 * M_PI * i / (float)360;
        float xofs = cos(angle) * (float)radius;
        float yofs = sin(angle) * (float)radius;
        glVertex2i(x + (int)xofs, y + (int)yofs);
    }
    glEnd();
    glutSwapBuffers();
}