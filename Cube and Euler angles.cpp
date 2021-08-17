#include<GL/glut.h>
#include <cmath>
#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4

float angle = 0.0f;

float red = 1.0f, blue = 1.0f, green = 1.0f;

float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;

float deltaAngle = 0.0f;
float deltaMove = 0.0f;

int xOrigin = -1;

void createMenus()
{
	int menu;

	menu = glutCreateMenu(processMenuEvents);

	glutAddMenuEntry("Red", RED);
	glutAddMenuEntry("Blue", BLUE);
	glutAddMenuEntry("Green", GREEN);
	glutAddMenuEntry("Orange", ORANGE);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void processMenuEvents(int option)
{
	switch (option)
	{
		case RED : 
			red = 1.0f;
			green = 0.0f;
			blue = 0.0f; 
			break;
		case GREEN:
			red = 0.0f;
			green = 1.0f;
			blue = 0.0f; 
			break;
		case BLUE:
			red = 0.0f;
			green = 0.0f;
			blue = 1.0f; 
			break;
		case ORANGE:
			red = 1.0f;
			green = 0.5f;
			blue = 0.5f; 
			break;
	}
}

void mouseButton(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			angle += deltaAngle;
			xOrigin = -1;
		}
		else
		{
			xOrigin = x;
		}
	}
}

void mouseMove(int x, int y)
{
	if (xOrigin >= 0) 
	{
		deltaAngle = (x - xOrigin) * 0.001f;

		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void pressKey(int key, int xx, int yy)
{
	switch (key)
	{
		case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
		case GLUT_KEY_RIGHT: deltaAngle = 0.01f; break;
		case GLUT_KEY_UP: deltaMove = 0.5f; break;
		case GLUT_KEY_DOWN: deltaMove = -0.5f; break;
	}
}

void releaseKey(int key, int x, int y)
{
	switch (key) 
	{
		case GLUT_KEY_LEFT:
		case GLUT_KEY_RIGHT: deltaAngle = 0.0f; break;
		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN: deltaMove = 0; break;
	}
}

void specialKeys(int key, int x, int y)
{
	float fraction = 0.1f;

	switch (key)
	{
		case GLUT_KEY_LEFT:
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT:
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP:
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN:
			x -= lx * fraction;
			z -= lz * fraction;
			break;
		case GLUT_KEY_F1:
			red = 1.0;
			green = 0.0;
			blue = 0.0;
			break;
		case GLUT_KEY_F2:
			red = 0.0;
			green = 1.0;
			blue = 0.0; 
			break;
		case GLUT_KEY_F3:
			red = 0.0;
			green = 0.0;
			blue = 1.0; 
			break;
	}
}

void normalKeys(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		exit(0);
	}
}

void reshape(int w, int h)
{
	if (h == 0)
	{
		h = 1;
	}
	float ratio = 1.0 * w / h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity(); 

	glViewport(0, 0, w, h);

	gluPerspective(45, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
}

void computePos(float deltaMove)
{
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle)
{
	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void renderScene(void) 
{
	if (deltaMove)
	{
		computePos(deltaMove);
	}

	if (deltaAngle)
	{
		computeDir(deltaAngle);
	}


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(x, 1.0f, z,
		x + lx, 1.0f, z + lz,
		0.0f, 1.0f, 0.0f);

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	/* Draw d'un triangle 2d qui tourne
	glBegin(GL_TRIANGLES);
		glVertex3f(-2.0f, -2.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0);
		glVertex3f(0.0f, 2.0f, 0.0)
	glEnd();*/

	
	// Draw d'un cube qui tourne
	glBegin(GL_QUADS);
	glColor3f(red,blue,green);
	// FRONT
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glColor3f(red, blue, green);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glColor3f(red, blue, green);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	// BACK
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor3f(red, blue, green);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glColor3f(red, blue, green);
	// LEFT
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glColor3f(red, blue, green);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor3f(red, blue, green);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	// RIGHT
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glColor3f(red, blue, green);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glColor3f(red, blue, green);
	glVertex3f(0.5f, -0.5f, 0.5f);

	glColor3f(red, blue, green);
	// TOP
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glColor3f(red, blue, green);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor3f(red, blue, green);
	// BOTTOM
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glColor3f(red, blue, green);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd();

	// angle += 0.5f;

	glutSwapBuffers();
}

int main(int argc, char** argv) {

	// Init GLUT & la Fenetre
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("OPENGL 3D");

	// Enregistrement de la fonction de render de l'écran
	glutDisplayFunc(renderScene);

	// Enregistrement de la fonction de reshape de la fenetre
	glutReshapeFunc(reshape);

	// IdleFunc
	glutIdleFunc(renderScene);

	// Enregistrement des fonctions de keyinput
	glutKeyboardFunc(normalKeys);
	glutSpecialFunc(specialKeys);
	glutSpecialFunc(pressKey);
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

	// Enregistrement des fonctions de mouseinput
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);


	glEnable(GL_DEPTH_TEST);

	// Initialization du processus de répétition GLUT
	glutMainLoop();

	return 1;
}
