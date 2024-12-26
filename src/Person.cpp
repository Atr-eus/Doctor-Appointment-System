#include "../Person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person(const string &name, const string &age, const genders &gender)
    : name(name), age(age), gender(gender) {};

string Person::get_name() const { return name; };

string Person::get_age() const { return age; };

genders Person::get_gender() const { return gender; };

void Person::display() const {
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "Gender: " << (gender ? "female" : "male") << endl;
}
