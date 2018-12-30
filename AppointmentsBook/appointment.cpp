#include "pch.h"
#include "appointment.h"



appointment::appointment()
{

}

appointment::appointment(string date, string name, string description)
{
	this->date = date;
	this->description = description;
	this->name = name;
}


appointment::~appointment()
{
}

void appointment::setDate(string date)
{
	this->date = date;
}

void appointment::setName(string name)
{
	this->name = name;
}

void appointment::setDescription(string description)
{
	this->description = description;
}

string appointment::getDate() const
{
	return this->date;
}

string appointment::getName() const
{
	return this->name;
}

string appointment::getDescription() const
{
	return this->description;
}
