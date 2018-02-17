#include "UI.h"
#include <string>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator mode" << endl;
	cout << "2 - User mode" << endl;
	cout << "0 - Exit" << endl;
}

void UI::printAdministratorMode()
{
	cout << endl;
	cout << "Available commands: " << endl;
	cout << "1 - Add a Dog" << endl;
	cout << "2 - Delete a Dog" << endl;
	cout << "3 - Update Dog(new name and age)" << endl;
	cout << "4 - See all Dogs" << endl;
	cout << "5 - Seed all Dogs with a weight lower than" << endl;
	cout << "0 - Back" << endl;
}

void UI::printUserMode()
{
	cout << endl;
	cout << "1 - See dogs" << endl;
	cout << "2 - Show all the dogs of a given breed" << endl;
	cout << "3 - See adoption list" << endl;
	cout << "0 - Back" << endl;
}

int UI::addDogToRepo()
{
	std::string breed;
	std::string name;
	int age;
	int weight;
	std::string photo;

	cout << "Enter the breed: ";
	getline(cin, breed);
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter weight: ";
	cin >> weight;
	cin.ignore();
	cout << "Enter link: ";
	getline(cin, photo);

	return this->ctrl.addDogToRepo(breed,name,age,weight,photo);

}

void UI::checkIfLower()
{
	int weight;

	cout << "Enter the comparing value: ";
	cin >> weight;
	cin.ignore();

	DynamicVector<Dog> dogs = this->ctrl.getRepo().dogLower(weight);
	if (dogs.getLength() == 0)
	{
		cout << "No dogs with a lower weight\n";
	}
	for (int i = 0; i < dogs.getLength(); i++)
	{
		Dog d = dogs[i];
		cout << d.getName() << " is a " << d.getAge() << " years old " << d.getBreed() <<" having "<<d.getWeight()<<" Kilos"<< endl;

	}
}

void UI::listDogsRepo()
{
	DynamicVector<Dog> dogs = this->ctrl.getRepo().getDogs();
	if (dogs.getLength() == 0)
	{
		cout << "There are no dogs in the repository." << endl;
		return;
	}

	for (int i = 0; i < dogs.getLength(); i++)
	{
		Dog d = dogs[i];
		cout << d.getName() << " is a " << d.getAge() << " years old " << d.getBreed() << " having " << d.getWeight() << " Kilos" << endl;

	}
}

int UI::deleteFromRepo()
{
	std::string breed;
	std::string name;

	cout << "Enter the breed: ";
	getline(cin, breed);
	cout << "Enter name: ";
	getline(cin, name);
	return this->ctrl.deleteFromRepo(breed, name);
}

int UI::updateDogInRepo()
{

	std::string breed;
	std::string name;
	int age;
	int weight;
	std::string newName;
	std::string newWeight;

	cout << "Enter the breed: ";
	getline(cin, breed);
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter new age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter new name: ";
	getline(cin, newName);
	cout << "Enter new weight: ";
	cin >> weight;
	cin.ignore();
	if (newName == "")
		newName = name;
	return this->ctrl.updateDogInRepo(breed , name,newName,age,weight);
}


int UI::next()
{
	int x=this->ctrl.next();
	if (x == -1)
		printf("No more selected dogs\nQuit to main menu\n");
	return x;
}

int UI::next2(const std::string & breed)
{
	int x=this->ctrl.next2(breed);
	if (x == -1)
		printf("No more selected dogs\nQuit to main menu\n");
	return x;
}

void UI::adopt()
{
	this->ctrl.adopt();
	printf("Dog adopted!\n Next dog is now shown on screen\n");
}

void UI::adoptnextreturn()
{
	cout << endl;
	cout << "1 - Adopt" << endl;
	cout << "2 - Next" << endl;
	cout << "3 - Back" << endl;
}

void UI::current0()
{
	this->ctrl.current0();
}

void UI::filter()
{
	std::string breed;
	
	cout << "Give breed: ";
	getline(cin, breed);
	this->adoptnextreturn();
	if(breed=="")
	{
		int aux = this->ctrl.filter("");
		if (aux == -1)
			cout << "No dogs in database";
		int cmd;

		while (true)
		{
			cout << "Give command: ";
			cin >> cmd;
			cin.ignore();
			switch (cmd)
			{
			case 1:
				this->adopt();
				//this->ctrl.backCurrent();
				if (this->next() == -1)
					return;
				break;
			case 2:
				if (this->next() == -1)
					return;
				break;
			case 3:
				return;
				break;
			}
		}
	}
	else
	{
		int aux = this->ctrl.filter2(breed);
		if (aux == -1)
		{
			cout << "No dogs in database";
			return;
		}
		int cmd;

		while (true)
		{
			cout << "Give command: ";
			cin >> cmd;
			cin.ignore();
			switch (cmd)
			{
			case 1:
				this->adopt();
				if (this->next2(breed) == -1)
					return;
				break;
			case 2:
				if (this->next2(breed) == -1)
					return;
				break;
			case 3:
				return;
				break;
			}
		}
	}

}

void UI::show()
{
	this->adoptnextreturn();
	this->current0();
	int aux = this->ctrl.filter("");
	if (aux == -1)
		cout << "No dogs in database";
	int cmd;
	
	while (true)
	{
		cout << "Give command: ";
		cin >> cmd;
		cin.ignore();
		switch (cmd)
		{
		case 1:
			this->adopt();
			//this->ctrl.backCurrent();
			if (this->next() == -1)
				return;
			break;
		case 2:
			if (this->next() == -1)
				return;
			break;
		case 3:
			return;
			break;
		}
	}
}

void UI::listAdoptions()
{
	DynamicVector<Dog> dogs = this->ctrl.getAdoptionList().getDogs();
	if (dogs.getLength() == 0)
	{
		cout << "There are no dogs on the adoption list." << endl;
		return;
	}
	int nrad = 0;
	for (int i = 0; i < dogs.getLength(); i++)
	{
		Dog d = dogs[i];
		cout << d.getName() << " a " << d.getAge() << " years old " << d.getBreed() << " having " << d.getWeight() << " Kilos" << endl;
		nrad++;
	}

	cout << "You adopted " << nrad << " dogs"<<endl;
}






void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command;
		cout << "Give command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		if (command == 1)
		{
			while (true)
			{
				UI::printAdministratorMode();
				int cmd;
				cout << "Give command: ";
				cin >> cmd;
				cin.ignore();
				if (cmd == 0)
					break;

				switch (cmd)
				{
				case 1:
					if (this->addDogToRepo() == 1)
						cout << endl << "\tDog succesfully added." << endl;
					else
						cout << endl << "\tDog already exist." << endl;
					break;
				case 2:
					if (this->deleteFromRepo() == 1)
						cout << endl << "\tDog succesfully deleted." << endl;
					else
						cout << endl << "\tDog does not exist." << endl;
					break;
				case 3:
					if (this->updateDogInRepo() == 1)
						cout << endl << "\tDog succesfully updated." << endl;
					else
						cout << endl << "\tDog does not exist." << endl;
					break;
				case 4:
					this->listDogsRepo();
					break;
				case 5:
					this->checkIfLower();
					break;
				}
			}
		}
		else if (command == 2)
		{
			while (true)
			{
				UI::printUserMode();
				int cmd;
				cout << "Give command: ";
				cin >> cmd;
				cin.ignore();
				if (cmd == 0)
					break;
				switch (cmd)
				{
				case 1:
					this->show();
					break;
				case 2:
					this->filter();
					break;
				case 3:
					this->listAdoptions();
					break;
				default:
					break;
				}
			}
		}
	}
}

