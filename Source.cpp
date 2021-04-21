/*
 *First project with OpenGL
 *Ehab
 */

#include "firstGame.h"


#define COLUMNS 40
#define ROWS 40

extern short direction;
bool win = false;
bool lose = false;
extern time_t initTime;

void display();
void reshape(int, int);
void Redisplay(int);
void keyboard(int, int, int);
extern int** array;



void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initSizeWindow(COLUMNS, ROWS);
}

int main(int argc, char** argv) {

	generateObstaclesPosition();
	generateStartAndEndPositions();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Using OpenGL to Create Game");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, Redisplay, 0);
	glutSpecialFunc(keyboard);
	init();
	initTime = time(NULL);

	glutMainLoop();
	return 0;
}



void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawWall();
	drawStartPathPosition();
	drawBlocks();
	drawEndPathPosition();
	glutSwapBuffers();
	timer();
	if (win == true) {
		MessageBox(NULL, "Congratulations \n you win", "result", MB_ICONEXCLAMATION | MB_OK);
		for (int i = 0; i < 39; ++i)
			delete[] array[i];
		delete[] array;
		exit(0);
	}
	else if (lose == true) {
		MessageBox(NULL, "GAME OVER \n you lost", "result", MB_ICONEXCLAMATION | MB_OK);
		for (int i = 0; i < 39; ++i)
			delete[] array[i];
		delete[] array;
		exit(0);
	}


}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

}

void Redisplay(int) {
	glutPostRedisplay();
	glutTimerFunc(1, Redisplay, 0);
}

void keyboard(int key, int, int) {

	switch (key)
	{
	case GLUT_KEY_DOWN:
		direction = DOWN;
		break;

	case GLUT_KEY_UP:
		direction = UP;
		break;

	case GLUT_KEY_LEFT:
		direction = LEFT;
		break;

	case GLUT_KEY_RIGHT:
		direction = RIGHT;
		break;
	default:
		break;
	}
}
