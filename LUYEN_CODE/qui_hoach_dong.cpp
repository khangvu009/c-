#include <iostream>

using namespace std;
	
void Amount_way (long long n, long long S, long long *Dp, long long *W, long long j)
{
	for (long long i = 0; i < n; i++){		
		if (j- W[i] >= 0){
			Dp[j] = Dp[j] + (Dp[j- W[i]]);
		}
	}		
}
	
void Solve (long long n, long long S,long long *W, long long *Dp)
{
	long long result,j;			
	for (j = 1; j <= S; j++){
		Amount_way(n,S,Dp,W,j);
	}
		
	cout << Dp[S];
}
	
int main()
{
	long long n,S,result;
	
//	cin >> n;
//			
//	long long W[n];
//	
//	cin >> S;
//		
//	long long Dp[S];
//		
//	Dp[0] = 1;
//		
//	for (long long i = 0; i < n; i++){
//		cin >> W[i];
//	}

//	cin >> n;
	n = 4;
				
	long long W[n];
	
//	cin >> S;
	S = 50;
	
	long long Dp[S];
		
	Dp[0] = 1;
		
//	for (long i = 0; i < n; i++){
//		cin >> W[i];-
//	}
	W[0] = 7;
	W[1] = 31;
	W[2] = 21;
	W[3] = 43;
		
	for (long long k = 1; k <= S; k++){
		Dp[k] = 0;
	}
			
	Solve(n,S,W,Dp);	
}

