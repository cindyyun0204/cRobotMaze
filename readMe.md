# Project Title: Robot Grid Navigation Simulator


## Description
This project is a simulation of a robot navigating through a grid, picking up markers, and returning them to a designated 'home' location. It showcases basic algorithms for movement, pathfinding, and obstacle avoidance in a grid environment. The robot is capable of moving forward, turning left and right, picking up markers, and avoiding blocks placed on the grid.


## Prerequisites
Before running this project, ensure you have the following installed:
- A C compiler (such as GCC)
- The graphics.h library (for graphical display)
- Standard C libraries: stdio.h, stdlib.h, string.h, and time.h


## Usage
To run the simulation:
1. Compile the code using a C compiler. For example, with GCC:

   gcc -o main main.c graphics.c functionManager.c

   Replace `main.c` with the name of your source file and adjust library flags as needed for your setup.
2. Run the compiled program, including the command line interface inputs:
    the input order: robotX, robotY, robotDirection, markerCount, blockCount

  ./main 2 3 "north" 3 3 | java -jar drawapp-2.0.jar


## Features
- Grid Initialisation: Sets up a 10x10 grid environment.
- Robot and Home Initialisation: Places the robot and home location on the grid.
- Marker and Block Placement: Randomly places markers and blocks on the grid.
- Robot Movement: Allows the robot to move forward, turn left, and turn right.
- Marker Pickup: The robot can pick up markers and carry them.
- Home Return: The robot can return to the home location to drop off markers.
- Obstacle Avoidance: The robot avoids blocks placed on the grid.


## Customisation
You can customise the initial position of the robot, its direction, and the number of markers and blocks by modifying the command line interface.
