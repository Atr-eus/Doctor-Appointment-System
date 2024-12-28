#include "../AccountManager.h"
#include <iostream>
using namespace std;

int main() {
  cout << "  .-----." << endl
       << " ( o   o )" << endl
       << "  |  ^  | " << endl
       << "  | '-' |  " << endl
       << "   -----   " << endl
       << "  /     \\ " << endl
       << " /       \\ " << endl
       << "/  O O O  \\ " << endl
       << "|   DOC   |" << endl;
  cout << "Welcome to the doctor's appointment system." << endl << endl;

  int opt;
  do {
    cout << "What would you like to do?" << endl;
    cout << "1. Register as a patient." << endl;
    cout << "2. Login as a patient." << endl;
    cout << "3. Login as a doctor." << endl;
    cout << "4. Quit." << endl;
    cout << "Enter your choice: ";
    cin >> opt;
    cin.ignore();
    AccountManager accountmanager;

    if (opt == 1) {
      accountmanager.patient_registration();
    } else if (opt == 2) {
      if (accountmanager.patient_login()) {
        accountmanager.patient_dashboard();
      }
    } else if (opt == 3) {
      if (accountmanager.doctor_login()) {
        accountmanager.doctor_dashboard();
      }
    } else if (opt == 4) {
      cout << "Quitting." << endl;
    } else {
      cout << "Invalid choice, try again." << endl;
    }
  } while (opt != 4);

  return 0;
}
