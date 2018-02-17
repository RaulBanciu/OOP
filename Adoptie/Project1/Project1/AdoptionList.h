#pragma once
#include "DynamicVector.h"
#include "Dog.h"


class AdoptionList
{
private:
	DynamicVector<Dog> list;

public:
	AdoptionList() {};

	DynamicVector<Dog> getDogs() const { return list; }

	void addToAdoptionList(const Dog& dog);
};