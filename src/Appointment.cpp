#include "../Appointment.h"
#include <iostream>
using namespace std;

Date::Date(int y, int m, int d) : day(d), month(m), year(y) {};

Date::operator string() const {
  ostringstream oss;
  oss << year << "/" << (month < 10 ? "0" : "") << month << "/"
      << (day < 10 ? "0" : "") << day;
  return oss.str();
}

Time::Time(int h, int m, int s) : second(s), minute(m), hour(h) {};

Time::operator string() const {
  ostringstream oss;
  oss << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "")
      << minute << ":" << (second < 10 ? "0" : "") << second;
  return oss.str();
}

Appointment::Appointment(const Date &d, const Time &t, bool done)
    : date(d), time(t), done(done) {};

void Appointment::display() const {
  string d = date, t = time;

  cout << "Date: " << d << endl;
  cout << "Time: " << t << endl;
  cout << "Done: " << (done ? "Yes" : "No") << endl;
}
