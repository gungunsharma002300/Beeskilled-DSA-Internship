#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
 * Practice Question 3: Solve 0/1 Knapsack Problem using DP.
 *
 * Assignments/04_Knapsack_01.cpp solves this using bottom-up TABULATION.
 * This version solves the same problem using top-down RECURSION +
 * MEMOIZATION, showing the alternate DP approach.
 */

vector<vector<int>> memo;

int knapsackMemo(vector<int>& weights, vector<int>& values, int n, int capacity) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    if (memo[n][capacity] != -1) {
        return memo[n][capacity]; // reuse previously computed result
    }

    int result;
    if (weights[n - 1] > capacity) {
        // item doesn't fit, skip it
        result = knapsackMemo(weights, values, n - 1, capacity);
    } else {
        // choose the better of including or excluding item n-1
        int include = values[n - 1] + knapsackMemo(weights, values, n - 1, capacity - weights[n - 1]);
        int exclude = knapsackMemo(weights, values, n - 1, capacity);
        result = max(include, exclude);
    }

    memo[n][capacity] = result;
    return result;
}

int main() {
    int n, capacity;

    cout << "=== 0/1 Knapsack Problem (Recursion + Memoization) ===" << endl;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Enter weight and value for each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - weight: ";
        cin >> weights[i];
        cout << "Item " << i + 1 << " - value: ";
        cin >> values[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Initialize memo table with -1 (meaning "not computed yet")
    memo.assign(n + 1, vector<int>(capacity + 1, -1));

    int maxValue = knapsackMemo(weights, values, n, capacity);
    cout << "\nMaximum value that can be carried: " << maxValue << endl;

    return 0;
}
