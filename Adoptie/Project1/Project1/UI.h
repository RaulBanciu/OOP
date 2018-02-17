#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printAdministratorMode();
	static void UI::printUserMode();

	int addDogToRepo();
	void checkIfLower();
	void listDogsRepo();
	int deleteFromRepo();
	int updateDogInRepo();
	void filter();
	void show();
	int next();
	int next2(const std::string & breed);
	void adopt();
	void adoptnextreturn();
	void current0();
	void listAdoptions();
};