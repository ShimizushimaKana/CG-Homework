#define NDEBUG

#include <stdlib.h>  
#include <GL/glut.h>  
#include<iostream>
#include <GLFW/glfw3.h>
#include "../../../stuff/Includes/GL/freeglut_std.h"

#pragma comment(lib, "freeglut.lib")  
using namespace std;
GLfloat roate = 0.1;//������ת����
GLfloat rote = 0.0;//��ת�Ƕ�
GLfloat anglex = 0.0;//X ����ת
GLfloat angley = 0.0;//Y ����ת
GLfloat anglez = 0.0;//Z ����ת
GLint WinW = 400;
GLint WinH = 400;
GLfloat oldx;//���������ʱ��¼�������  
GLfloat oldy;
GLfloat xOffset = 0.0f, yOffset = 0.0f;


void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0); //������ɫ  
}
void getColor(float deltatime)
{

}
void display(void)
{

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0 - rote / 360, rote/360, rote/360); //���ʺ�ɫ
		//����
		glClearColor( 1.0 - rote / 360, 1.0 - rote / 360, rote / 360, 1.0);
	    glLoadIdentity();  //���ص�λ����  
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
			oldx = x;//���������ʱ��¼�������  
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
	anglex += 360 * (GLfloat)deltax / (GLfloat)WinW;//������Ļ����껬���ľ�����������ת�ĽǶ�  
	angley += 360 * (GLfloat)deltay / (GLfloat)WinH;
	anglez += 360 * (GLfloat)deltay / (GLfloat)WinH;
	oldx = x;//��¼��ʱ��������꣬�����������  
	oldy = y;//����û����������䣬��������ת���ò��ɿ�  
	glutPostRedisplay();
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//˫������ɫģʽ
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Teapot");
	init();
	glutDisplayFunc(display);//��ʾ
	glutReshapeFunc(reshape);//�ػ�
	glutMouseFunc(mouse);
	glutSpecialFunc(specialKey);
	glutMotionFunc(motion);
	glutIdleFunc(display);
	glutMainLoop();//������ѭ���������¼�
	return 0;
}
