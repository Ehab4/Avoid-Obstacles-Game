

#include "firstGame.h"



using std::cout;
using std::setw;
using std::setfill;
using std::endl;

int width, height;
int startPositionX = 1, startPositionY = 1;
int endPositionX = 1, endPositionY = 1;
time_t initTime;
short direction = 0;
extern bool win;
extern bool lose;
int ** array = new int* [39];

int seconds = 0;

int startX = 0;
int startY = 0;

int* generateTwoRandomNumber() {
	
	int x = 1 + rand() % 37;
	int y = 1 + rand() % 37;
	if (array[x][y] == 0) {
		int arr[2];
		arr[0] = x;
		arr[1] = y;
		return arr;
	}
	else {
		return generateTwoRandomNumber();
	}
	

}

void generateStartAndEndPositions()
{
	srand(time(NULL));
	int* arr = generateTwoRandomNumber();
	startPositionX = arr[0];
	startPositionY = arr[1];
	startX = startPositionX;
	startY = startPositionY;
	int* arr1 = generateTwoRandomNumber();
	endPositionX = arr1[0];
	endPositionY = arr1[1];
}


void initSizeWindow(int x, int y) {

	width = x;
	height = y;

}





void drawWall() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			unitWall(x, y);
		}
	}
}




void unitWall(int x, int y) {

	if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
		glLineWidth(3.0);
		glColor3f(1.0f, 0.0f, 0.0f);

		glBegin(GL_LINE_LOOP);
		glVertex2f(x, y);
		glVertex2f(x + 1, y);
		glVertex2f(x + 1, y + 1);
		glVertex2f(x, y + 1);
		glEnd();
	}
}

void drawStartPathPosition() {
	
	if (direction == UP) {
		if(startPositionY<=37)
			startPositionY++;

	}
	else if (direction == DOWN) {
		if (startPositionY >= 2)
			startPositionY--;
	}
	else if (direction == LEFT) {
		if (startPositionX >=2)
			startPositionX--;
	}
	else if (direction == RIGHT) {
		if (startPositionX <= 37)
			startPositionX++;
	}
	if (array[startPositionX][startPositionY] == 1) {
		lose = true;
	}
	
	direction = 0;

	glColor3f(1.0f, 0.2f, 0.0f);
	glRectd(startPositionX, startPositionY,(double)startPositionX+1,(double)startPositionY+1);
	if (startPositionX == endPositionX && startPositionY == endPositionY) {
		win = true;
	}

}

void drawBlocks() {

	for (int x = 1; x < 39; x++) {
		for (int y = 1; y < 39; y++) {

			if (array[x][y]) {
				glColor3f(0.0f, 1.0f, 0.4f);
				glRectd(x, y, (double)x + 1, (double)y + 1);

			}

		}
	}
}

void generateObstaclesPosition() {
	for (int i = 0; i < 39; ++i)
		array[i] = new int[39];
	srand(time(NULL));
	int count = 1;
	for (int x = 1; x < 39; x++) {
		for (int y = 1; y < 39; y++) {
			int r = rand() % 2;
			count += r;

			if (r == 1 && count % 3 != 0) {
				r = 0;
			}
			array[x][y] = r;

		}
	}
}


void drawEndPathPosition() {
	glColor3f(0.0f, 0.0f, 1.0f);
	glRectf((float)endPositionX, (float)endPositionY, (float)endPositionX + 1, (float)endPositionY + 1);
}

void displayClock()
{
	// system call to clear the screen 
	system("cls");
	cout << setfill(' ') << setw(55) << "         TIMER         \n";
	cout << setfill(' ') << setw(55) << " --------------------------\n";
	cout << setfill(' ') << setw(40) << "| " << seconds << " sec |" << endl;
}
void timer()
{
	displayClock();
	time_t currentTime = time(NULL);
	
	seconds = currentTime - initTime;

	if (seconds == 11) {
		lose = true;
	}
}


