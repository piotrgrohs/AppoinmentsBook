#pragma once
#include <string>
#include <time.h>
using namespace std;
class Date
{
public:
	Date();

	bool valid(string date);
	void setDate(string date);
	string getDate();
	string actualDate();
	~Date();
private:
	string date;
	bool isLeap(int year);
	bool validFormat(string date);
	bool validLenght(string date);
	
};

