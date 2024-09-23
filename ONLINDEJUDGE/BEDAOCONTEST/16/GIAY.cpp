#include<bits/stdc++.h>

using namespace std;

long A[1000000],B[1000000];

double f(double x,long n) {
	double res = 0;
  
	for(long long i = 0; i < n; i++) {
    	for(long long j = 0; j < n; j++) {
     		if(i != j) {
 	    		long long da = A[i] - A[j];
    	    	long long db = B[i] - B[j];
    			res = max(res, da * cos(x) + db * sin(x));
      		}
    	}
  	}
  return res;
}


void Solve(long n){
	double min1;
	double result = f(M_PI,n);
	
	min1 = min(min1,(double)0);
	
	cout << min1;
}

int main(){
	long n,input;
	
	cin >> n;
	
	for(long i = 0; i < n; i++){
		cin >> input;
		A[i] = input;
	}
	for(long i = 0; i < n; i++){
		cin >> input;
		B[i] = input;
	}
	
	Solve(n);
}
