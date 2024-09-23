#include<bits/stdc++.h>
using namespace std;

ifstream inp;
ofstream out;

struct Point {
    long start;
    long end;
    long value;
};

vector<Point> A;

void Solve(long n, Point p) {
    long result = LONG_MAX;
    vector<long> Dp(n, 0);


    for (long i = 0; i < A.size(); i++) {
        Dp[i] = A[i].value;
        if (A[i].start >= p.start && A[i].end <= p.end) {
            for (long j = 0; j < i; j++) {
                if (A[i].start > A[j].end) {
                    Dp[i] = min(Dp[i], Dp[j] + A[i].value);
                }
            }
            result = min(result, Dp[i]);
        }
    }

    out << result;
}

int main() {
    long n, m;
    Point temp, p;

    inp.open("VANCHUYEN.INP");
    out.open("VANCHUYEN.OUT");

    inp >> m >> n >> p.start >> p.end;

    if (p.start > p.end) swap(p.start, p.end);

    for (long i = 0; i < n; i++) {
        inp >> temp.start >> temp.end >> temp.value;
        if (temp.start > temp.end) {
            swap(temp.start, temp.end);
        }
        A.push_back(temp);
    }

    Solve(n, p);

    inp.close();
    out.close();
}

