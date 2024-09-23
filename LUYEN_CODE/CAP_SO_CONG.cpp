#include <iostream>

using namespace std;


void Sort (long *A)
{
	long temp = 0;
	
	for (int i = 0; i <= 2; i++){
		for (int j = i+1; j <= 2; j++){
			if (A[i] > A[j]){
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}	
	
}

long Solve (long *A)
{
	long k2 = 0;
	long k = 0;
	long result = 0;
	
	Sort(A);
	
	if (A[1] - A[0] > A[2] - A[1]){
		k2 = A[1] - A[0];
		k = A[2] - A[1];
		result = k2 - k + A[0];  
	}	
	if (A[1] - A[0] == A[2] - A[1]){
		result = A[2] + (A[1] - A[0]);
	}
	if (A[1] - A[0] < A[2] - A[1]){
		k = A[1] - A[0]; 
		k2 = A[2] - A[1];
		result = k2 - k + A[1];
	}
	return result;
}

int main()
{
	long A[3],result;
	
	cin >> A[0];
	cin >> A[1];
	cin >> A[2];
	
	result = Solve(A);

	cout << result;
}
