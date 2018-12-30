#pragma once
#include "appointment.h"
#include "appointmentAttachment.h"
class privateAppointment :
	public appointment
{
public:
	privateAppointment();
	~privateAppointment();
	void setPlace(string place);
	string getPlace();
	privateAppointment* next;
private:
	string place;
	
};

