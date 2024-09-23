#include<bits/stdc++.h>

using namespace std;

vector<long> addVectors(const vector<long>& A, const vector<long>& B) {
    long carry = 0;
    vector<long> result;
    long size1 = A.size();
    long size2 = B.size();
    long i = size1 - 1;
    long j = size2 - 1;

    while (i >= 0 || j >= 0 || carry) {
        long num1 = (i >= 0) ? A[i--] : 0;
        long num2 = (j >= 0) ? B[j--] : 0;
        long sum = num1 + num2 + carry;
        result.push_back(sum % 10);
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

void Solve() {
    string str, str1;
    cin >> str >> str1;

    vector<long> A, B;
    for (long i = 0; i < str.size(); ++i) {
        A.push_back(str[i] - '0');
    }
    for (long i = 0; i < str1.size(); ++i) {
        B.push_back(str1[i] - '0');
    }

    vector<long> C = addVectors(A, B);

    for (long i = 0; i < C.size(); ++i) {
        cout << C[i];
    }
    cout << endl;
}

int main() {
    Solve();
}

