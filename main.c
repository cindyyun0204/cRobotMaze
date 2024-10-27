#include "graphics.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "functionManager.h"
#include "string.h"

void initialGrid(){
    //initialises the grid
    int i = 0, j = 0;
    for (i = 0 ; i < 10 ; i++){
        for (j = 0 ; j < 10 ; j++){
            array2D.grid[i][j] = 0;
        }
    }
}

void initialRobotCoordinates(int argc, char **argv){
    //sets positions for the robot and home
    //input order: robotX, robotY, robotDirection, markerCount, blockCount
    setRobotCoordinates(2,3), setRobotDirection('N'); //default robot direction & position when no input
    setHomeCoordinates(2,3); //default home position when no input
    setMarkerCount(3), setBlockCount(3); //default marker and block count when no input
    if (argc == 6){
        setRobotCoordinates(atoi(argv[1]),atoi(argv[2]));
        setHomeCoordinates(atoi(argv[1]),atoi(argv[2]));
        char *tempDir = argv[3];
        if (strcmp(tempDir, "north") == 0){
            setRobotDirection('N');
        }
        else if (strcmp(tempDir, "south") == 0){
            setRobotDirection('S');
        }
        else if (strcmp(tempDir, "east") == 0){
            setRobotDirection('E');
        }
        else if (strcmp(tempDir, "west") == 0){
            setRobotDirection('W');
        }
        setMarkerCount(atoi(argv[4]));
        setBlockCount(atoi(argv[5]));
    }
    setArrayContent(getRobotX(),getRobotY(),2);
}

void initialMarkerCoordinates(int markerNumber){
    //sets the initial marker coordinates
    srand(time(NULL));
    int markerCount = 0;
    while (markerCount < markerNumber){
        int x = rand() % 10;
        int y = rand() % 10;
        if (getArrayContent(x,y) == 0){
            setArrayContent(x,y,3);
            setColour(gray);
            fillRect(120+(60*x),60+(60*y),60,60);
            markerCount += 1;
        }
    }
}

void initialBlockCoordinates(int blockNumber){
    //sets the initial block coordinates
    int blockCount = 0;
    while (blockCount < blockNumber){
        int x = rand() % 10;
        int y = rand() % 10;
        if (getArrayContent(x,y) == 0){
            setArrayContent(x,y,4);
            setColour(black);
            fillRect(120+(60*x),60+(60*y),60,60);
            blockCount += 1;
        }
    }
}

void drawGrid(){
    //draws the grid
    setWindowSize(1000,1000);
    background();
    int i, j;
    for (i = 0 ; i < 10 ; i++) {
        int a = 120 + (i * 60);
        for (j = 0 ; j < 10 ; j++) {
            int b = 60 + (j * 60);
            drawRect(a,b,60,60);
        }
    }
    foreground();
}

void colourGrid(){
    int i, j;
    for (i = 0; i < 10 ; i ++){
        for (j = 0 ; j < 10 ; j++){
            if (getArrayContent(i,j) == 2){
                setColour(blue);
                fillRect(120+(60*i),60+(60*j),60,60);
            }
            else if (getArrayContent(i,j) == 3){
                setColour(gray);
                fillRect(120+(60*i),60+(60*j),60,60);
            }
            else if (getArrayContent(i,j) == 4){
                setColour(black);
                fillRect(120+(60*i),60+(60*j),60,60);
            }
        }
    }
}

void drawRobot(){
    //draws the robot
    setColour(green);
    fillPolygon(3,getDrawRobotArrayX(),getDrawRobotArrayY());
}

void drawHome(){
    //draws the home
    setColour(blue);
    fillRect(120+(60*getHomeX()),60+(60*getHomeY()),60,60);
}

void initialiseGrid(int argc, char **argv){
    initialGrid();
    initialRobotCoordinates(argc, argv);
    setRobotDrawCoord(getRobotX(),getRobotY(),getRobotDirection());
    drawGrid();
    drawHome();
    drawRobot();
    initialMarkerCoordinates(getMarkerCount());
    initialBlockCoordinates(getBlockCount());
    initialiseMarkerPickedUp();
}

void forward(){
    drawGrid();
    colourGrid();
    if (getRobotDirection() == 'N'){
        setRobotCoordinates(getRobotX(),getRobotY()-1);
    }
    else if (getRobotDirection() == 'S'){
        setRobotCoordinates(getRobotX(),getRobotY()+1);
    }
    else if (getRobotDirection() == 'E'){
        setRobotCoordinates(getRobotX()+1,getRobotY());
    }
    else if (getRobotDirection() == 'W'){
        setRobotCoordinates(getRobotX()-1,getRobotY());
    }
    setColour(green);
    setRobotDrawCoord(getRobotX(),getRobotY(),getRobotDirection());
    fillPolygon(3,getDrawRobotArrayX(),getDrawRobotArrayY());
    setArrayContent(getRobotX(), getRobotY(), 0);
    push(getRobotX(), getRobotY(), getRobotDirection());
}

