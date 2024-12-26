#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "Doctor.h"
#include "Patient.h"
#include <string>
using namespace std;

enum account_type { patient, doctor };

class AccountManager {
private:
  string user;
  // string password;
  // account_type type;

public:
  // AccountManager(const string &username, const string &password, const
  // account_type &type);

  void patient_registration() const;
  bool patient_login();
  bool patient_logout();
  bool doctor_login();
  bool doctor_logout();
  void patient_dashboard() const;
  void doctor_dashboard() const;
  void display() const;
};

#endif
