#include "draw.h"
#include <string>
#include "GL/glut.h"

SGlutContextStruct glutContext;

int getPos(int index, int width, int curLevel, int maxLevel) {
    int x1 = 0;
    int x2 = static_cast<int> (std::pow(2, curLevel) - 1);
    int y1 = static_cast<int> (width / std::pow(2, curLevel + 1));
    int y2 = static_cast<int> (width - std::pow(2, maxLevel - curLevel));
    if (x1 == x2) {
        return y1;
    }
    double k = (static_cast<double> (y2 - y1) / (x2 - x1));
    double m = -x1 * k + y1;
    int y    = static_cast<int> (k * index + m);
    return y;
}


void Tree::initWindow(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(glutContext.window_width, glutContext.window_height);
    glutCreateWindow("My Tree");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // glutPassiveMotionFunc(mouseMove);
    glutMainLoop();
}

void Tree::drawTree(int argc, char** argv, int window_width, int window_height, int shift, int k) {
    Tree* temp = this->copyTree();
    temp = temp->replaceNullForEmpty();
    glutContext.tree          = temp;
    glutContext.window_width  = window_width;
    glutContext.window_height = window_height;
    glutContext.shift         = shift;
    glutContext.k             = k;
    initWindow(argc, argv);
}


static void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLsizei) w, 0, (GLsizei) h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutContext.window_width  = w;
    glutContext.window_height = h;
    glutPostRedisplay();
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
            x1 = static_cast<float> (i * sin(t) + x);
            y1 = static_cast<float> (i * cos(t) + y);
            glVertex2f(x1, y1);
        }
    }
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (int i = R - 1; i <= R; i++) {
        for (int t = 0; t <= 1440; t++) {
            x1 = static_cast<float> (R * sin(t) + x);
            y1 = static_cast<float> (R * cos(t) + y);
            glVertex2f(x1, y1);
        }
    }
    glEnd();
}

template<class T>
static void drawText(T text, void* font, int text_x, int text_y, int R, int k) {
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(text_x, text_y, 0.0);
    std::string s = std::to_string(text).substr(0, 3);  //Обрезаем число до трёх символов
    char* s1 = new char[s.size() + 1];
    for (int i = 0; i < s.size(); i++) {
        s1[i] = s[i];
    }
    s1[s.size()] = 0;
    char* c;
    int max_char_width = 0;
    int char_width = 0;
    for (c = s1; *c != '\0'; c++) {
        char_width = glutStrokeWidth(font, *c);
        if (max_char_width < char_width) {
            max_char_width = char_width;
        }
    }
    float expand_x = static_cast<float> (1.5 * R / (k * max_char_width));
    float expand_y = static_cast<float> (1.5 * R / (k * 100));
    glScalef(expand_x, expand_y, 1.0);
    for (c = s1; *c != '\0'; c++) {
        glutStrokeCharacter(font, *c);
    }
    glPopMatrix();
}

void display() {
    Tree* tree = (Tree*) glutContext.tree;
    //tree = tree->replaceNullForEmpty();
    int k            = glutContext.k;
    int windowWidth  = glutContext.window_width;
    int windowHeight = glutContext.window_height;
    int shift        = glutContext.shift;
    int height       = tree->getHeight();
    int maxLeafs     = std::pow(2, height - 1); // Максимальное число листов на нижнем уровне (нумерация с нуля)
    int index        = 0;          // Минимальная ширина дерева для печати (не конечная, но необходимая)
    int curLevel     = 0;       // Номер строки (на выводе)
    int width        = 2 * maxLeafs - 1;
//номер элемента в строке (нумерация с нуля)/позиция корня (число пробелов перед ним)
    int factSpaces   = getPos(index, width, curLevel, height - 1);
    pos node{};
    std::vector<Tree*> vNodes;
    std::vector<pos> vPos;
    int R = 3 * (windowHeight / tree->getHeight()) / 4; // Радиус круга

    if (2 * R * height > (windowHeight - 2 * shift)) {
        R = (windowHeight - 2 * shift) / (2 * height);
    }
    glutContext.R = R;
// Установили координаты корня при рисовании
    tree->setCoordsForNode(windowWidth, windowHeight, shift, width, height, factSpaces, curLevel, R);
    vNodes.push_back(tree);
    node.col = factSpaces;
    node.str = curLevel;
    vPos.push_back(node);

    glClearColor(0.941, 0.973, 1.000, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2);
    glEnable(GL_POINT_SMOOTH);
    for (int i = 0; i < tree->getAmountOfNodes(); i++) {
        if (pow(2, curLevel) <= index + 1) {
            index = 0;
            curLevel++;
        }
        if (vNodes[i]->getLeft() != NULL) {
            vNodes.push_back(vNodes.at(i)->getLeft());
            factSpaces  = getPos(index, width, curLevel, height - 1);
            node.col    = factSpaces;
            node.str    = curLevel;
            vPos.push_back(node);
            index++;
            vNodes[i]->getLeft()->setCoordsForNode(windowWidth, windowHeight, shift,
                                                   width, height, factSpaces, curLevel, R);
            if (vNodes[i]->getLeft()->getData() != NULL) {
                int x1 = vNodes[i]->node_x;
                int y1 = vNodes[i]->node_y;
                int x2 = vNodes[i]->getLeft()->node_x;
                int y2 = vNodes[i]->getLeft()->node_y;
                drawLine(x1, y1, x2, y2);
            }
        }

        if (vNodes[i]->getRight() != NULL) {
            vNodes.push_back(vNodes.at(i)->getRight());
            factSpaces  = getPos(index, width, curLevel, height - 1);
            node.col    = factSpaces;
            node.str    = curLevel;
            vPos.push_back(node);
            index++;
            vNodes[i]->getRight()->setCoordsForNode(windowWidth, windowHeight, shift, width, height,
                                                    factSpaces, curLevel, R);
            if (vNodes[i]->getRight()->getData() != NULL) {
                int x1 = vNodes[i]->node_x;
                int y1 = vNodes[i]->node_y;
                int x2 = vNodes[i]->getRight()->node_x;
                int y2 = vNodes[i]->getRight()->node_y;
                drawLine(x1, y1, x2, y2);
            }
        }

        if (vNodes[i]->getData() != NULL) {
            if (glutContext.state == 0) {
                drawFillCircle(vNodes[i]->node_x, vNodes[i]->node_y, R);
            } else {
                glClear(GL_COLOR_BUFFER_BIT);
                drawFillCircle(vNodes[i]->node_x, vNodes[i]->node_y, R);
            }
            vNodes[i]->setCoordsForText(k, R);
            drawText(vNodes[i]->getData(), GLUT_STROKE_ROMAN, vNodes[i]->text_x, vNodes[i]->text_y, R, k);
        }
    }
    glutSwapBuffers();
    glDisable(GL_POINT_SMOOTH);
}

