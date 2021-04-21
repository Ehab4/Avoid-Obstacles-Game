#pragma once
#include <iomanip> 
#include <iostream> 
#include <stdlib.h> 
#include <windows.h> 
#include <cstdlib>
#include <ctime>
#include <string>
#include <GL/glut.h>

#define UP 1
#define DOWN -1
#define LEFT 2
#define RIGHT -2



void initSizeWindow(int, int);
void drawWall();
void unitWall(int, int);
void drawStartPathPosition();
void keyboard(int key, int, int);
void drawBlocks();
int* generateTwoRandomNumber();
void generateObstaclesPosition();

void generateStartAndEndPositions();
void drawEndPathPosition();

void displayClock();
void timer();
