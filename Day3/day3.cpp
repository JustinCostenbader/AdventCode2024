// Justin Costenbader
// Advent of Code Day 3
#include <iostream>

using namespace std;

#include <string>
#include <regex> // YAY Regular Expressions

int main()
{
	// The R before the string allows you to use backslashes and special characters without escaping them.
	// (Raw String Literal)
	regex multiply(R"(mul\((\d+),(\d+)\))");
	smatch match;
	
	string line;
    int totalSum = 0;

    // Read input line by line
    while (getline(cin, line)) 
    {
		// const interators
        auto start = line.cbegin();
        auto end = line.cend();

        // Search for all regular expression matches in the current line
        while (regex_search(start, end, match, multiply)) 
        {
            // Extract the numbers from the match
            int x = stoi(match[1].str());
            int y = stoi(match[2].str());

            // Add the result of the multiplication to the total sum
            totalSum += x * y;

            // Move past the match after it is found to avoid an infinite loop
            start = match.suffix().first;
        }
    }

    // Output the total sum
    cout << "Total sum: " << totalSum << endl;

    return 0;
}