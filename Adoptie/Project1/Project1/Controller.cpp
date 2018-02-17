#include "Controller.h"

int Controller::addDogToRepo(const std::string& breed, const std::string& name, int age,int weight, const std::string& photo)
{
	Dog Dog{ breed, name, age, weight, photo };
	return this->repo.addDog(Dog);
}

int Controller::deleteFromRepo(const std::string& breed, const std::string& name)
{
	return this->repo.deleteDog(breed, name);
}

int Controller::updateDogInRepo(const std::string& breed, const std::string& name,const std::string& newName,int age,int weight)
{
	return this->repo.updateDog(breed, name,newName, age,weight);
}

int Controller::filter(const std::string & breed)
{
	return this->repo.filter(breed);
}
int Controller::filter2(const std::string & breed)
{
	return this->repo.filter2(breed);
}

void Controller::backCurrent()
{
	this->repo.backCurrent();
}


int Controller::next()
{
	return this->repo.next();
}

int Controller::next2(const std::string & breed)
{
	return this->repo.next2(breed);
}

void Controller::current0()
{
	this->repo.current0();
}

DynamicVector<Dog> Controller::dogLower(int value)
{
	DynamicVector<Dog> lower;
	lower = this->repo.dogLower(value);
	return lower;
}

void Controller::adopt()
{
	Dog dog = this->repo.getCurrentDog();
	this->list.addToAdoptionList(dog);
	this->repo.deleteDog(dog.getBreed(), dog.getName());
}
