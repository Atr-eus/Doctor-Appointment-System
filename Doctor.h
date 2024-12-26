#ifndef DOCTOR_H
#define DOCTOR_H

#include "Appointment.h"
#include "Person.h"
#include <string>
#include <vector>
using namespace std;

class Doctor : public Person {
private:
  string specialty;
  vector<Appointment> appointments;

public:
  Doctor(const string &name, const string &age, const genders &gender,
         const string &specialty);

  void add_appointment(const Appointment &appointment);
  void display() const;
};

#endif
