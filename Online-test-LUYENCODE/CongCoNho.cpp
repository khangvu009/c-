#include<bits/stdc++.h>

using namespace std;

void ToVec(vector<int> &A, long long n) {
    if (n == 0) {
        A.push_back(0);
        return;
    }

    while (n > 0) {
        A.push_back(n % 10);
        n /= 10;
    }

    reverse(A.begin(), A.end());
}


long Plus(const vector<int> &A, const vector<int> &B) {
    int nho = 0, count = 0;
    int i = A.size() - 1, j = B.size() - 1;

    while (i >= 0 && j >= 0) {
        int temp = A[i] + B[j] + nho;
        if (temp > 1) {
            nho = 1;
            count++;
        } else {
            nho = 0;
        }
        i--;
        j--;
    }

    while (j >= 0) {
        if (B[j] + nho > 1) {
            nho = 1;
            count++;
        } else {
            nho = 0;
        }
        j--;
    }

    while (i >= 0) {
        if (A[i] + nho > 1) {
            nho = 1;
            count++;
        } else {
            nho = 0;
        }
        i--;
    }

    return count;
}


void Solve(long n,long m){
	vector<int> A,B;
	int count;
	
	ToVec(A,n);
	ToVec(B,m);
	
	count = Plus(A,B);
	
	cout << count << endl;
}

int main(){
	long n,m;
	
	cin >> n >> m;
	if(n == 1 && m == 0){
		cout << 0;
	} 
	else if (n == 0 && m == 1){
		cout << 0;
	}
	else{
		Solve(n,m);
	}
}
