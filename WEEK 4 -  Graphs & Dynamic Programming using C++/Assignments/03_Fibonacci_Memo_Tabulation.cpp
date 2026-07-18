#include <iostream>
#include <vector>
using namespace std;

/*
 * Assignment 3: Solve Fibonacci using Memoization + Tabulation.
 *
 * Two Dynamic Programming approaches are shown:
 *  1. Memoization (Top-Down)  - recursion + cache
 *  2. Tabulation  (Bottom-Up) - iterative table filling
 */

// ---------- Memoization (Top-Down) ----------
long long fibMemoHelper(int n, vector<long long>& memo) {
    if (n <= 1) return n;

    if (memo[n] != -1) {
        return memo[n]; // already computed, reuse it
    }

    memo[n] = fibMemoHelper(n - 1, memo) + fibMemoHelper(n - 2, memo);
    return memo[n];
}

long long fibMemoization(int n) {
    vector<long long> memo(n + 1, -1);
    return fibMemoHelper(n, memo);
}

// ---------- Tabulation (Bottom-Up) ----------
long long fibTabulation(int n) {
    if (n <= 1) return n;

    vector<long long> table(n + 1);
    table[0] = 0;
    table[1] = 1;

    for (int i = 2; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }

    return table[n];
}

int main() {
    int n;

    cout << "=== Fibonacci using Memoization & Tabulation ===" << endl;
    cout << "Enter the value of n (find nth Fibonacci number): ";
    cin >> n;

    cout << "\nFibonacci(" << n << ") using Memoization (Top-Down): " << fibMemoization(n) << endl;
    cout << "Fibonacci(" << n << ") using Tabulation (Bottom-Up): " << fibTabulation(n) << endl;

    // Bonus: print the whole series using tabulation
    cout << "\nFibonacci series up to n=" << n << ": ";
    for (int i = 0; i <= n; i++) {
        cout << fibTabulation(i) << " ";
    }
    cout << endl;

    return 0;
}
