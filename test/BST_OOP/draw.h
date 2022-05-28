#pragma once

#include "Node.h"
#include <GL/glut.h>

constexpr int g_radius = 10;        //Радиус окружности
constexpr int g_scale = 30;         //Масштабирование
constexpr int g_windowWeight = 800; //Ширина окна
constexpr int g_windowHeight = 600; //Высота окна
Node* mainroot = nullptr;

void draw() {
    //Обработка дерева и вызов соответствующих функций рисования линий и кругов.
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glPointSize(2.0);

    Node* test = new Node(2.5);

    glutSwapBuffers();

}

//Инициализация OpenGL
void init() {
    glClearColor(0.191, 0.191, .191, 0.0);    //Фон окна
    glMatrixMode(GL_PROJECTION);                     //Параметры проекции
    gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

void draw_main(Node* tree, int argc, char* argv[]) {
    mainroot = tree;
    glutInit(&argc, argv);              //Инициализация GLUT.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   //Двойная буферизация и четырехкомпонентный цвет
    glutInitWindowSize(g_windowWeight, g_windowHeight);
    glutInitWindowPosition(50, 50);        //Позиция окна, считая с левого верхнего угла
    glutCreateWindow("Binary trees");
    init();
    //glutDisplayFunc(draw);
    glutDisplayFunc(draw);
    glutMainLoop();
}


//Пиксельная графика
void pixelPlot(GLint x, GLint y){
    y = g_windowHeight / 2 - y;  //перемещение источника в левый верхний угол
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    //https://docs.microsoft.com/en-us/windows/win32/opengl/glflush
    glFlush();  //The glFlush function forces execution of OpenGL functions in finite time.
}

