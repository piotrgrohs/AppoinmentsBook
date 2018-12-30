#include "pch.h"
#include "appointmentAttachment.h"


appointmentAttachment::appointmentAttachment()
{
}


appointmentAttachment::~appointmentAttachment()
{
}

void appointmentAttachment::setName(string name)
{
	this->name = name;
}

void appointmentAttachment::setLocation(string location)
{
	this->locationOfFile = location;
}

string appointmentAttachment::getName() const
{
	return this->name;
}

string appointmentAttachment::getLocation() const
{
	return this->locationOfFile;
}
