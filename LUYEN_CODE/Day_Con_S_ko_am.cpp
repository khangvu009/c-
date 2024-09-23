#include <iostream>
#include <fstream>

using namespace std;

long Count_sl_va_Tinh_Tong (long a, long b, long *A,long &count)
{
	long S = 0;
	count = 0;
	
//	count so luong phan tu va tinh tong
	for (int i = a; i <= b; i++){
		S = S + A[i];
		count++;
	}	
	
	return S;
}

long kt_tong (long S)
{
	if (S >= 0){
		return 1;
	}
	else{
		return 0;
	}

}

long Solve (long &n, long *A)
{
	long kt_S,S;
	long result = -1;
	
//	duyet qua tung phan tu
	for(long i = 0; i < n-1 ; i++){
		for (long j = i+1; j < n; j++){
			long count = 0;
			S = Count_sl_va_Tinh_Tong(i,j,A,count);
			kt_S = kt_tong(S);
			if (kt_S == 1 && result < count){
				result = count;
			}
			
		}
	}	
	
	for (int i =0; i < n; i++){
		if (A[i] >= 0 && result == -1){
			result = 1;
		}
	}
	
	return result;
}

int main()
{
	long n,A[100000],result;
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	result = Solve(n,A);
	
	cout << result;

}
