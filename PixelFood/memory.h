#pragma once
#include <iostream>
#include <fstream> 
#include <string>
#include <cstdlib>


// Read from the text file

bool GameActive = true;
int LevelNumber = 0;

int PlayerPointer = 0;
int FoodPointer = 7;

int GridCells = 25;
char GridArray[25] = {};
int RawX = 5;

int CurrentBuilderPostion = 0;
int CurrentGridMakerPostion = -1;