void left(){
    drawGrid();
    colourGrid();
    if (getRobotDirection() == 'N'){
        setRobotDirection('W');
    }
    else if (getRobotDirection() == 'S'){
        setRobotDirection('E');
    }
    else if (getRobotDirection() == 'E'){
        setRobotDirection('N');
    }
    else if (getRobotDirection() == 'W'){
        setRobotDirection('S');
    }
    setColour(green);
    setRobotDrawCoord(getRobotX(),getRobotY(),getRobotDirection());
    fillPolygon(3,getDrawRobotArrayX(),getDrawRobotArrayY());
}

void right(){
    drawGrid();
    colourGrid();
    if (getRobotDirection() == 'N'){
        setRobotDirection('E');
    }
    else if (getRobotDirection() == 'S'){
        setRobotDirection('W');
    }
    else if (getRobotDirection() == 'E'){
        setRobotDirection('S');
    }
    else if (getRobotDirection() == 'W'){
        setRobotDirection('N');
    }
    setColour(green);
    setRobotDrawCoord(getRobotX(),getRobotY(),getRobotDirection());
    fillPolygon(3,getDrawRobotArrayX(),getDrawRobotArrayY());
}

int atMarker(){
    if (getArrayContent(getRobotX(), getRobotY()) == 3){
        return 1;
    }
    else{return 0;}

}

int canMoveForward(){
    if (getRobotDirection() == 'N'){
        if (getRobotY() == 0 || getArrayContent(getRobotX(), getRobotY()-1) == 4){
            return 0;
        }
        else{return 1;}
    }
    else if (getRobotDirection() == 'S'){
        if (getRobotY() == 9 || getArrayContent(getRobotX(), getRobotY()+1) == 4){
            return 0;
        }
        else{return 1;}
    }
    else if (getRobotDirection() == 'E'){
        if (getRobotX() == 9 || getArrayContent(getRobotX()+1, getRobotY()) == 4){
            return 0;
        }
        else{return 1;}
    }
    else {
        if (getRobotX() == 0 || getArrayContent(getRobotX()-1, getRobotY()) == 4){
            return 0;
        }
        else{return 1;}
    }
}

int atHome(){
    if (getArrayContent(getRobotX(), getRobotY()) == 2){
        return 1;
    }
    else{return 0;}
}

void pickUpMarker(){
    if (atMarker() == 1){
        setArrayContent(getRobotX(), getRobotY(), 0);
        drawGrid();
        colourGrid();
        setMarkerPickedUp(getMarkerPickedUp()+1);
    }
}

void dropMarker(){
    if (atHome() == 1){
        drawGrid();
        colourGrid();
        setColour(blue);
        fillRect(120+(60*getRobotX()),60+(60*getRobotY()),60,60);
        setColour(green);
        setRobotDrawCoord(getRobotX(),getRobotY(),getRobotDirection());
        fillPolygon(3,getDrawRobotArrayX(),getDrawRobotArrayY());
        setMarkerPickedUp(getMarkerPickedUp()-1);
        setMarkerCount(getMarkerCount()-1);
    }
}

int isCarryingAMarker(){
    if (getMarkerPickedUp() > 0){
        return 1;
    }
    else{return 0;}
}

void goBackHome(){
    while (getTailPtr() > -1 && atHome() == 1){
        setColour(green);
        char tempDirection;
        switch(popDirection()) {
            case 'N' :
                tempDirection = 'S';
                break;
            case 'S' :
                tempDirection = 'N';
                break;
            case 'E' :
                tempDirection = 'W';
                break;
            case 'W' :
                tempDirection = 'E';
                break;
        }
        setRobotDrawCoord(popX(),popY(),tempDirection);
        decrementTailPtr();
        fillPolygon(3,getDrawRobotArrayX(),getDrawRobotArrayY());
    }
    dropMarker();
    
}



int main(int argc, char **argv){
    initialiseGrid(argc, argv);
    while (getMarkerCount > 0){
        while (atMarker() == 0){
            if (canMoveForward() == 1){
                int temp = rand() % 4;
                if (temp == 0){
                    right();
                    drawGrid();
                    colourGrid();
                    drawRobot();
                    sleep(250);
                }
                else if (temp == 1){
                    left();
                    drawGrid();
                    colourGrid();
                    drawRobot();
                    sleep(250);
                }
                else{
                    forward();
                    sleep(250);
                }
            }
            int temp2 = rand() % 2;
            if (temp2 == 0){
                left();
                drawGrid();
                colourGrid();
                drawRobot();
                sleep(250);
            }
            else if (temp2 == 1){
                right();
                drawGrid();
                colourGrid();
                drawRobot();
                sleep(250);
            }
            
        }
        pickUpMarker();
        
        if (isCarryingAMarker() == 1){
            goBackHome();
        }
    }
}