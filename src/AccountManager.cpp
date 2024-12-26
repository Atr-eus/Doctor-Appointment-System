#include "../AccountManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const char SEPARATOR = '|';

void save_login(const string &filename, const string &data,
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

vector<string> read_records(const string &filename) {
  vector<string> lines;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  return lines;
}

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
    if (account.find(user + "|") == 0) {
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
    cout << "What to do? " << endl;
    cout << "1. Add appointment." << endl;
    cout << "2. Logout." << endl;
    cin >> opt;
    cin.ignore();

    if (opt == 1) {
    } else if (opt == 2) {
      cout << "Logging out from " << user << "." << endl;
    } else {
      cout << "Invalid choice, try again." << endl;
    }
  } while (opt != 2);
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
}

void AccountManager::display() const { cout << "hello manager" << endl; }