#include <algorithm>
#include <cstdlib>
#include <day1/day1.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

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

      // Insert into the second list
      secondList.push_back(stoi(second));
    }
  }
}

// Method to sort the data in the lists
void sortData() {

  // Sort the vectors in an ascending manner
  sort(firstList.begin(), firstList.end());
  sort(secondList.begin(), secondList.end());
  
}

int calculateDistance() {
  int listsSize = firstList.size();

  for (int i = 0; i < listsSize; i++) {
    totalDistance += abs(firstList[i] - secondList[i]);
  }

  return totalDistance;
}

int calculateSimilarity(){

  int totalSimilarity = 0;
  map<int,int> similarities; 

  // Loop through the left list
  for (int num : firstList){

    // If the num already exists and its sim was calculated
    if (similarities.find(num) != similarities.end()){
      totalSimilarity += similarities[num];
    }
    else {
      int elementSim = count(secondList.begin(),secondList.end(),num);
      similarities[num] = elementSim * num;
      totalSimilarity += elementSim * num;

    }

    

  }

  return totalSimilarity;
}

