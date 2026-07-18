#include <iostream>
#include <vector>
using namespace std;

/*
 * Assignment 4: Write a program for 0/1 Knapsack problem.
 * (Also covers Practice Question 3: Solve 0/1 Knapsack Problem using DP.)
 *
 * Given item weights, values, and a knapsack capacity, find the maximum
 * value achievable without exceeding the capacity. Each item can either
 * be taken fully or not at all (hence "0/1").
 */

int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                // choose the better of: including item i-1, or excluding it
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]],
                                dp[i - 1][w]);
            } else {
                // item doesn't fit, so it can't be included
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    cout << "=== 0/1 Knapsack Problem (Dynamic Programming) ===" << endl;
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

    int maxValue = knapsack(capacity, weights, values, n);
    cout << "\nMaximum value that can be carried: " << maxValue << endl;

    return 0;
}
