#include "../Appointment.h"
#include "../Doctor.h"
#include "../Patient.h"
#include <iostream>
using namespace std;

int main() {
  cout << "hello doctor" << endl;
  Patient p("John Doe", 22, genders::male, "120/80", 37.4,
            "chest pain, puking, headache");
  p.display();
  Appointment ap(Date(2024, 25, 12), Time(16, 31, 10), false);
  ap.display();

  Doctor d("Mike Hawk", 30, genders::female, "Neurologist");
  d.add_appointment(ap);
  d.display();

  return 0;
}
