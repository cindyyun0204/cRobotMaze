#ifndef VARIABLES_H
#define VARIABLES_H

typedef struct{
    int x;
    int y;
    char direction;
}Coordinates;


typedef struct{
    int grid[10][10];
} GridTrack;


typedef struct{
    int count;
}Count;

typedef struct{
    int x[3], y[3];
} DrawRobotCoord;

typedef struct{
    char grid[1000];
    int tailPtr;
} DirectionGrid;

typedef struct{
    int grid[1000][2];
    int tailPtr;
} CoordinatesGrid;


#endif