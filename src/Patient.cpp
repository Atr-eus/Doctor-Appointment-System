#include "../Patient.h"
#include "utils.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

Patient::Patient(const string &n, const string &a, const genders &g,
                 const string &bp, const string &bt, const string &smp)
    : Person(n, a, g), blood_pressure(bp), body_temperature(bt),
      symptoms(smp) {};

void Patient::add_appointment() const {
  string doctor_name, date, time;
  vector<string> doctor_accounts = read_records("doctors.txt");
  cout << endl << "Doctors in our database: " << endl;
  for (auto &account : doctor_accounts) {
    istringstream iss(account);
    string n, p, g, specialties;
    if (getline(iss, n, SEPARATOR) && getline(iss, p, SEPARATOR) &&
        getline(iss, g, SEPARATOR) && getline(iss, specialties)) {
      cout << "Name: " << n << endl;
      cout << "Specialties: " << specialties << endl;
    }
  }

  cout << "Enter doctor's name you'd like an appointment with: ";
  getline(cin, doctor_name);
  bool found = false;
  for (auto &account : doctor_accounts) {
    if (account.find(doctor_name + SEPARATOR) == 0) {
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "That doctor is not on our database." << endl;
    return;
  }

  cout << "Enter appointment date (yyyy/mm/dd): ";
  getline(cin, date);
  cout << "Enter appointment time (hh:mm:ss): ";
  getline(cin, time);

  ofstream file("appointments.txt", ios::app);
  if (file.is_open()) {
    file << name << SEPARATOR << doctor_name << SEPARATOR << date << SEPARATOR
         << time << SEPARATOR << "not_done" << endl;
    file.close();
    cout << "Booked appointment with " << doctor_name << " on " << date
         << " at " << time << "." << endl;
  } else {
    cout << "Failed to open file appointments.txt" << endl;
  }
}

void Patient::display() const {
  Person::display();
  cout << "Blood pressure: " << blood_pressure << endl;
  cout << "Body temperature: " << body_temperature << endl;
  cout << "Symptoms: " << symptoms << endl;
}
