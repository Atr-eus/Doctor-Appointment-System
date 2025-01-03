#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "Doctor.h"
#include "Patient.h"
#include <string>
using namespace std;

class AccountManager {
private:
  string user;

public:
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
