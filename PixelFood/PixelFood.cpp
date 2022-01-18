#include <iostream>
#include <string>

// Header files
#include "core.h"
#include "memory.h"


using namespace std;

int main()
{
	char PlayerInput;
	initGrid();
	while (GameActive)
	{
		cout << "\n       ";
		cin >> PlayerInput;
		system("CLS");
		MovePlayer(PlayerInput);
	}
}