#include "pch.h"
#include "Screen.h"


Screen::Screen()
{
	string temp = ""; 
	for (int i = 0; i < X; i++) {
		temp += "*";
	}
	displayList.push(temp);
	privAppoint = new privateAppointmentList;
	workAppoint = new workAppointmentList;
	date = new Date();
}

void Screen::setTitle(string title)
{
	displayList.push(title);
}
void Screen::menu() 
{
	displayList.push("1. Create private appointment");
	displayList.push("2. Create work appointment");
	displayList.push("3. Show private appointments");
	displayList.push("4. Show work appointments");
	displayList.push("5. Today mettings");
	displayList.push("6. Delete private appointment");
	displayList.push("7. Delete work appointment");
	displayList.push("8. Exit");
	displayList.push("Today date: "+date->actualDate());
	print();
}


void Screen::print()
{
	/*Inverting STL list, to display in correct way
	*/
	stack <string> displayListInvertion;
	int displaySize = displayList.size();
	for (int i = 0; i < displaySize; i++) {
		displayListInvertion.push(displayList.top());
		displayList.pop();
	}
	while (displayListInvertion.empty() == false) {
		cout << displayListInvertion.top() << endl;
		displayListInvertion.pop();
	}
}
void Screen::privateAppointmentListAdd()
{
	cout << "Write place:" << endl;
	const auto place = getInput();
	cout << "Write date:" << endl;
	string date;
	while(true)
	{		
		date = getInput();
	if(validDate(date))
	{
		break;
	}
		cout << "Write correct date (DD.MM.YYY)" << endl;
	}
	cout << "Write name:" << endl;
	const auto name = getInput();
	cout << "Write description:" << endl;
	const auto description = getInput();
	privAppoint->add(place, date, name, description);
}
void Screen::workAppointmentListAdd()
{
	cout << "Write place:" << endl;
	const auto place = getInput();
	cout << "Write date:" << endl;
	string date;
	while (true)
	{
		date = getInput();
		if (validDate(date))
		{
			break;
		}
		cout << "Write correct date (DD.MM.YYY)" << endl;
	}
	cout << "Write name:" << endl;
	const auto name = getInput();
	cout << "Write description:" << endl;
	const auto description = getInput();
	cout << "Write attachment location:" << endl;
	const auto attachment = getInput();
	cout << "Write people to meeting:" << endl;
	const auto people = getInput();
	workAppoint->add( place,  date,  name,  people,  attachment,  description);
}

void Screen::privateAppointmentListDel()
{
	cout << "Write id: " << endl;
	int id = stoi(getInput());
	if (!privAppoint->del(id))
	{
		cout << "Wrong id" << endl;
	}
}

void Screen::workAppointmentListDel()
{
	cout << "Write id: " << endl;
	int id = stoi(getInput());
	if(!workAppoint->del(id))
	{
		cout << "Wrong id" << endl;
	}
}

bool Screen::chooseMenu(int inputValue) {
	/*Choose menu for choosing menu input
	*/
	switch (inputValue)
	{
	case 1:
		privateAppointmentListAdd();
		break;
	case 2:
		workAppointmentListAdd();
		break;
	case 3:
		privAppoint->display();
		break;
	case 4:
		workAppoint->display() ;
		break;
	case 5:
		privAppoint->today(date->actualDate());
		workAppoint->today(date->actualDate());
		break;
	case 6:
		privateAppointmentListDel();
		break;
	case 7:
		workAppointmentListDel();
		break;
	case 8:
		return false;
		break;
	
	default:
		break;
	}
	return true;
}
string Screen::getInput() {
	string temp; 
	cin >> temp;
	return temp;
}

Screen::~Screen()
{
	delete(privAppoint);
	delete(date);
}

bool Screen::validDate(string date) 
{
	return this->date->valid(date);
}

