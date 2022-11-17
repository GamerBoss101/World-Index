#pragma once

#include <iostream>
#include <string>

enum Sex { a, b, intersex };
enum Gender { male, female, other };
enum Food { pizza };
static const std::string FoodStrings = { "pizza" };
enum Drink { water, coffee };
static const std::string DrinkStrings = { "water", "coffee" };

class Human {
    public:
	    Human(std::string fName, std::string lName, int age);
     	Human(std::string fName, std::string lName, int age, Sex sex);
    	Human(std::string fName, std::string lName, int age, Gender gender);
    	Human(std::string fName, std::string lName, int age, Sex sex, Gender gender);
    	~Human();
    	int age;
    	std::string fName, lName;
    	std::string pronouns[4];
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

Human::Human(std::string fName, std::string lName, int age) {
	this->fName = fName;
	this->lName = lName;
	this->age = age;
}
Human::~Human() {
	std::cout << this->fName << " has died." << std::endl;
}
void Human::birthday() {
	this->age++;
	std::cout << "Happy birthday, " << this->fName << "!" << std::endl;
}
void Human::eat(Food edible) {
	std::cout << this->fName << " ate " << FoodStrings[edible] << "." << std::endl;
}
void Human::drink(Drink drinkable) {
	std::cout << this->fName << " drank " << DrinkStrings[drinkable] << "." << std::endl;
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

