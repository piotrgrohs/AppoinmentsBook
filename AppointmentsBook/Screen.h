#pragma once
#include <iostream>
#include <stack>
#include <string>
#include "privateAppointmentList.h"
#include "workAppointmentList.h"
#include "Date.h"
#define X 40
#define Y 20
using namespace std;
class Screen

{
public:
	Screen();
	void setTitle(string title);
	void menu();
	void print();
	void privateAppointmentListAdd();
	void workAppointmentListAdd();
	void privateAppointmentListDel();
	void workAppointmentListDel();
	bool chooseMenu(int inputValue);
	string getInput();
	~Screen();
private: 
	privateAppointmentList* privAppoint;
	workAppointmentList* workAppoint;
	char Tab[Y][X];
	char title[X];
	stack <string> displayList;
	Date* date;
	bool validDate(string date);
};

