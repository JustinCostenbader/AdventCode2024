// Justin Costenbader
// Advent of Code Day 1, Part 2
#include <iostream>

using namespace std;

#include <vector>

int main()
{
	// Initialize vectors for the two lists.
	vector<int> left;
	vector<int> right;
	
	// Input Variables
	int left_val, right_val;
  
	// Read the .txt until end of file
	while (cin >> left_val >> right_val)
	{
		left.push_back(left_val);
		right.push_back(right_val);
	}
	
	int total = 0;
	for (int numLeft : left)
	{
		// Count frequency
		int count = 0;
		for (int numRight : right)
		{
			if (numLeft == numRight)
			{
				count++;
			}
		}
		total += numLeft * count;
	}
	
	// Output the total
	cout << "Similarity Score: " << total << endl;
	
	return 0;
}
