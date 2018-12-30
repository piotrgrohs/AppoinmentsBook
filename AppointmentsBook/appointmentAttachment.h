#pragma once
#include <string>
using namespace std;
class appointmentAttachment
{
public:
	appointmentAttachment();
	~appointmentAttachment();
	void setName(string name);
	void setLocation(string location);
	string getName() const;
	string getLocation() const;
private:
	int id;
	string name;
	string locationOfFile;
};

