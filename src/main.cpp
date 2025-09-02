#include <iostream>
#include <day1/day1.h>

using namespace std;

int main (int argc, char *argv[]) {
  
  cout << "======= Advent Of Code Day 1 ======" << endl;

  // Read the data from the file
  readData();

  // Sort the vectors
  sortData();

  // Calculate the total distance
  cout << "The total distance : " << calculateDistance();

  
  return 0;
}
