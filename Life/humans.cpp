#include <iostream>
#include <string>

using namespace std;

enum Sex { a, b, intersex };
enum Gender { male, female, other };
enum Food { pizza };
static const string FoodStrings = { "pizza" };
enum Drink { water, coffee };
static const string DrinkStrings = { "water", "coffee" };

class Human {
    public:
	    Human(string fName, string lName, int age);
     	Human(string fName, string lName, int age, Sex sex);
    	Human(string fName, string lName, int age, Gender gender);
    	Human(string fName, string lName, int age, Sex sex, Gender gender);
    	~Human();
    	int age;
    	string fName, lName;
    	string pronouns[4];
    	void birthday();
    	void eat(Food edible);
    	void drink(Drink drinkable);
    	Sex getSex();
    	Gender getGender();
    	void setGender(Gender gender);
    private:
	    Sex sex;
	    Gender gender;
};

Human::Human(string fName, string lName, int age) {
	this->fName = fName;
	this->lName = lName;
	this->age = age;
}
Human::~Human() {
	cout << this->fName << " has died." << endl;
}
void Human::birthday() {
	this->age++;
	cout << "Happy birthday, " << this->fName << "!" << endl;
}
void Human::eat(Food edible) {
	cout << this->fName << " ate " << FoodStrings[edible] << "." << endl;
}
void Human::drink(Drink drinkable) {
	cout << this->fName << " drank " << DrinkStrings[drinkable] << "." << endl;
}
Sex Human::getSex() {
	return this->sex;
}
Gender Human::getGender() {
	return this->gender;
}
void Human::setGender(Gender gender) {
	this->gender = gender;
}

int main() {
	Human elon = Human("Elon", "Musk", 50);
}