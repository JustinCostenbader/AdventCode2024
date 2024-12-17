// Justin Costenbader
// Advent of Code Day 1
#include <iostream>

using namespace std;

#include <cmath>
#include <vector>
#include <algorithm>

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

  // Sort both lists
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  // Calculate Distance
  int distance = 0;
  for ( int i = 0; i < left.size(); i++)
  {
    distance += abs(left[i] - right[i]);
  }

  // Output the result
  cout << "Total Distance: " << distance << endl;

  return 0;
}
