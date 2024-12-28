#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include <string>
using namespace std;

class Patient : public Person {
private:
  string blood_pressure;
  string body_temperature;
  string symptoms;

public:
  Patient(const string &name, const string &age, const genders &gender,
          const string &blood_pressure, const string &body_temperature,
          const string &symptoms);

  void add_appointment() const;
  void display() const;
};

#endif
