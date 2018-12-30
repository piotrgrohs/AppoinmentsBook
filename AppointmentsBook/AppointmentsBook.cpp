// AppointmentsBook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "AppointmentsBook.h"

using namespace std;
int main()
{
	string inputValue; 
	Screen screen;
	screen.setTitle("Meeting schedule");
	while (true) {
		screen.menu();
		inputValue = screen.getInput();
		system("CLS");
		if (!screen.chooseMenu(stoi(inputValue))) {
			break;
		}
	}
}
