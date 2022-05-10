#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glut/glut.h"
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glu32.lib")

#pragma region OLD
//
//HINSTANCE hInstance;
//HWND hWnd;
//HDC dev_ctx;
//HGLRC gl_ctx;
//
//INT window_width, window_height;
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT command, WPARAM wParam, LPARAM lParam)
//{
//	LRESULT res = 0;
//	switch (command) {
//
//	case WM_SIZE: {
//		window_width = LOWORD(lParam);
//		window_height = HIWORD(lParam);
//		if (!window_height)
//			window_height = 1;
//
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		glViewport(0, 0, window_width, window_height);
//		glOrtho((double)0, (double)window_width, (double)window_height, (double)0, -1.0, 1.0);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		break;
//	}
//
//	case WM_CLOSE:
//		PostQuitMessage(0);
//		break;
//
//	default:
//		res = DefWindowProc(hWnd, command, wParam, lParam);
//	}
//	return res;
//}
//
//int main()
//{
//	hInstance = GetModuleHandleA(0);
//
//	WNDCLASSA wc;
//	memset(&wc, NULL, sizeof(wc));
//	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wc.lpszClassName = "opengl";
//	wc.hInstance = hInstance;
//	wc.lpfnWndProc = WndProc;
//	if (!RegisterClassA(&wc)) {
//		printf("lasterror: %d\n", GetLastError());
//		return 1;
//	}
//
//	INT ww = 800;
//	INT wh = 600;
//	INT width = GetSystemMetrics(SM_CXSCREEN);
//	INT height = GetSystemMetrics(SM_CYSCREEN);
//	INT xpos = (width / 2) - (ww / 2);
//	INT ypos = (height / 2) - (wh / 2);
//	hWnd = CreateWindowExA(0, wc.lpszClassName, "OpenGL app", WS_OVERLAPPEDWINDOW, xpos, ypos, ww, wh, NULL, (HMENU)NULL, NULL, NULL);
//	if (!hWnd)
//		return 2;
//
//	dev_ctx = GetDC(hWnd);
//	if (!dev_ctx)
//		return 3;
//
//	int  iPixelFormat;
//	PIXELFORMATDESCRIPTOR pfd = {
//	sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd  
//	1,                     // version number  
//	PFD_DRAW_TO_WINDOW |   // support window  
//	PFD_SUPPORT_OPENGL |   // support OpenGL  
//	PFD_DOUBLEBUFFER,      // double buffered  
//	PFD_TYPE_RGBA,         // RGBA type  
//	24,                    // 24-bit color depth  
//	0, 0, 0, 0, 0, 0,      // color bits ignored  
//	0,                     // no alpha buffer  
//	0,                     // shift bit ignored  
//	0,                     // no accumulation buffer  
//	0, 0, 0, 0,            // accum bits ignored  
//	32,                    // 32-bit z-buffer      
//	0,                     // no stencil buffer  
//	0,                     // no auxiliary buffer  
//	PFD_MAIN_PLANE,        // main layer  
//	0,                     // reserved  
//	0, 0, 0                // layer masks ignored  
//	};
//	iPixelFormat = ChoosePixelFormat(dev_ctx, &pfd);
//	if (!iPixelFormat)
//		return 4;
//
//	if (!SetPixelFormat(dev_ctx, iPixelFormat, &pfd))
//		return 5;
//
//	gl_ctx = wglCreateContext(dev_ctx);
//	if (!gl_ctx)
//		return 6;
//
//	wglMakeCurrent(dev_ctx, gl_ctx);
//	ShowWindow(hWnd, SW_SHOW);
//
//	glClearColor(0.4, 0.4, 0.4, 1.0);
//
//	MSG msg;
//	while (GetMessage(&msg, NULL, NULL, NULL)) {
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//
//		glClear(GL_COLOR_BUFFER_BIT);
//		glLoadIdentity();
//
//		glRecti(100, 100, 200, 200);
//
//		glBegin(GL_LINES);
//		glVertex2i(0, 0);
//		glVertex2i(500, 500);
//
//		glVertex2i(100, 0);
//		glVertex2i(500, 500);
//		glEnd();
//
//		SwapBuffers(dev_ctx);
//	}
//	return 0;
//}
#pragma endregion

void Update(int key, int x, int y)										// Perform Motion Updates Here
{
	if (key == 27)									// Is ESC Being Pressed?
		exit(0);							// Terminate The Program

	glutPostRedisplay();
}

void DrawString(void* p_font, int x, int y, const char* p_format, ...) {
	char string[512];
	va_list argptr;
	va_start(argptr, p_format);
	vsprintf_s(string, sizeof(string), p_format, argptr);
	va_end(argptr);
	for (int i = 0; string[i]; i++) {
		glRasterPos2i(x, y);
		glutBitmapCharacter(p_font, string[i]);
		x += glutBitmapWidth(p_font, string[i]);
	}
}

//GLUT_BITMAP_TIMES_ROMAN_24

void DrawCircle(int xx, int yy, int radius) {
	glBegin(GL_POLYGON);                        // Middle circle
	for (int i = 0; i <= 300; i++) {
		double angle = 2 * 3.1415926535897932384 * i / 300;
		double x = cos(angle) * (double)radius;
		double y = sin(angle) * (double)radius;
		glVertex2i(xx + (int)x, yy + (int)y);
	}
	glEnd();
}

void DrawNode(int x, int y, int r, int n) {
	DrawCircle(x, y, r);
	glPushAttrib(GL_CURRENT_BIT);
	glColor3ub(0, 0, 0);

	y += 10;
	char buf[128];
	sprintf_s(buf, sizeof(buf), "%d", n);
	int w = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)buf);
	DrawString(GLUT_BITMAP_TIMES_ROMAN_24, x - (w / 2), y, buf);
	glPopAttrib();
}

void Draw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear Screen And Depth Buffer
	glLoadIdentity();													// Reset The Modelview Matrix

	DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 100, 100, "O privet!");



	DrawNode(300, 300, 30, 1000);

	glutSwapBuffers();
}

void ReshapeGL(int width, int height) {
	glViewport(0, 0, (GLsizei)(width), (GLsizei)(height));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLfloat)(width), (GLfloat)(height), 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();
}


// GLUT

void Key(unsigned char key, int x, int y) {
	Update(key, x, y);
	return;
};

void OnIdle() {
	glutPostRedisplay();
};

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(argv[0]);
	glutReshapeFunc(ReshapeGL);
	glutKeyboardFunc(Key);
	glutSpecialFunc(Update);
	glutDisplayFunc(Draw);
	glutIdleFunc(OnIdle);
	glutMainLoop();
	return 0;
}