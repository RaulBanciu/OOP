#pragma once
#include "Dog.h"
#include "DynamicVector.h"
#include "UI.h"

class Repository
{
private :
	DynamicVector<Dog> dogs;
	DynamicVector<UI> ui;
public:
	/*
	Default constructu=or.
	Initializes an object of type repository.
	*/
	Repository() {}

	/*
	Adds a song to the repository.
	Input: s - Song.
	Output: the song is added to the repository.
	*/
	DynamicVector<Dog> getDogs() const { return dogs; }

	bool findByBreedAndName(const std::string& breed, const std::string& name);

	int addDog(const Dog& s);

	std::string getSource(const std::string & breed, const std::string & name);

	int updateDog(const std::string & breed, const std::string & name, const std::string & newName,const int &age,const int& weight);

	int deleteDog(const std::string & breed, const std::string & name);

	void backCurrent();

	DynamicVector<Dog> Repository::dogLower(const int & value);

	int getPosition(const std::string & breed, const std::string & name);

	/*
	Finds a song, by artist and title.
	Input: artist, title - string
	Output: the song that was found, or an "empty" song (all fields empty and duration 0), if nothing was found.
	*/
	int filter(const std::string& breed);



	int searchBreed(const std::string & breed);

	void current0();

	int filter2(const std::string & breed);

	int next();
	int next2(const std::string & breed);
	Dog getCurrentDog();
};
