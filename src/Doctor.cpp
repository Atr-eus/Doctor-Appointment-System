#include "../Doctor.h"
#include <iostream>
#include <string>
using namespace std;

Doctor::Doctor(const string &name, const string &age, const genders &gender,
               const string &specialty)
    : Person(name, age, gender), specialty(specialty) {};

void Doctor::add_appointment(const Appointment &appointment) {
  appointments.emplace_back(appointment);
}

void Doctor::display() const {
  Person::display();
  cout << "Specialty: " << specialty << endl;
  cout << "Appointments:" << endl;
  for (auto &appointment : appointments) {
    appointment.display();
  }
}
