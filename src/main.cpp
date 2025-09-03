#include <iostream>
#include <day3.h>

using namespace std;

int main (int argc, char *argv[]) {
  
  cout << "======= Advent Of Code Day 3 ======" << endl;

  string data = read_data();

  // calculateMuls(data);

  cout << "The total mul is : " << calculateMuls(data) << endl;

 
  return 0;
}
