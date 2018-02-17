#pragma once
#include <iostream>

class Dog
{
private:
	std::string breed;
	std::string name;
	int age;
	int weight;
	std::string source;
public:
	//default constructor
	Dog();

	//constructor with parameters
	Dog(const std::string& breed, const std::string& name,const int& age,const int& weight, const std::string& source);

	std::string getBreed() const { return breed; }
	std::string getName() const { return name; }
	int getAge() const { return age; }
	int getWeight() const { return weight; }
	std::string getSource() const { return source; }

	bool operator==(const Dog& dog);

	bool operator<(const int & val);

	void show();
};