#include "UI.h"
#include <Windows.h>
#include <crtdbg.h>


using namespace std;

int main()
{
	{
		Repository repo{};
		Dog d1{ "Siberian Husky","Rex",7,12,"https://upload.wikimedia.org/wikipedia/commons/thumb/d/d2/Siberian_Husky_with_Blue_Eyes.jpg/220px-Siberian_Husky_with_Blue_Eyes.jpg"};
		Dog d2{ "Pug","Lucy",4,5,"http://cdn3-www.dogtime.com/assets/uploads/2011/01/file_23124_pug-460x290.jpg"};
		Dog d3{ "Labrador","Cory",2,20,"https://upload.wikimedia.org/wikipedia/commons/2/26/YellowLabradorLooking_new.jpg" };
		Dog d4{ "Beagle","Doris",6,7, "http://www.dogbreedinfo.com/images24/BeagleBayleePurebredDogs8Months1.jpg"};
		Dog d5{ "German Shepherd","Fox",10,26,"http://cdn2-www.dogtime.com/assets/uploads/gallery/german-shepherd-dog-breed-pictures/standing-7.jpg" };
		Dog d6{ "Rottweiler","Bruno",5,16,"https://upload.wikimedia.org/wikipedia/commons/thumb/7/7a/Rottweiler3.jpg/220px-Rottweiler3.jpg" };
		Dog d7{ "Bulldog","Fifi",3,8,"http://pbs.twimg.com/media/CO-ghuGWEAAGsFd.jpg:large" };
		Dog d8{	"Puddle","Sebastien",6,6,"http://cdn1-www.dogtime.com/assets/uploads/gallery/poodle-dog-breed-pictures/greaycoat-5.jpg" };
		Dog d9{ "American Pit Bull","Princess",4,7,"http://cdn1-www.dogtime.com/assets/uploads/gallery/pit-bull-dog-breed-pictures/pit-bull-dog-breed-picture-10.jpg" };
		Dog d10{ "Shih Tzu","Blitz",2,3,"http://cdn2-www.dogtime.com/assets/uploads/gallery/shih-tzu-dog-breed-pictures/shih-tzu-breed-picture-8.jpg" };
		Dog d11{ "Chow Chow","Leon",4,16,"https://encrypted-tbn1.gstatic.com/images?q=tbn:ANd9GcR0-8aTd1i8RZQ1bNiFwqN0RdAr8TWQ8Qo7QraghbiPjfIZv-eL"};
		Dog d12{ "Akita","Hachiko",6,18,"https://upload.wikimedia.org/wikipedia/commons/7/78/Akita_inu.jpeg"};
		Dog d13{ "Bulldog","Misu",5,7,"https://upload.wikimedia.org/wikipedia/commons/thumb/1/13/Clyde_The_Bulldog.jpg/220px-Clyde_The_Bulldog.jpg" };

		repo.addDog(d1);
		repo.addDog(d2);
		repo.addDog(d3);
		repo.addDog(d4);
		repo.addDog(d5);
		repo.addDog(d6);
		repo.addDog(d7);
		repo.addDog(d8);
		repo.addDog(d9);
		repo.addDog(d10);
		repo.addDog(d11);
		repo.addDog(d12);
		repo.addDog(d13);


		Controller ctrl{ repo };
		UI ui{ ctrl };
		ui.run();
	}
	_CrtDumpMemoryLeaks();


	return 0;
}