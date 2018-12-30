#include "pch.h"
#include "privateAppointmentList.h"
#include "privateAppointment.h"

void privateAppointmentList::add(string place, string date, string name, string description)
{
	privateAppointment* newAppointment = new privateAppointment();
	newAppointment->setDate(date);
	newAppointment->setDescription(description);
	newAppointment->setPlace(place);
	newAppointment->setName(name);
	if (first == nullptr) {
		first = newAppointment;
	}else {
		privateAppointment* temp = first;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newAppointment;
		newAppointment->next = 0;
	}

}

bool privateAppointmentList::del(int id)
{
	if (first != nullptr&& id<= countId()) {
		privateAppointment* temp = first;
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


int privateAppointmentList::countId()
{
	if(first!=nullptr)
	{
		int i = 0;
		privateAppointment* temp = first;
		while(temp!=nullptr)
		{
			i++;
			temp = temp->next;
		}
		return i;
	}
	return 0;
}

void privateAppointmentList::sortByDate()
{
	if(first!=nullptr&&first->next!=nullptr)
	{
		privateAppointment* temp = first;
		privateAppointment* second = first->next;
		while(temp!=nullptr)
		{
			if(second->getDate())
			temp = temp->next;
		}
	}
}

void privateAppointmentList::today(string date)
{
	privateAppointment* temp = first;
	int i = 1;
	while (temp != nullptr) {
		if(temp->getDate()==date){
		cout << i << ". Name: " << temp->getName() << ", Date: " << temp->getDate() << " ,Place: "
			<< temp->getPlace() << endl
			<< "Description: \n" << temp->getDescription() << endl;
		}
		i++;
		temp = temp->next;
	}
}

void privateAppointmentList::display()
{
	privateAppointment* temp = first;
	int i = 1;
	while (temp!= nullptr) {
		cout << i << ". Name: " << temp->getName() << ", Date: " << temp->getDate() <<" ,Place: " 
			<< temp->getPlace() << endl 
			<< "Description: \n" << temp->getDescription() << endl;
		i++;
		temp = temp->next;
	}
	
}



privateAppointmentList::privateAppointmentList()
{
	first = nullptr;
}


privateAppointmentList::~privateAppointmentList()
{
		
}


