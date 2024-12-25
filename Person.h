#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

enum genders { male, female };

class Person {
private:
  string name;
  int age;
  genders gender;

public:
  Person(const string &, int, const genders &);

  string get_name() const;
  int get_age() const;
  genders get_gender() const;
  void display() const;
};

#endif
