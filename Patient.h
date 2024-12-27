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
  Patient(const string &, const string &, const genders &, const string &,
          const string &, const string &);
  void add_appointment() const;
  void display() const;
};

#endif
