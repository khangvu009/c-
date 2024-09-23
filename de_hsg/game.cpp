#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Convert_D_to_B(vector<int> &A, long n)
{
	while (n > 0){
		A.push_back(n%2);
		n = n / 2;
	}	
}

long long binary_to_decimal(vector<int>& A) 
{
    long long S = 0;

    for (int i = A.size() - 1, j = 0; i >= 0; i--, j++) {
        S += A[i] * pow(2, j);
    }

    return S;
}


void Sort (vector <int> &A)
{
	sort(A.begin(),A.end());
	reverse(A.begin(), A.end());
}

void Solve(long n)
{
	vector <int> A;
	long long result;
	
	Convert_D_to_B(A,n);
	Sort(A);
	result = binary_to_decimal(A);
	
	cout << result;
	
}

int main()
{
	long n;
	
	cin >> n;
	
	Solve(n);
}
