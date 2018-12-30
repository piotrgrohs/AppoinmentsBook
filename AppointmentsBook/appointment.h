#pragma once
#include <string>
using namespace std;
class appointment
{
public:
	appointment();
	appointment(string date, string name, string description);
	~appointment();
	void setDate(string date);
	void setName(string name);
	void setDescription(string description);

	string getDate() const;
	string getName() const;
	string getDescription() const;
private: 
	string date;
	string name;
	string description;
	

};

