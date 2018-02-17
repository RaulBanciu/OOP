#pragma once
#include <iterator>
#include "Dog.h"

template <typename T>
class DynamicVector
{
private:
	T* elems;
	int length;
	int capacity;
	int current = 0;
	void ResizeVector();

public:
	//default contructor for DynamicVector
	DynamicVector(int capacity = 10);

	//copy constructor for DynamicVector
	DynamicVector(const DynamicVector& v);

	//destructor for DynamicVector
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	void operator-(const T& coat);

	/*
	Overloading the subscript operator
	Input: pos - a valid position within the vector.
	Output: a reference to the element o position pos.
	*/
	T& operator[](int pos);



	// Adds an element to the current DynamicVector.
	void add(const T& coat);

	//Removes an dog from the current DynamicVector
	void remove(int pos);

	//Update dog
	void updateDog(int pos, std::string newName,int age,int weight);

	int filter(const std::string& breed);
	int filter2(const std::string& breed);
	int getLength() const;
	void backCurrent();
	void current0();
	void setSize(int s) { size = s; }
	int next();
	int next2(const std::string& breed);

	Dog getCurrentDog();
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity = 10)
{
	this->length = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template <typename T>
void DynamicVector<T>::ResizeVector()
{
	this->capacity = this->capacity * 2;
	T* aux = new T[this->capacity];
	for (int i = 0; i < this->length; i++)
		aux[i] = this->elems[i];

	delete[] this->elems;
	this->elems = aux;
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	this->length = v.length;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->length; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->length = v.length;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->length; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template<typename T>
void DynamicVector<T>::operator-(const T& dog)
{
	int pos;
	for (int i = 0; i < this->length; i++)
	{
		if (this->elems[i] == dog)
			pos = i;
	}
	if (pos < this->length - 1)
		for (int i = pos; i < this->length - 1; i++)
		{
			this->elems[i] = this->elems[i + 1];
		}
	else
		this->elems[pos] = this->elems[pos + 1];
	this->length--;
}

template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}


template <typename T>
void DynamicVector<T>::backCurrent()
{
	if(this->current!=0)
		this->current = this->current - 1;
}

template <typename T>
void DynamicVector<T>::current0()
{
	this->current = 0;
}

template <typename T>
void DynamicVector<T>::add(const T& dog)
{
	if (this->length == this->capacity)
		ResizeVector();

	this->elems[this->length] = dog;
	this->length++;
}

template <typename T>
void DynamicVector<T>::remove(int pos)
{
	*this - this->elems[pos];
	this->current = this->current - 1;
	if (this->current < 0)
		this->current = 0;
	if (this->current >= this->length )
		this->current = 0;
}

template<typename T>
void DynamicVector<T>::updateDog(int pos,std::string newName, int age,int weight)
{
	Dog d{ this->elems[pos].getBreed(),newName,age,weight,this->elems[pos].getSource() };
	this->elems[pos] = d;
}



template <typename T>
int DynamicVector<T>::getLength() const
{
	return this->length;
}



template<typename T>
inline Dog DynamicVector<T>::getCurrentDog()
{
	return this->elems[this->current - 1];
}



template<typename T>
inline int DynamicVector<Dog>::next()
{
	std::string breed = this->elems[this->current].getBreed();
	return this->filter(breed);
}

template<typename T>
inline int DynamicVector<Dog>::next2(const std::string& breed)
{
	std::string breeds = breed;
	cout << breeds << endl;
	return this->filter2(breeds);
}

template<typename T>
inline int DynamicVector<Dog>::filter(const std::string & breed)
{
	if (this->length == 0)
		return -1;

	if (breed == "")
	{
		if (this->current == this->length)
			this->current = 0;
		this->elems[this->current].show();
		cout << this->elems[this->current].getName() << " is a " << this->elems[this->current].getAge() << " years old " << this->elems[this->current].getBreed() << " having " << this->elems[this->current].getWeight() << " Kilos" << endl;
	}
	else
	{
		const std::string & name = this->elems[this->current].getName();

		if (this->current != 0 && strcmp(breed.c_str(), this->elems[this->current - 1].getBreed().c_str()) != 0)
			this->current = 0;
		while (this->current < this->length && this->elems[this->current].getBreed() != breed &&	this->elems[this->current].getName() != name)
			this->current++;
		if (this->current >= this->length)
			this->current = 0;
		this->elems[this->current].show();
		cout << this->elems[this->current].getName() << " is a " << this->elems[this->current].getAge() << " years old " << this->elems[this->current].getBreed() << " having " << this->elems[this->current].getWeight() << " Kilos" << endl;
	}

	this->current++;

	return 0;
}

template<typename T>
inline int DynamicVector<Dog>::filter2(const std::string & breed)
{
	if (this->length == 0)
		return -1;

	if (breed == "")
	{
		if (this->current == this->length)
			this->current = 0;
		this->elems[this->current].show();
		cout << this->elems[this->current].getName() << " is a " << this->elems[this->current].getAge() << " years old " << this->elems[this->current].getBreed() << endl;
	}
	else
	{
		if (this->current != 0 && strcmp(breed.c_str(), this->elems[this->current - 1].getBreed().c_str()) != 0)
			this->current = 0;
		while (this->current < this->length && this->elems[this->current].getBreed() != breed)
			this->current++;
		if (this->current >= this->length)
		{
			this->current = 0;
			while (this->current < this->length && this->elems[this->current].getBreed() != breed)
				this->current++;
			if (this->current >= this->length)
				return -1;
		}
		this->elems[this->current].show();
		cout << this->elems[this->current].getName() << " is a " << this->elems[this->current].getAge() << " years old " << this->elems[this->current].getBreed() << endl;
	}

	this->current++;

	return 0;
}




