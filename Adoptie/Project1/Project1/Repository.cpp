#include "Repository.h"
#include <string>

using namespace std;


bool Repository::findByBreedAndName(const std::string& breed, const std::string& name)
{
	for (int i = 0; i < this->dogs.getLength(); i++)
	{
		Dog d = dogs[i];
		if (d.getBreed() == breed && d.getName() == name)
			return 1;
	}

	return 0;
}

///admin
int Repository::addDog(const Dog& s)
{
	if (findByBreedAndName(s.getBreed(), s.getName()) == 0)
	{
		this->dogs.add(s);
		return 1;
	}

	return 0;
}

std::string Repository::getSource(const std::string & breed, const std::string & name)
{
	for (int i = 0; i < this->dogs.getLength(); i++)
	{
		Dog d = dogs[i];
		if (d.getBreed() == breed && d.getName() == name)
			return d.getSource;
	}

	return 0;
}

int Repository::updateDog(const std::string & breed, const std::string & name, const std::string & newName, const int & age,const int& weight)
{
	if (findByBreedAndName(breed, name) == 1)
	{

		int pos = getPosition(breed, name);
		if (findByBreedAndName(breed, newName) == 1)
			return 0;
		Dog d{ breed,newName,age,weight,this->getSource(breed,name) };
		this->dogs.updateDog(pos,newName,age,weight);
		return 1;
	}
	return 0;
}

int Repository::deleteDog(const std::string& breed, const std::string& name)
{
	if (findByBreedAndName(breed, name) == 1)
	{

		int pos = getPosition(breed, name);
		this->dogs.remove(pos);
		return 1;
	}
	return 0;
}

void Repository::backCurrent()
{
	this->dogs.backCurrent();
}

DynamicVector<Dog> Repository::dogLower( const int & value)
{
	DynamicVector<Dog> dogs2;
	for (int i = 0; i < this->dogs.getLength(); i++)
	{
		Dog d = dogs[i];
		if (d < value)
			dogs2.add(d);
	}
	return dogs2;
}

int Repository::getPosition(const std::string& breed, const std::string& name)
{
	for (int i = 0; i < this->dogs.getLength(); i++)
	{
		Dog d = dogs[i];
		if (d.getBreed() == breed && d.getName() == name)
			return i;
	}
}

int Repository::filter(const std::string & breed)
{
	return this->dogs.filter(breed);
}

int Repository::searchBreed(const std::string & breed)
{
	for (int i = 0; i < this->dogs.getLength(); i++)
	{
		Dog d = dogs[i];
		if (d.getBreed() == breed)
			return 1;
	}
	return 0;
}

void Repository::current0()
{
	this->dogs.current0();
}

int Repository::filter2(const std::string & breed)
{
	if (!searchBreed(breed))
		return -1;
	return this->dogs.filter2(breed);
}

int Repository::next()
{
	return this->dogs.next();
}

int Repository::next2(const std::string & breed)
{
	return this->dogs.next2(breed);
}

Dog Repository::getCurrentDog()
{
	return this->dogs.getCurrentDog();
}

