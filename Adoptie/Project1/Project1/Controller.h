#include "Repository.h"
#include "AdoptionList.h"

class Controller
{
private:
	Repository repo;
	AdoptionList list;

public:
	Controller(const Repository& r) : repo(r) {}

	Repository getRepo() const { return repo; }

	int addDogToRepo(const std::string& breed, const std::string& name, int age, int weight, const std::string& photo);

	int deleteFromRepo(const std::string& breed, const std::string& name);

	int updateDogInRepo(const std::string& breed, const std::string& name, const std::string& newName, int age,int weight);

	int filter(const std::string& breed);

	int filter2(const std::string & breed);

	void backCurrent();

	int next();

	int next2(const std::string & breed);

	void current0();

	DynamicVector<Dog> dogLower(int value);

	void adopt();

	AdoptionList getAdoptionList() const { return list; }
};