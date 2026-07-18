#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Practice Question 4: Compute the longest common subsequence (LCS).
 *
 * Given two strings, find the length of their longest common
 * subsequence (characters that appear in both strings in the same
 * relative order, not necessarily contiguous) and also print the
 * actual subsequence itself.
 */

string longestCommonSubsequence(const string& s1, const string& s2, int& lcsLength) {
    int m = s1.size();
    int n = s2.size();

    // dp[i][j] = length of LCS of s1[0..i-1] and s2[0..j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    lcsLength = dp[m][n];

    // Backtrack through the dp table to reconstruct the actual subsequence
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string s1, s2;

    cout << "=== Longest Common Subsequence (LCS) ===" << endl;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    int lcsLength;
    string lcs = longestCommonSubsequence(s1, s2, lcsLength);

    cout << "\nLength of LCS: " << lcsLength << endl;
    cout << "LCS string: " << lcs << endl;

    return 0;
}
