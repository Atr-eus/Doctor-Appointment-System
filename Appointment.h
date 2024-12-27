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
  Date(int y, int m, int d);

  operator string() const;
};

class Time {
private:
  int second;
  int minute;
  int hour;

public:
  Time(int h, int m, int s);

  operator string() const;
};

class Appointment {
private:
  Date date;
  Time time;
  bool done;

public:
  Appointment(const Date &date, const Time &time, bool done = false);

  void display() const;
};

#endif
