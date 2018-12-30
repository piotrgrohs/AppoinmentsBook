#include "pch.h"
#include "Date.h"
#include <sstream>


Date::Date()
{
}
bool Date::isLeap(int year)
{
	return (((year % 4 == 0) &&
		(year % 100 != 0)) ||
		(year % 400 == 0));
}

bool Date::valid(string date)
{
	if (validLenght(date))
	{
		if (validFormat(date)) {
			string day = date.substr(0, 1);
			string month = date.substr(3, 4);
			string year = date.substr(6, 9);
			/* Converting string month day and year to int
			*/
			int m = stoi(day);
			int d = stoi(month);
			int y = stoi(year);

			/* Checking month and day in range
			*/
			if (m < 1 || m > 12)
				return false;
			if (d < 1 || d > 31)
				return false;
			if (m == 2)
			{
				if (isLeap(y))
					return (d <= 29);
				else
					return (d <= 28);
			}
			if (m == 4 || m == 6 ||
				m == 9 || m == 11)
				return (d <= 30);
			return true;
		}
	}
	return false;
}


void Date::setDate(string date)
{
	this->date = date;
}

string Date::getDate()
{
	return this->date;
}


Date::~Date()
{
}

bool Date::validFormat(string date)
{
	/* Checking format of date
	*/
	return !(date.at(2) != '.' || date.at(5) != '.');
}

bool Date::validLenght(string date)
{
	/* Checking lenght of date
	*/
	return date.length() == 10;
}

string Date::actualDate()
{
	time_t now;
	time(&now);
	struct tm* data = localtime(&now);
	string actualDate = to_string(data->tm_mday) + '.' + to_string(data->tm_mon + 1) + '.' + to_string(
		data->tm_year + 1900);
	return actualDate;
}
