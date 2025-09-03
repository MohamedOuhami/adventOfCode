#include <cstdio>
#include <day4.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> parseData() {

  string dataPath = "../data/day4.txt";

  vector<vector<char>> dataVector;

  // Read each line of the data
  ifstream data(dataPath);
  string dataLine;

  while (getline(data, dataLine)) {

    vector<char> lineChars;

    for (auto c : dataLine) {
      lineChars.push_back(c);
    }

    dataVector.push_back(lineChars);
  }

  cout << "Number of rows : " << dataVector.size() << endl;

  cout << "Number of columns : " << dataVector[0].size() << endl;

  return dataVector;
}

int calculateOccurence(vector<vector<char>> data) {

  cout << "===== Searching =====" << endl;

  int xmasCount = 0;

  for (size_t i = 0; i < data.size(); i++) {

    for (size_t j = 0; j < data[i].size(); j++) {

      // horizontally
      if (data[i][j] == 'X' && j < data[i].size() - 3) {

        string word;

        word += data[i][j];
        word += data[i][j + 1];
        word += data[i][j + 2];
        word += data[i][j + 3];

        if (word == "XMAS") {
          xmasCount++;

          // cout << "Found an xmas at line " << i << endl;
        }
      }

      // horizontally Reverse
      if (data[i][j] == 'X' && j >= 3) {

        string word;

        word += data[i][j];
        word += data[i][j - 1];
        word += data[i][j - 2];
        word += data[i][j - 3];

        if (word == "XMAS") {
          xmasCount++;

          // cout << "Found an xmas at line " << i << endl;
        }
      }

      // Vertically

      if (data[i][j] == 'X' && i < data.size() - 3) {

        string word;

        word += data[i][j];
        word += data[i + 1][j];
        word += data[i + 2][j];
        word += data[i + 3][j];

        if (word == "XMAS") {
          xmasCount++;

          // cout << "Found an xmas at line " << i << endl;
        }
      }

      // Vertically reverse

      if (data[i][j] == 'X' && i >= 3) {

        string word;

        word += data[i][j];
        word += data[i - 1][j];
        word += data[i - 2][j];
        word += data[i - 3][j];

        if (word == "XMAS") {
          xmasCount++;

          // cout << "Found an xmas at line " << i << endl;
        }
      }

      // Direction bottom right
      if (data[i][j] == 'X' && i + 3 < data.size() && j + 3 < data[i].size()) {

        string word;

        word += data[i][j];
        word += data[i + 1][j + 1];
        word += data[i + 2][j + 2];
        word += data[i + 3][j + 3];

        if (word == "XMAS") {
          xmasCount++;

          // cout << "Found an xmas at line " << i << endl;
        }
      }

      // Direction top right
      if (data[i][j] == 'X' && i >= 3 && j + 3 < data[i].size()) {

        string word;

        word += data[i][j];
        word += data[i - 1][j + 1];
        word += data[i - 2][j + 2];
        word += data[i - 3][j + 3];

        if (word == "XMAS") {
          xmasCount++;

          // cout << "Found an xmas at line " << i << endl;
        }
      }

      // Direction Bottom Left
      if (data[i][j] == 'X' && i + 3 < data.size() && j >= 3) {

        string word;

        word += data[i][j];
        word += data[i + 1][j - 1];
        word += data[i + 2][j - 2];
        word += data[i + 3][j - 3];

        if (word == "XMAS") {
          xmasCount++;

          // cout << "Found an xmas at line " << i << endl;
        }
      }

      // Direction top left
      if (data[i][j] == 'X' && i >= 3 && j >= 3) {

        string word;

        word += data[i][j];
        word += data[i - 1][j - 1];
        word += data[i - 2][j - 2];
        word += data[i - 3][j - 3];

        if (word == "XMAS") {
          xmasCount++;

          // cout << "Found an xmas at line " << i << endl;
        }
      }
    }
  }

  return xmasCount;
}

int calculateXMAS(vector<vector<char>> data) {

  int xmasCount = 0;
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data[i].size(); j++) {

      if (data[i][j] == 'A' && i >= 1 && j >= 1 && i < data.size() - 1 &&
          j < data[i].size() - 1) {

        // Top S and Bottom M
        bool topS_bottomM =
            data[i - 1][j + 1] == 'S' && data[i - 1][j - 1] == 'S' &&
            data[i + 1][j + 1] == 'M' && data[i + 1][j - 1] == 'M';

        // Top M and Bottom S
        bool topM_bottomS =
            data[i - 1][j + 1] == 'M' && data[i - 1][j - 1] == 'M' &&
            data[i + 1][j + 1] == 'S' && data[i + 1][j - 1] == 'S';

        // Right M and Left S
        bool rightM_leftS =
            data[i - 1][j + 1] == 'M' && data[i - 1][j - 1] == 'S' &&
            data[i + 1][j + 1] == 'M' && data[i + 1][j - 1] == 'S';

        // Right S and Left M
        bool leftM_rightS =
            data[i - 1][j + 1] == 'S' && data[i - 1][j - 1] == 'M' &&
            data[i + 1][j + 1] == 'S' && data[i + 1][j - 1] == 'M';

        if (topS_bottomM || topM_bottomS || rightM_leftS || leftM_rightS) {

          cout << "Found an XMAS at " << i << "-" << j << endl;
          xmasCount++;
        }
      }
    }
  }

  return xmasCount;
}
