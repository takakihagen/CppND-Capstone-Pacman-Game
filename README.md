# CPPND: Capstone Snake Game Example

This is a repo of the final project for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PacmanGame`.

## Project Structure

The rendered objects are derived from GameObject Class that has render() function, which is a virtual function.
One of those object is the map. It holds the information about the position of the wall and coins. Everytime pacman hit the coin, the map will change the grid to "passed area" and no coin will be visible.
The objects which move are derived from MovableObject which also derives from GameObject.
MovableObject has also a virtual function called Update() which updates the position and the status of the moving objects.
This MovableObject is a base class of Enemy and Pacman.

The goal of this game is to get all the coin which is represented as a yellow rectangle. If the Pacman is hit by an enemy, the game is over.
An enemy doesn't move in the opposite direction and if it is possible to move in several directions, it will randomly choose one of a possible direction.

After you lose or gather all the coins, you can press the space key, which starts a new game.

## Rubric
This project applies proper memory management, object oriented programming, and loops.

### 1. The project accepts user input and processes the input.
We can control the Pacman with the arrow keys.

### 2. The project demonstrates an understanding of C++ functions and control structures.
The Control class controls not only the Pacman but also enemies.

### 3. The project uses Object Oriented Programming techniques.
We use several classes and each class has only one function such as control, render, update

### 4. Classes follow an appropriate inheritance hierarchy.
GameObject has only one virtual function and no other function. Moreover, the hierarchies are organized properly.

### 5. Overloaded functions allow the same function to operate on different parameters.
There are constructors with different parameters.

### 6. Derived class functions override virtual base class functions.
render() and Update() are overrided

### 7. The project makes use of references in function declarations.
In the loop in game.cpp and controller.cpp, and render.cpp, enemyList are processed as reference.

### 8. The project uses smart pointers instead of raw pointers.
We're using shared_ptr for the instances of map and mt19937


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
