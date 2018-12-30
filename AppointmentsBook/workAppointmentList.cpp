#include "pch.h"
#include "workAppointmentList.h"


workAppointmentList::workAppointmentList()
{
	first = nullptr;
}


workAppointmentList::~workAppointmentList()
{
}

int workAppointmentList::countId()
{
	if (first != nullptr)
	{
		int i = 0;
		workAppointment* temp = first;
		while (temp != nullptr)
		{
			i++;
			temp = temp->next;
		}
		return i;
	}
	return 0;
}

void workAppointmentList::add(string place, string date, string name, string people,string attachment,string descritpion)
{
	workAppointment* newAppointment = new workAppointment();
	newAppointment->setDate(date);
	newAppointment->setPeople(people);
	newAppointment->setPlace(place);
	newAppointment->setName(name);
	newAppointment->setAttachment(attachment);
	newAppointment->setDescription(descritpion);
	if (first == nullptr) {
		first = newAppointment;
	}
	else {
		workAppointment* temp = first;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newAppointment;
		newAppointment->next = 0;
	}
}

void workAppointmentList::display()
{
	
	workAppointment* temp = first;
	int i = 1;
	while (temp != nullptr) {
		cout << i << ". Name: " << temp->getName() << ", Date: " << temp->getDate() << " ,Place: "
			<< temp->getPlace() << endl
			<< "People: \n" << temp->getPeople() << endl
			<< "Description: \n" << temp->getDescription() << endl
			<< "Attachment: \n" << temp->getAttachment() << endl;
		i++;
		temp = temp->next;
	}
}

void workAppointmentList::today(string date)
{
	workAppointment* temp = first;
	int i = 1;
	while (temp != nullptr) {
		if (temp->getDate() == date) {
			cout << i << ". Name: " << temp->getName() << ", Date: " << temp->getDate() << " ,Place: "
				<< temp->getPlace() << endl
				<< "People: \n" << temp->getPeople() << endl
				<< "Description: \n" << temp->getDescription() << endl
				<< "Attachment: \n" << temp->getAttachment() << endl;
		}
		i++;
		temp = temp->next;
	}
}


bool workAppointmentList::del(int id)
{
	if (first != nullptr&& id <= countId()) {
		workAppointment* temp = first;
		if (id == 1)
		{
			first = temp->next;
			return true;
		}
		if (id >= 2)
		{
			int i = 1;
			while (temp)
			{
				if (i + 1 == id) break;

				temp = temp->next;
				i++;
			}

			if (temp->next->next == 0)
				temp->next = 0;
			else
				temp->next = temp->next->next;

			return true;
		}
	}
	return false;
}
