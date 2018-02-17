#include "Dog.h"
#include <Windows.h>
#include <shellapi.h>

Dog::Dog() : breed(""), name(""), age(0),weight(0), source(""){}

Dog::Dog(const std::string& breed, const std::string& name, const int& age, const int& weight, const std::string& source) 
{
	this->breed=breed;
	this->name=name;
	this->age=age;
	this->weight = weight;
	this->source = source;
}

bool Dog::operator==(const Dog & dog)
{
	return this->breed == dog.getBreed() && this->name == dog.getName();
}

bool Dog::operator<(const int & val)
{
	return this->weight < val;
}

void Dog::show()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}