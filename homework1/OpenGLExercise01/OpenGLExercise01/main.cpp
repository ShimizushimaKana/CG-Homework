#define NDEBUG

#include <stdlib.h>  
#include <GL/glut.h>  
#include<iostream>
#include <GLFW/glfw3.h>
#include "../../../stuff/Includes/GL/freeglut_std.h"

#pragma comment(lib, "freeglut.lib")  
using namespace std;
GLfloat roate = 0.1;//设置旋转速率
GLfloat rote = 0.0;//旋转角度
GLfloat anglex = 0.0;//X 轴旋转
GLfloat angley = 0.0;//Y 轴旋转
GLfloat anglez = 0.0;//Z 轴旋转
GLint WinW = 400;
GLint WinH = 400;
GLfloat oldx;//当左键按下时记录鼠标坐标  
GLfloat oldy;
GLfloat xOffset = 0.0f, yOffset = 0.0f;


void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0); //背景白色  
}
void getColor(float deltatime)
{

}
void display(void)
{

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0 - rote / 360, rote/360, rote/360); //画笔红色
		//背景
		glClearColor( 1.0 - rote / 360, 1.0 - rote / 360, rote / 360, 1.0);
	    glLoadIdentity();  //加载单位矩阵  
		gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glRotatef(rote, 0.0f, 1.0f, 0.0f);
		glRotatef(anglex, 1.0, 0.0, 0.0);
		glRotatef(angley, 0.0, 1.0, 0.0);
		glRotatef(anglez, 0.0, 0.0, 1.0);
		glutWireTeapot(2);
		rote += roate;
		if (rote >= 360) rote = 0;
		cout << rote << endl;
		//glRotatef(angle, 0.0, 1.0, 0.0);
		//angle += 1.0f;
		glutSwapBuffers();
	
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			roate = 0.0;
			rote = 0;
			oldx = x;//当左键按下时记录鼠标坐标  
			oldy = y;
			cout << "left" << endl;
		}

	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			roate += 0.1f;
			cout << "right" << endl;
		}

	}

}
void specialKey(int key, int x, int y)
{
	switch ( key )
	{
	case GLUT_KEY_UP:
		rote = 0; 
		cout << "up" << endl; break;
	case GLUT_KEY_DOWN:
		rote = 90;
		cout << "down" << endl; break;
	case GLUT_KEY_LEFT:
		rote = 180;
		cout << "left" << endl; break;
	case GLUT_KEY_RIGHT:
		rote = 270;
		cout << "right" << endl; break;
	default:
		break;
	}
	
}

void motion(int x, int y)
{
	GLint deltax = oldx - x;
	GLint deltay = oldy - y;
	anglex += 360 * (GLfloat)deltax / (GLfloat)WinW;//根据屏幕上鼠标滑动的距离来设置旋转的角度  
	angley += 360 * (GLfloat)deltay / (GLfloat)WinH;
	anglez += 360 * (GLfloat)deltay / (GLfloat)WinH;
	oldx = x;//记录此时的鼠标坐标，更新鼠标坐标  
	oldy = y;//若是没有这两句语句，滑动是旋转会变得不可控  
	glutPostRedisplay();
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//双缓冲颜色模式
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Teapot");
	init();
	glutDisplayFunc(display);//显示
	glutReshapeFunc(reshape);//重绘
	glutMouseFunc(mouse);
	glutSpecialFunc(specialKey);
	glutMotionFunc(motion);
	glutIdleFunc(display);
	glutMainLoop();//进入主循环并处理事件
	return 0;
}
