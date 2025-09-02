#include <cstdlib>
#include <day2.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
bool isCurrentSafe(int current, int next, OrderStatus &orderStatus) {

  // cout << "Comparing " << current << " to " << next << endl;
  if (orderStatus == ASC) {

    return (current < next) && (abs(current - next) >= 1) &&
           (abs(current - next) <= 3);
  } else if (orderStatus == DESC) {

    return (current > next) && (abs(current - next) >= 1) &&
           (abs(current - next) <= 3);
  } else if (orderStatus == NOT_DEFINED) {

    if (current < next) {
      orderStatus = ASC;

      return (current < next) && (abs(current - next) >= 1) &&
             (abs(current - next) <= 3);

    } else if (current > next) {

      orderStatus = DESC;
      return (current > next) && (abs(current - next) >= 1) &&
             (abs(current - next) <= 3);

    } else {
      return false;
    }
  } else {

    return false;
  }
}

bool checkLineSafetyAfterChange(vector<int> &reports) {

  OrderStatus currentOrder = NOT_DEFINED;

  for (int i = 0; i < reports.size() - 1; i++) {

    if (!isCurrentSafe(reports[i], reports[i + 1], currentOrder)) {
      return false;
    }
  }
  return true;
}

bool checkLineSafety(vector<int> reports, bool &consumedTolerance) {

  if (checkLineSafetyAfterChange(reports)) {
    cout << "The initial list is correct" << endl;
    return true;
  }

  cout << "Found an anomaly, looking for other possible combinations ...."
       << endl;

  for (size_t i = 0; i < reports.size(); i++) {
    vector<int> temp = reports;
    temp.erase(temp.begin() + i);

    if (checkLineSafetyAfterChange(temp)) {
      return true;
    }
  }

  return false;
}

void checkReportsSafety() {
  string dataPath = "../data/day2.txt";
  string dataLine;

  int totalSafe = 0;

  int lineNumbers = 0;
  ifstream dataFile(dataPath);

  while (getline(dataFile, dataLine)) {

    lineNumbers++;
    cout << "===== Line " << lineNumbers << " =====" << endl;
    istringstream iss(dataLine);
    vector<int> reports;

    int current;
    while (iss >> current) {
      reports.push_back(current);
    }

    if (checkLineSafety(reports))
      totalSafe++;
  }
  cout << "Total of Safe reports is " << totalSafe << endl;
}
