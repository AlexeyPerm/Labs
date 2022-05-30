#include "draw.h"
#include "GL/glut.h"
#include <cmath>
#include <string>

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

void display() {
    glClearColor(0.6, 0.8, .8, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    int x[8]{0, 70, 360, 560, 150, 250, 720, 450};
    int y[8]{0, 515, 550, 465, 330, 175, 230, 50};
    int vertexNum[8]{0, 3, 6, 7, 5, 1, 2, 4};
    int R = 30;     //Радиус окружности
    glLineWidth(2.0);
    drawLine(x[1], y[1], x[2], y[2]);
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[1] + x[2]) / 2, (y[1] + y[2]) / 2  + 15, 5);
    drawLine(x[2], y[2], x[3], y[3]);
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[2] + x[3]) / 2, (y[2] + y[3]) / 2  + 15, 19);
    drawLine(x[6], y[6], x[3], y[3]);
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[6] + x[3]) / 2, (y[6] + y[3]) / 2  + 15, 23);
    drawLine(x[6], y[6], x[7], y[7]);
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[6] + x[7]) / 2, (y[6] + y[7]) / 2  + 15, 17);
    drawLine(x[5], y[5], x[7], y[7]);
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[5] + x[7]) / 2, (y[5] + y[7]) / 2  + 15, 26);
    drawLine(x[5], y[5], x[4], y[4]);
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[5] + x[4]) / 2 + 5, (y[5] + y[4]) / 2  + 15, 9);
    drawLine(x[1], y[1], x[4], y[4]);
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[1] + x[4]) / 2 + 5, (y[1] + y[4]) / 2  + 15, 13);
    drawLine(x[2], y[2], x[7], y[7]);
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[2] + x[7]) / 2 + 8, (y[2] + y[7]) / 2, 42);
    drawLine(x[3], y[3], x[4], y[4]);
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[3] + x[4]) / 2, (y[3] + y[4]) / 2 + 15, 30);

    for (int i = 1; i <= 7; ++i) {
        drawFillCircle(x[i], y[i], R);                      //Круги
        DrawString(GLUT_BITMAP_TIMES_ROMAN_24, x[i], y[i], vertexNum[i]);   //Числа на вершинах
    }


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

void DrawString(void *p_font, int x, int y, int vertexNum) {
    //GLUT_BITMAP_TIMES_ROMAN_24
    //GLUT_BITMAP_HELVETICA_18
    std::string s = std::to_string(vertexNum);
    glRasterPos2i(x - 6, y - 6);
    for (int i = 0; i < s.size(); ++i) {
        glutBitmapCharacter(p_font, s[i]);
    }


}