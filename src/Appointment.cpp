#include "../Appointment.h"
#include <iostream>
using namespace std;

Appointment::Appointment(const Date &d, const Time &t, bool done = false)
    : date(d), time(t), done(done) {};

void Appointment::update_staus() { done = true; }

bool Appointment::get_status() const { return done; }

void Appointment::display() const {
  date.display();
  time.display();
  cout << "Done: " << (done ? "Yes" : "No") << endl;
}
