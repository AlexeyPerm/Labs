//#include "GL/glut.h"
//#include "Node.h"
//
//constexpr int RADIUS = 10;
//constexpr int SCALE = 10;
//constexpr int WINDOW_WIDTH = 800;
//constexpr int WINDOW_HEIGHT = 600;
//
//
//void display();
//void draw_main(Node* root, int argc, char* argv[]);
//void Reshape(int, int);
//
//void draw_main(Node* root, int argc, char* argv[]) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//    glutInitWindowPosition(1000, 50);
//    glutCreateWindow("Binary trees");
//    glutReshapeFunc(Reshape);
//    glutDisplayFunc(display);
//    glutMainLoop();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_QUADS);
//    glColor3f(1.0, 1.0, 1.0);
//    glVertex2i(250, 450);
//    glColor3f(0.0, 0.0, 1.0);
//    glVertex2i(250, 150);
//    glColor3f(0.0, 1.0, 0.0);
//    glVertex2i(550, 150);
//    glColor3f(1.0, 0.0, 0.0);
//    glVertex2i(550, 450);
//    glEnd();
//    glutSwapBuffers();
//}
//
//void Reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, width, 0, height);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
