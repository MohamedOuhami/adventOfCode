#include "iostream"
#include <algorithm>
#include <cstdlib>
#include <day1/day1.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> firstList{};
vector<int> secondList{};
int totalDistance = 0;

void readData() {

  const string dataPath = "../data/day1part1.txt";
  string dataLine;
  // Read data from the data file
  std::ifstream dataFile(dataPath);

  // Read the file content line by line
  while (getline(dataFile, dataLine)) {

    // Use istringstream to get elements from each line
    istringstream iss(dataLine);

    string first, second;

    if (iss >> first >> second) {

      // Insert into the first vector
      firstList.push_back(stoi(first));
      // cout << "First element : " << first << endl;

      // Insert into the second list
      secondList.push_back(stoi(second));
      // cout << "Second element : " << second << endl;
    }
  }
}

// Method to sort the data in the lists
void sortData() {

  // Sort the vectors in an ascending manner
  sort(firstList.begin(), firstList.end());
  sort(secondList.begin(), secondList.end());

  // cout << "The lists sorted" << endl;

  // cout << "list 1 :" << endl;

  // for (int n : firstlist)
  //   cout << n << " ";
  //
  // cout << endl;
  // cout << "list 2 :" << endl;
  //
  // for (int n : secondlist)
  //   cout << n << " ";
}

int calculateDistance() {
  int listsSize = firstList.size();

  for (int i = 0; i < listsSize; i++) {
    totalDistance += abs(firstList[i] - secondList[i]);
  }

  return totalDistance;
}
