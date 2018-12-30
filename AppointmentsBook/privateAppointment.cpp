#include "pch.h"
#include "privateAppointment.h"


privateAppointment::privateAppointment()
{
	next = 0;
}


privateAppointment::~privateAppointment()
{
}



void privateAppointment::setPlace(string place)
{
	this->place = place;
}

string privateAppointment::getPlace() 
{
	return this->place;
}
