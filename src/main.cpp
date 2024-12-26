#include "../AccountManager.h"
#include "../Appointment.h"
#include "../Doctor.h"
#include "../Patient.h"
#include <iostream>
using namespace std;

int main() {
  cout << "  .-----." << endl;
  cout << " ( o   o )" << endl;
  cout << "  |  ^  | " << endl;
  cout << "  | '-' |  " << endl;
  cout << "   -----   " << endl;
  cout << "  /     \\ " << endl;
  cout << " /       \\ " << endl;
  cout << "/  O O O  \\ " << endl;
  cout << "|   DOC   |" << endl;
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

  cout << endl << endl << endl;
  Patient p("John Doe", "22", genders::male, "120/80", "37.4",
            "chest pain, puking, headache");
  p.display();
  Appointment ap(Date(2024, 25, 12), Time(16, 31, 10), false);
  ap.display();

  Doctor d("Mike Hawk", "30", genders::female, "Neurologist");
  d.add_appointment(ap);
  d.display();

  return 0;
}
