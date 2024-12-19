// Justin Costenbader
// Advent of Code Day 2
#include <iostream>

using namespace std;

#include <cmath>
#include <vector>
#include <sstream>
#include <string>

// Function Prototype
bool isSafeReport(const vector<int>& levels); // Part 1
bool isSafeWithRemoval(const vector<int>& levels); // Part 2

int main()
{
	string line;
	int safeCount = 0;
	int safeRmCount = 0;
	
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
		
		// Part 1: Check if the report is safe
        if (isSafeReport(levels))
		{
			safeCount++;
        }
		
		// Part 2: Check if the report is safe with removal
		if (isSafeWithRemoval(levels))
		{
			safeRmCount++;
        }
		
	}
	
	// Output total safe
	cout << "Number of safe reports: " << safeCount << endl;
	cout << "Number of safe w/ removal reports: " << safeRmCount << endl;
	
	return 0;
}

// Function Definitions
// Part 1
bool isSafeReport(const vector<int>& levels)
{
	bool increasing = true;
	bool decreasing = true;
	
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

// Part 2
bool isSafeWithRemoval(const vector<int>& levels) 
{
    // Check if the report is safe without removal
    if (isSafeReport(levels)) 
	{
        return true;
    }

    // Check if removing each level one by one makes the report safe
    for (int i = 0; i < levels.size(); i++) 
	{
        vector<int> modifiedLevels = levels;
        modifiedLevels.erase(modifiedLevels.begin() + i);
        if (isSafeReport(modifiedLevels)) 
		{
            return true;
        }
    }

    return false;
}