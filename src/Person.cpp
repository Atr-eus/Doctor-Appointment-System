#include "../Person.h"
#include "utils.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

Person::Person(const string &name, const string &age, const genders &gender)
    : name(name), age(age), gender(gender) {};

string Person::get_name() const { return name; };

string Person::get_age() const { return age; };

genders Person::get_gender() const { return gender; };

void Person::show_appointments() const {
  vector<string> appointments = read_records("appointments.txt");
  int c = 1;
  bool none_found = true;
  for (auto &appointment : appointments) {
    istringstream iss(appointment);
    string patient_name, doctor_name, date, time, is_done;

    if (getline(iss, patient_name, SEPARATOR) &&
        getline(iss, doctor_name, SEPARATOR) && getline(iss, date, SEPARATOR) &&
        getline(iss, time, SEPARATOR) && getline(iss, is_done)) {
      if (name == patient_name || name == doctor_name) {
        cout << "Appointment " << c++ << ":" << endl;
        cout << "Patient: " << patient_name << endl;
        cout << "Doctor: " << doctor_name << endl;

        int y, m, d, h, min, s;
        if (sscanf(date.c_str(), "%d/%d/%d", &y, &m, &d) == 3 &&
            sscanf(time.c_str(), "%d:%d:%d", &h, &min, &s)) {
          none_found = false;
          Appointment app(Date(y, m, d), Time(h, min, s),
                          is_done == "done" ? true : false);
          app.display();
        } else {
          cout << "Date: " << date << endl;
          cout << "Time: " << time << endl;
          cout << "Done: " << (is_done == "done" ? "Yes" : "No") << endl;
        }
        cout << endl;
      }
    }
  }
  if (none_found) {
    cout << "No appointment to show." << endl;
  }
}

void Person::display() const {
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "Gender: " << (gender ? "female" : "male") << endl;
}
