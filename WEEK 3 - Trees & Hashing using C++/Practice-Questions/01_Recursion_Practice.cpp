#include <iostream>
using namespace std;

/*
 * Practice Question 1: Implement recursive factorial and Fibonacci functions.
 * Practice Question 5: Write a recursive function to sum elements in an array.
 */

// Recursive factorial: n! = n * (n-1)!
long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Recursive Fibonacci: fib(n) = fib(n-1) + fib(n-2)
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive sum of array elements
int recursiveSum(int arr[], int n) {
    if (n <= 0) {
        return 0;
    }
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int main() {
    // ---- Factorial ----
    int fnum;
    cout << "=== Recursive Factorial ===" << endl;
    cout << "Enter a number to find its factorial: ";
    cin >> fnum;
    cout << fnum << "! = " << factorial(fnum) << endl;

    // ---- Fibonacci ----
    int fibCount;
    cout << "\n=== Recursive Fibonacci ===" << endl;
    cout << "How many Fibonacci terms do you want to print? ";
    cin >> fibCount;
    cout << "Fibonacci series: ";
    for (int i = 0; i < fibCount; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    // ---- Recursive array sum ----
    int n;
    cout << "\n=== Recursive Sum of Array Elements ===" << endl;
    cout << "How many elements does the array have? ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Sum of array elements = " << recursiveSum(arr, n) << endl;

    return 0;
}
