// A Dynamic Programming based C++ program to
// find minimum number operations is less than
// or equal to k or not to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;

// Utility function to find minimum of three numbers
int min(int x, int y, int z)
{
	return min(min(x, y), z);
}

int editDistDP(string str1, string str2, int m, int n)
{
	// Create a table to store results of subproblems
	int dp[m + 1][n + 1];

	// Fill d[][] in bottom up manner
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			// If first string is empty, only option is to
			// insert all characters of second string
			if (i == 0)
				dp[i][j] = j; // Min. operations = j

			// If second string is empty, only option is to
			// remove all characters of second string
			else if (j == 0)
				dp[i][j] = i; // Min. operations = i

			// If last characters are same, ignore last char
			// and recur for remaining string
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			// If last character are different, consider all
			// possibilities and find minimum
			else
				dp[i][j] = 1 + min(dp[i][j - 1], // Insert
								dp[i - 1][j], // Remove
								dp[i - 1][j - 1]); // Replace
		}
	}

	return dp[m][n];
}

// Returns true if str1 and str2 are k edit distance apart,
// else false.
bool areKDistant(string str1, string str2, int k)
{
	int m = str1.length();
	int n = str2.length();

	if (abs(m - n) > k)
		return false;

	return (editDistDP(str1, str2, m, n) <= k);
}

// Driver program
int main()
{
	// your code goes here
	string str1 = "geek";
	string str2 = "gks";
	int k = 3;

	areKDistant(str1, str2, k) ? cout << "Yes" : cout << "No";

	return 0;
}

