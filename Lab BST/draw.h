#pragma once
#include "Tree.h"
#include <cmath>

void display();
static void reshape(int w, int h);
static void drawFillCircle(int x, int y, int R);
static void drawLine(int x1, int y1, int x2, int y2);
int getPos(int index, int width, int curLevel, int maxLevel);

template<class T>
static void drawText(T text, void* font, int text_x, int text_y, int R, int k);

struct pos {
    int col;    // Столбец (х)
    int str;    // Строка  (у)
};

struct SGlutContextStruct {
    /* window_width – ширина окна;
     * window_height – высота окна;
     * shift – отступ от краев (решено сделать его одинаковым с двух сторон);
     * k - коэффициент ширины данных;
     * R – радиус круга;
     * x, y - координаты чего-либо;
     * state - переменная состояния при работе с мышью
    */
    Tree* tree;     //копия дерева
    int window_width, window_height, shift, k, R, x, y, state;
};

