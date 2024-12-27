#include "../Patient.h"
#include "../Person.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const char SEPARATOR = '|';

inline void save_login(const string &filename, const string &data,
                       const string &username) {
  ofstream file(filename, ios::app);
  if (file.is_open()) {
    file << data << endl;
    cout << "Successfully registerd as " << username << "." << endl;
    file.close();
  } else {
    cout << "Failed to open: " << filename << "." << endl;
  }
}

inline vector<string> read_records(const string &filename) {
  vector<string> lines;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  return lines;
}

inline Patient get_patient_data(const string &username) {
  string age, gender, blood_pressure, body_temperature, symptoms;
  vector<string> patient_accounts = read_records("patients.txt");

  for (auto &account : patient_accounts) {
    if (account.find(username + SEPARATOR) == 0) {
      istringstream iss(account);
      getline(iss, age, SEPARATOR);
      getline(iss, age, SEPARATOR);
      getline(iss, age, SEPARATOR);
      getline(iss, gender, SEPARATOR);
      getline(iss, blood_pressure, SEPARATOR);
      getline(iss, body_temperature, SEPARATOR);
      getline(iss, symptoms);
    }
  }

  return Patient(username, age,
                 gender == "male" ? genders::male : genders::female,
                 blood_pressure, body_temperature, symptoms);
}
