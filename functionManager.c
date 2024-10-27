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

void setRobotCoordinates(int x, int y) {
    robot.x = x;
    robot.y = y;
}

void setRobotDirection(char direction){
    robot.direction = direction;
}

void setHomeCoordinates(int x, int y) {
    home.x = x;
    home.y = y;
}

void setArrayContent(int x, int y, int type){
    //types: empty = 0, robot = 1, home = 2, marker = 3, block = 4
    array2D.grid[y][x] = type;
}

void setMarkerCount(int count){
    markerCount.count = count;
}

void setBlockCount(int count){
    blockCount.count = count;
}

void setRobotDrawCoord(int x, int y, char direction){
    if (direction == 'N'){
        robotCoord.x[0] = 120 + (x * 60), robotCoord.x[1] = 150 + (x * 60), robotCoord.x[2] = 180 + (x * 60);
        robotCoord.y[0] = 120 + (y * 60), robotCoord.y[1] = 60 + (y * 60), robotCoord.y[2] = 120 + (y * 60);
    }
    else if (direction == 'S'){
        robotCoord.x[0] = 180 + (x * 60), robotCoord.x[1] = 150 + (x * 60), robotCoord.x[2] = 120 + (x * 60);
        robotCoord.y[0] = 60 + (y * 60), robotCoord.y[1] = 120 + (y * 60), robotCoord.y[2] = 60 + (y * 60);
    }
    else if (direction == 'E'){
        robotCoord.x[0] = 120 + (x * 60), robotCoord.x[1] = 180 + (x * 60), robotCoord.x[2] = 120 + (x * 60);
        robotCoord.y[0] = 60 + (y * 60), robotCoord.y[1] = 90 + (y * 60), robotCoord.y[2] = 120 + (y * 60);
    }
    else if (direction == 'W'){
        robotCoord.x[0] = 180 + (x * 60), robotCoord.x[1] = 120 + (x * 60), robotCoord.x[2] = 180 + (x * 60);
        robotCoord.y[0] = 120 + (y * 60), robotCoord.y[1] = 90 + (y * 60), robotCoord.y[2] = 60 + (y * 60);
    }
}

void setMarkerPickedUp(int count){
    markerPickedUp.count = count;
}

void initialiseMarkerPickedUp(){
    markerPickedUp.count = 0;
}

void initialiseStack(){
    for (int i = 0 ; i < 1000 ; i++){
        coordinatesGrid.grid[i][0] = -1;
        coordinatesGrid.grid[i][1] = -1;
        directionGrid.grid[i] = 'p';
        coordinatesGrid.tailPtr = -1;
        directionGrid.tailPtr = -1;
    }
}

void push(int x, int y, char direction){
    coordinatesGrid.tailPtr += 1;
    directionGrid.tailPtr += 1; 
    coordinatesGrid.grid[coordinatesGrid.tailPtr][0] = x;
    coordinatesGrid.grid[coordinatesGrid.tailPtr][1] = y;
    directionGrid.grid[directionGrid.tailPtr] = direction;
}

void decrementTailPtr(){
    coordinatesGrid.tailPtr -= 1;
    directionGrid.tailPtr -= 1;
}


int getRobotX(){
    return robot.x;
}

int getRobotY(){
    return robot.y;
}

int getMarkerCount(){
    return markerCount.count;
}

int getBlockCount(){
    return blockCount.count;
}

int getArrayContent(int x, int y){
    return array2D.grid[y][x];
}

int getMarkerPickedUp(){
    return markerPickedUp.count;
}

int popX(){
    return coordinatesGrid.grid[coordinatesGrid.tailPtr][0];;
}

int popY(){
    return coordinatesGrid.grid[coordinatesGrid.tailPtr][1];;
}

int getTailPtr(){
    return coordinatesGrid.tailPtr;
}

int getHomeX(){
    return home.x;
}

int getHomeY(){
    return home.y;
}


int* getDrawRobotArrayX(){
    return robotCoord.x;
}

int* getDrawRobotArrayY(){
    return robotCoord.y;
}


char getRobotDirection(){
    return robot.direction;
}

char popDirection(){
    return directionGrid.grid[directionGrid.tailPtr];
}