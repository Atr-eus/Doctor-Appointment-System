#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Date {
private:
  int day;
  int month;
  int year;

public:
  Date(int y, int m, int d) : day(d), month(m), year(y) {};

  operator string() const {
    ostringstream oss;
    oss << year << "/" << (month < 10 ? "0" : "") << month << "/"
        << (day < 10 ? "0" : "") << day;
    return oss.str();
  }
};

class Time {
private:
  int second;
  int minute;
  int hour;

public:
  Time(int h, int m, int s) : second(s), minute(m), hour(h) {};

  operator string() const {
    ostringstream oss;
    oss << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "")
        << minute << ":" << (second < 10 ? "0" : "") << second;
    return oss.str();
  }
};

class Appointment {
private:
  Date date;
  Time time;
  bool done;

public:
  Appointment(const Date &date, const Time &time, bool done = false);

  void update_staus();
  bool get_status() const;
  void display() const;
};

#endif
