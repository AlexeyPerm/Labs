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
    int x1 {};
    int y1 {};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0,1.0);
    glBegin(GL_POINTS);
        for (int t = 0; t <= 360; t++) {
            x1 = i*sin(t) + x;
            y1 = i*cos(t) + y;
            glVertex2f(x1, y1);
    }
    glEnd();
    glutSwapBuffers();
}