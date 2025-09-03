#include <day4.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  cout << "======= Advent Of Code Day 4 ======" << endl;

  vector<vector<char>> data = parseData();

  int xmasCount = calculateXMAS(data);

  cout << "Total X-MAS : " << xmasCount << endl;

  return 0;
}
