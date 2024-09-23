#include <iostream>
#include<math.h>

using namespace std;

void San (int *SieveA, long n)
{
	for (long i = 2; i <= sqrt(n)+1; i++){
		for(long j = i * i; j <= n; j = j + i){
			SieveA[j] = 0;
		}
	}
}

int main()
{
	long n;
	
	cin >> n;
	
	int SieveA[n];
	
	for (long i = 0; i <= n; i++){
		SieveA[i] = 1;
	}
	
	San(SieveA,n);
	
	for (int i = 1; i <= n; i++){
		if (SieveA[i] == 1){
//			cout << i << endl;
		}
	}
}
