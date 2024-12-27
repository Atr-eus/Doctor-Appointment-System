#include "../Doctor.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Doctor::Doctor(const string &name, const string &age, const genders &gender,
               const string &specialty)
    : Person(name, age, gender), specialty(specialty) {};

void Doctor::update_appointment() const {
  int target;
  cout << "Enter which appointment to update: ";
  cin >> target;

  vector<string> appointments = read_records("appointments.txt");
  vector<string> doctor_appointments;
  vector<int> doctor_indices;
  for (int i = 0; i < static_cast<int>(appointments.size()); ++i) {
    istringstream iss(appointments[i]);
    string patient_name, doctor_name, date, time, status;
    if (getline(iss, patient_name, SEPARATOR) &&
        getline(iss, doctor_name, SEPARATOR) && getline(iss, date, SEPARATOR) &&
        getline(iss, time, SEPARATOR) && getline(iss, status)) {
      if (doctor_name == name) {
        doctor_appointments.push_back(appointments[i]);
        doctor_indices.push_back(i);
      }
    }
  }

  if (target <= 0 || target > static_cast<int>(doctor_appointments.size())) {
    cout << "Choice is out of bound." << endl;
    return;
  }
  string target_appointment = doctor_appointments[target - 1];
  int real_idx = doctor_indices[target - 1];

  istringstream iss(target_appointment);
  string patient_name, doctor_name, date, time, status;
  if (getline(iss, patient_name, SEPARATOR) &&
      getline(iss, doctor_name, SEPARATOR) && getline(iss, date, SEPARATOR) &&
      getline(iss, time, SEPARATOR) && getline(iss, status)) {
    if (status == "done") {
      status = "not_done";
    } else if (status == "not_done") {
      status = "done";
    } else {
      cout << "Invalid status in appointment.txt." << endl;
      return;
    }
    string updated_appointment = patient_name + SEPARATOR + doctor_name +
                                 SEPARATOR + date + SEPARATOR + time +
                                 SEPARATOR + status;
    appointments[real_idx] = updated_appointment;

    ofstream file("appointments.txt");
    if (file.is_open()) {
      for (auto &appointment : appointments) {
        file << appointment << endl;
      }
      file.close();
      cout << "Updated status for " << target << "th " << "appointment."
           << endl;
    } else {
      cout << "Unable to open file: appointment.txt" << endl;
    }
  }
}

void Doctor::display() const {
  Person::display();
  cout << "Specialty: " << specialty << endl;
  cout << "Appointments:" << endl;
}
