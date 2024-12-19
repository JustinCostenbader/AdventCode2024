// Justin Costenbader
// Advent of Code Day 2
#include <iostream>

using namespace std;

#include <cmath>
#include <vector>
#include <sstream>
#include <string>

// Function Prototype
bool isSafeReport(const vector<int>& levels);

int main()
{
	string line;
	int safeCount = 0;
	
	// Read input line by line
    while (getline(cin, line)) 
	{
        stringstream ss(line);
        vector<int> levels;
        int level;
		
		// Parse levels from the line
    while (ss >> level) 
		{
        levels.push_back(level);
    }
		
		// Check if the report is safe
    if (isSafeReport(levels))
		{
        safeCount++;
    }
		
	}
	
	// Output total safe
	cout << "Number of safe reports: " << safeCount << endl;
	
	return 0;
}

// Function Definition
bool isSafeReport(const vector<int>& levels)
{
	bool increasing = true;
	bool decreasing = true;

  // Start at the second element and compare to the first
	for (int i = 1; i < levels.size(); i++)
	{
		int diff = abs(levels[i] - levels[i - 1]);
		if (diff < 1 || diff > 3) 
		{
        return false;
    }
		
		if (levels[i] < levels[i - 1]) 
		{
        increasing = false;
    }
		
		if (levels[i] > levels[i - 1]) 
		{
      decreasing = false;
    }

	}
	
	return increasing || decreasing;
}
