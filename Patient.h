#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include <string>
using namespace std;

class Patient : public Person {
private:
  string blood_pressure;
  float body_temperature;
  string symptoms;

public:
  Patient(const string &, int, const genders &, const string &, float,
          const string &);
  void display() const;
};

#endif
