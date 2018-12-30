#pragma once
#include "appointment.h"
#include "appointmentAttachment.h"
class workAppointment :
	public appointment
{
public:
	workAppointment();
	~workAppointment();
	void setPlace(string place);
	void setPeople(string people);
	void setAttachment(string attachment);
	string getPlace();
	string getAttachment();
	string getPeople();
	workAppointment* next;
private:
	string people;
	string place;
	appointmentAttachment * attachment;
};

