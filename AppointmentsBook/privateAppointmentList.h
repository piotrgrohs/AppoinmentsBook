#pragma once
#include "privateAppointment.h"
#include <iostream>
#include "workAppointment.h"
using namespace std;

class privateAppointmentList
{
public:
	privateAppointment* first;
	void add(string place, string date, string name, string description);
	bool del(int id);
	int countId();
	void sortByDate();
	void today(string date);
	void display();
	privateAppointmentList();
	~privateAppointmentList();
};

