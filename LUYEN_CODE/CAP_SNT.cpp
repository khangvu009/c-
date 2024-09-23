#include <iostream>
#include <fstream>

using namespace std;

long Tim_ucln1 (long a, long b)
{
	if (b == 0){
		return a;
	}
	return Tim_ucln1(b, a % b);
}

long Tim_ucln (long a, long b)
{
	long min = a;
	if (min < b){
		min = b;
	}
	
	for (long i = 2; i <= min; i++){
		if (a % i == 0 && b % i == 0){
			return 0;
		}
	}
	
	return 1;
}

long Solve (long *A, long n)
{
	long result,count;
	
	count = 0;

	for (long i = 0; i < n-1; i++){
		for (long j = i+1; j < n; j++){
			result = Tim_ucln1(A[i],A[j]);
//			cout << "A["  << i << "] = " << A[i] << " A[" << j << "] = " << A[j] << "--ucln = " << result << endl;
			if (result == 1){
				count++;
//				cout << "--count = " << i << endl;
			}
//			cout << "--count = " << count << endl;
		}
	}
	
	return count;
}

int main()
{
//	ifstream cap_snt_inp;
//	cap_snt_inp.open("C:\\bt_c++\\LUYEN_CODE\\CAP_SNT.INP");
	long n,A[100000];
	long num_element = 0;
	long result;
	
//	cap_snt_inp >> n;
//	
//	while (num_element < n && cap_snt_inp >> A[num_element]){
//		num_element++;
//	}
	cin >> n;
	
	for (long i = 0; i < n; i++){
		cin >> A[i];
	}
	result = Solve(A,n);
	cout << result;
}
