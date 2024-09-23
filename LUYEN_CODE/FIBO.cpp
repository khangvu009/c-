#include <iostream>

using namespace std;

long Max_fibo (long long n)
{
	long long f = 0;
	long long f1 = 1;
	long long f2 = 0;
	long long max = 0;
	
	while (f2 < n){
		if (n == 2){
			return 2;
		}
		f2 = f + f1;
		f = f1;
		f1 = f2;
	}
	
	return f;
}

long Solve (long long  n, long long *A)
{
	long long hieu = n;
	long long f;
	long long count = 0;
	
	while (hieu > 0){
		f = Max_fibo(hieu);
		A[count] = f;
		hieu = hieu - f;
		count++;
	}
	
	return count;
}

int main(){
	long long n,A[100000],result;

	cin >> n;
	
	
	result = Solve(n,A);
	
	cout << result << endl;
	
	for (int i = 0; i < result; i++){
		if (i <= result -1 ){
			cout << A[i] << " ";
		}
		else{
			cout << A[i];
		}	 
	}
	
	
}
