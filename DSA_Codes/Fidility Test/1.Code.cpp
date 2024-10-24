#include <iostream>
#include <vector>

using namespace std;

int sumEvenOdd(int** a, int n, int x) {
    int sum = 0;

    // Find the row and column indices of x
    int row = -1, col = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }

    // If x is not found, return -1
    if (row == -1 || col == -1) {
        return -1;
    }

    // Calculate the sum of even or odd numbers based on row and column indices
    int row_col_sum = row + col;
    if (row_col_sum % 2 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] % 2 == 0) {
                    sum += a[i][j];
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] % 2 != 0) {
                    sum += a[i][j];
                }
            }
        }
    }

    return sum;
}

int main() {
    int n = 3;  // Fixed matrix size

    // int** a = new int*[n];
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;  // Initialize elements to zero
        }
    }

    // Assign values to the matrix
    a[0][0] = 11;
    a[0][1] = 22;
    a[0][2] = 33;
    a[1][0] = 44;
    a[1][1] = 55;
    a[1][2] = 66;
    a[2][0] = 77;
    a[2][1] = 88;
    a[2][2] = 99;

    int x = 55;  // Fixed target element

    int result = sumEvenOdd(a, n, x);
    if (result == -1) {
        cout << "Element not found in the matrix" << endl;
    } else {
        cout << result << endl;
    }

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}