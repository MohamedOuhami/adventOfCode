#include <vector>
using namespace std;

// Function to check if a list of reports is safe
bool isCurrentSafe(int current, int next);

// Function to read the data and check if safe 
void checkReportsSafety();

bool checkLineSafety(vector<int> reports);
bool checkLineSafetyAfterChange(vector<int>& reports);

// The different order status that it can get
enum OrderStatus { NOT_DEFINED, ASC, DESC };

