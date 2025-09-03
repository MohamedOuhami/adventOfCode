#include <day3.h>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

string read_data() {

  string data_path = "../data/day3.txt";
  string allData;
  string dataLine;

  ifstream data_stream(data_path);

  while (getline(data_stream, dataLine)) {
    // cout << dataLine << endl;
    allData += dataLine;
  };

  return allData;
}

int calculateMuls(string data) {

  int totalMul = 0;

  // Get only the data that is between a do() and don't()
  //
  // The regex object to use in the search in the string
  
  regex doRegex(R"(do\(\))");
  regex dontRegex(R"(don't\(\))");
  regex mul(R"(mul\((\d+),(\d+)\))");
  regex fullReg(R"(do\(\)|don't\(\)|mul\(\d+,\d+\))");

  bool doFlag = true;

  auto it = sregex_iterator(data.begin(), data.end(), fullReg);
  auto end = sregex_iterator();

  while (it != end) {

    string token = it->str();
    smatch match;

    if (regex_match(token, doRegex)) {
      doFlag = true;
    }

    else if (regex_match(token, dontRegex)) {
      doFlag = false;
    }

    else if (regex_match(token, match,mul) && doFlag) {

     totalMul += stoi(match[1]) * stoi(match[2]);

    }

    it++;
  }


  return totalMul;
}
