#ifndef FUNCTIONMANAGER_H
#define FUNCTIONMANAGER_H

#include "variables.h"

static Coordinates robot;
static Coordinates home;
static GridTrack array2D;
static Count markerCount;
static Count blockCount;
static DrawRobotCoord robotCoord;
static Count markerPickedUp;
static DirectionGrid directionGrid;
static CoordinatesGrid coordinatesGrid;

void setRobotCoordinates(int x, int y);
void setRobotDirection(char direction);
void setHomeCoordinates(int x, int y);
void setArrayContent(int x, int y, int type);
void setMarkerCount(int count);
void setBlockCount(int count);
void setMarkerPickedUp(int count);
void initialiseMarkerPickedUp();
void setRobotDrawCoord(int x, int y, char direction);
void initialiseStack();
void push(int x, int y, char direction);
void decrementTailPtr();


int getRobotX();
int getRobotY();
int getMarkerCount();
int getBlockCount();
int getArrayContent(int x, int y);
int getMarkerPickedUp();
int popX();
int popY();
int getTailPtr();
int getHomeX();
int getHomeY();

int* getDrawRobotArrayX();
int* getDrawRobotArrayY();

char getRobotDirection();
char popDirection();

#endif