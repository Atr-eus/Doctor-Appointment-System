#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char SEPARATOR = '|';

inline void save_login(const string &filename, const string &data,
                       const string &username) {
  ofstream file(filename, ios::app);
  if (file.is_open()) {
    file << data << endl;
    cout << "Successfully registerd as " << username << "." << endl;
    file.close();
  } else {
    cout << "Failed to open: " << filename << "." << endl;
  }
}

inline vector<string> read_records(const string &filename) {
  vector<string> lines;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  return lines;
}
