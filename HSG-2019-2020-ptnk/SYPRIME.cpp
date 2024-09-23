#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

bool IsPrime(long n){
	for(long i = 2; i < sqrt(n)+1; i++) if (n % i == 0) return false;
	return true;
}

long MaxPrimeSmallerThanN(long n){
	long i = n-1;
	
	while(true){
		if(IsPrime(i)) return i;
		i--;
	}
}

long MaxPrimeBiggerThanN(long n){
	long i = n+1;
	
	while(true){
		if(IsPrime(i)) return i;
		i++;
	}
}

long Processing(long n){
	long a = MaxPrimeSmallerThanN(n); 
	long b = MaxPrimeBiggerThanN(n);
	long result = a+b;
	return result;
}

void Solve(){
	long temp;
	
	for(long i = 0; i < A.size(); i++){
		if (A[i] >= 5 && IsPrime(A[i])){
			temp = Processing(A[i]);
			if (temp/2 == A[i]) cout << "YES" << endl;
			else cout << "NO" << endl;	
		}
		else cout << "NO" << endl;
	}
}

int main(){
	long n,input;
	
	inp.open("C:\\bt_c++\\HSG-2019-2020-ptnk\\SYPRIME.INP");
	out.open("C:\\bt_c++\\HSG-2019-2020-ptnk\\SYPRIME.OUT");
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);
	}	
	
	Solve();
	
	inp.close();
	out.close();
}
