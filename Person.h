#ifndef PERSON_H
#define PERSON_H

#include "Appointment.h"
#include <string>
using namespace std;

enum genders { male, female };

class Person {
protected:
  string name;
  string age;
  genders gender;

public:
  Person(const string &name, const string &age, const genders &gender);

  void show_appointments() const;
  void display() const;
};

#endif
