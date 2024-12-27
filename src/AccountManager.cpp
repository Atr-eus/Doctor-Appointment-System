#include "../AccountManager.h"
#include "utils.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// AccountManager::AccountManager(const string &username, const string
// &password, const account_type &type) : username(username),
// password(password), type(type) {};

void AccountManager::patient_registration() const {
  cout << "Patient registration." << endl;

  string username, password, age, gender, blood_pressure, body_temperature,
      symptoms;
  cout << "Enter username: ";
  getline(cin, username);
  cout << "Enter password: ";
  getline(cin, password);

  cout << "Give us some general information about your health." << endl;
  cout << "Enter your age: ";
  getline(cin, age);
  cout << "Enter your gender: ";
  getline(cin, gender);
  cout << "Enter your blood pressure: ";
  getline(cin, blood_pressure);
  cout << "Enter your body temperature: ";
  getline(cin, body_temperature);
  cout << "Enter your symptoms: ";
  getline(cin, symptoms);

  save_login("patients.txt",
             username + SEPARATOR + password + SEPARATOR + age + SEPARATOR +
                 gender + SEPARATOR + blood_pressure + SEPARATOR +
                 body_temperature + SEPARATOR + symptoms,
             username);
}

bool AccountManager::patient_login() {
  cout << "Patient login." << endl;

  string username, password;
  cout << "Enter username: ";
  getline(cin, username);
  cout << "Enter password: ";
  getline(cin, password);

  vector<string> patient_accounts = read_records("patients.txt");

  for (const auto &account : patient_accounts) {
    string u, p;
    stringstream ss(account);
    getline(ss, u, SEPARATOR);
    getline(ss, p, SEPARATOR);

    if (username == u && password == p) {
      cout << "Logged in as " << username << "." << endl;
      user = username;
      return true;
    }
  }

  cout << "Invalid credentials." << endl;
  return false;
}

bool AccountManager::doctor_login() {
  cout << "Doctor login." << endl;

  string username, password;
  cout << "Enter username: ";
  getline(cin, username);
  cout << "Enter password: ";
  getline(cin, password);

  vector<string> doctors_accounts = read_records("doctors.txt");

  for (const auto &account : doctors_accounts) {
    string u, p;
    stringstream ss(account);
    getline(ss, u, SEPARATOR);
    getline(ss, p, SEPARATOR);

    if (username == u && password == p) {
      cout << "Logged in as " << username << "." << endl;
      user = username;
      return true;
    }
  }

  cout << "Invalid credentials." << endl;
  return false;
}

void AccountManager::patient_dashboard() const {
  vector<string> patient_accounts = read_records("patients.txt");
  string target;
  for (const auto &account : patient_accounts) {
    if (account.find(user + SEPARATOR) == 0) {
      target = account;
      break;
    }
  }

  stringstream ss(target);
  string age, gender, blood_pressure, body_temperature, symptoms;
  getline(ss, age, SEPARATOR);
  getline(ss, age, SEPARATOR);
  getline(ss, age, SEPARATOR);
  getline(ss, gender, SEPARATOR);
  getline(ss, blood_pressure, SEPARATOR);
  getline(ss, body_temperature, SEPARATOR);
  getline(ss, symptoms, SEPARATOR);

  transform(gender.begin(), gender.end(), gender.begin(),
            [](unsigned char c) { return tolower(c); });
  Patient patient(user, age,
                  (gender == "male" ? genders::male : genders::female),
                  blood_pressure, body_temperature, symptoms);

  patient.display();

  int opt;
  do {
    cout << endl << "What to do? " << endl;
    cout << "1. Add appointment." << endl;
    cout << "2. See my appointments." << endl;
    cout << "3. Logout." << endl;
    cout << "Enter your choice: ";
    cin >> opt;
    cin.ignore();

    if (opt == 1) {
      patient.add_appointment();
    } else if (opt == 2) {
      patient.show_appointments();
    } else if (opt == 3) {
      cout << "Logging out from " << user << "." << endl;
    } else {
      cout << "Invalid choice, try again." << endl;
    }
  } while (opt != 3);
}

void AccountManager::doctor_dashboard() const {
  vector<string> doctor_accounts = read_records("doctors.txt");
  string target;
  for (const auto &account : doctor_accounts) {
    if (account.find(user + "|") == 0) {
      target = account;
      break;
    }
  }

  stringstream ss(target);
  string gender, specialty;
  getline(ss, gender, SEPARATOR);
  getline(ss, gender, SEPARATOR);
  getline(ss, gender, SEPARATOR);
  getline(ss, specialty, SEPARATOR);

  transform(gender.begin(), gender.end(), gender.begin(),
            [](unsigned char c) { return tolower(c); });
  Doctor doctor(user, "30", gender == "male" ? genders::male : genders::female,
                specialty);
  doctor.display();

  int opt;
  do {
    cout << endl << "What to do? " << endl;
    cout << "1. See my appointments." << endl;
    cout << "2. Update appointment status." << endl;
    cout << "3. Logout." << endl;
    cout << "Enter your choice: ";
    cin >> opt;
    cin.ignore();

    if (opt == 1) {
      doctor.show_appointments();
    } else if (opt == 2) {
      doctor.show_appointments();
      doctor.update_appointment();
    } else if (opt == 3) {
      cout << "Logging out from " << user << "." << endl;
    } else {
      cout << "Invalid choice, try again." << endl;
    }
  } while (opt != 3);
}

void AccountManager::display() const { cout << "hello manager" << endl; }
