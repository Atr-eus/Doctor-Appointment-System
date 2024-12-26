#include "../Patient.h"
#include <iostream>
#include <string>
using namespace std;

Patient::Patient(const string &n, const string &a, const genders &g,
                 const string &bp, const string &bt, const string &smp)
    : Person(n, a, g), blood_pressure(bp), body_temperature(bt),
      symptoms(smp) {};

void Patient::display() const {
  Person::display();
  cout << "Blood pressure (celcius): " << blood_pressure << endl;
  cout << "Body temperature: " << blood_pressure << endl;
  cout << "Symptoms: " << symptoms << endl;
}
