#include <iostream>
#include <vector>

using namespace std;

void Solve(string str1, string str2) {
    long m = str1.length();
    long n = str2.length();

    vector<vector<long>> A(m + 1, vector<long>(n + 1, 0));

    for (long i = 1; i <= m; i++) {
        for (long j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                A[i][j] = A[i - 1][j - 1] + 1;
            } else {
                A[i][j] = max(A[i][j - 1], A[i - 1][j]);
            }
        }
    }

    // Find the LCS sequence
    string lcs;
    long i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        } else if (A[i - 1][j] > A[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Display the matrix A
    cout << "Matrix A:" << endl;
    for (long i = 0; i <= m; i++) {
        for (long j = 0; j <= n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Display the length of LCS
    cout << "Length of LCS: " << A[m][n] << endl;

    // Display the LCS sequence
    cout << "LCS Sequence: " << lcs << endl;
}

int main() {
    string str1 = "ABCBDAB";
    string str2 = "BDCAB";

    Solve(str1, str2);
    return 0;
}

