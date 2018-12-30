#pragma once
#include "workAppointment.h"
#include <iostream>
using namespace std;
class workAppointmentList :
	public workAppointment
{
public:
	workAppointment* first;
	bool del(int id);
	workAppointmentList();
	~workAppointmentList();
	int countId();
	void add(string place, string date, string name, string people, string attachment, string descritpion);
	void display();
	void today(string date);
};

