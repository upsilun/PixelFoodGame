#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <fstream> 

#include "memory.h"

using namespace std;



void initGrid() {
	cout << "########  #### ##     ## ######## ##       ########  #######   #######  ########  \n";
	cout << "##     ##  ##   ##   ##  ##       ##       ##       ##     ## ##     ## ##     ## \n";
	cout << "##     ##  ##    ## ##   ##       ##       ##       ##     ## ##     ## ##     ## \n";
	cout << "########   ##     ###    ######   ##       ######   ##     ## ##     ## ##     ## \n";
	cout << "##         ##    ## ##   ##       ##       ##       ##     ## ##     ## ##     ## \n";
	cout << "##         ##   ##   ##  ##       ##       ##       ##     ## ##     ## ##     ## \n";
	cout << "##        #### ##     ## ######## ######## ##        #######   #######  ########  \n\n";

	for (int i = 0; i <= (sizeof(GridArray) / sizeof(*GridArray)) - 1; i++) {

		if (CurrentBuilderPostion == 5) {
			cout << "\n";
			CurrentBuilderPostion = 0;
		}

		if (PlayerPointer == FoodPointer) {
			LevelNumber = LevelNumber + 1;
			cout << "##      ##  ####  ##    ##   ### \n";
			cout << "##  ##  ##   ##   ###   ##   ### \n";
			cout << "##  ##  ##   ##   ####  ##   ### \n";
			cout << "##  ##  ##   ##   ## ## ##    #  \n";
			cout << "##  ##  ##   ##   ##  ####       \n";
			cout << "##  ##  ##   ##   ##   ###   ### \n";
			cout << " ###  ###   ####  ##    ##   ### \n\n";
			cout << LevelNumber << endl;
			Beep(722, 500);
			Sleep(500);
			srand((int)time(0));
			int NewFood = (rand() % 24) + 1;
			system("CLS");
			cout << NewFood << " " << i << " " << CurrentBuilderPostion;
			Sleep(100);
			FoodPointer = NewFood;
			PlayerPointer = 0;
			system("CLS");
			CurrentBuilderPostion = 0;
			initGrid();
			break;
		}

		if (PlayerPointer == i) {
			cout << " O ";
			CurrentBuilderPostion = CurrentBuilderPostion + 1;
		}
		else {
			if (FoodPointer == i) {
				cout << " X ";
				CurrentBuilderPostion = CurrentBuilderPostion + 1;
			}
			else {
				cout << " # ";
				CurrentBuilderPostion = CurrentBuilderPostion + 1;
			}
		}
	}
}

void MovePlayer(char playerinput) {
	switch (playerinput) {
		case 'W':
		case 'w':
			if (PlayerPointer >= 5) {
				PlayerPointer = PlayerPointer - 5;
				Beep(422, 200);
				initGrid();
			}
			else {
				Beep(222, 200);
				initGrid();
			}
			break;
		case 'S':
		case 's':
			if (PlayerPointer <= GridCells - 6) {
				PlayerPointer = PlayerPointer + 5;
				Beep(422, 200);
				initGrid();
			}
			else {
				Beep(222, 200);
				initGrid();
			}
			break;
		case 'D':
		case 'd':
			if (PlayerPointer <= GridCells - 2) {
				PlayerPointer = PlayerPointer + 1;
				Beep(422, 200);
				initGrid();
			}
			else {
				Beep(222, 200);
				initGrid();
			}
			break;
		case 'A':
		case 'a':
			if (PlayerPointer > 0) {
				PlayerPointer = PlayerPointer - 1;
				Beep(422, 200);
				initGrid();
			}
			else {
				Beep(222, 200);
				initGrid();
			}
			break;
	}
}