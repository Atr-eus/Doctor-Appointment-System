#include "../Appointment.h"
#include <iostream>
using namespace std;

Appointment::Appointment(const Date &d, const Time &t, bool done)
    : date(d), time(t), done(done) {};

void Appointment::update_staus() { done = true; }

bool Appointment::get_status() const { return done; }

void Appointment::display() const {
  string d = date, t = time;

  cout << "Date: " << d << endl;
  cout << "Time: " << t << endl;
  cout << "Done: " << (done ? "Yes" : "No") << endl;
}
