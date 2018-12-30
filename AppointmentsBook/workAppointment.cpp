#include "pch.h"
#include "workAppointment.h"



workAppointment::workAppointment()
{
	next = 0;
	attachment = new appointmentAttachment();
}


workAppointment::~workAppointment()
{
	delete attachment;
}

void workAppointment::setPlace(string place)
{
	this->place = place;
}

void workAppointment::setPeople(string people)
{
	this->people = people;
}

void workAppointment::setAttachment(string attachment)
{
	this->attachment->setName(attachment);
}

string workAppointment::getPlace()
{
	return this->place;
}

string workAppointment::getAttachment()
{
	return this->attachment->getName() ;
}

string workAppointment::getPeople()
{
	return this->people;
}
