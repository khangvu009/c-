#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

const long subtract = 1000000007;

long GCD (long a, long b){
	if(a == 0) return b;
	return GCD(b%a,a);
}

long long LCM(long a, long b) {
    long long gcd = GCD(a, b);
    return ((a % subtract) * ((b / gcd) % subtract)) % subtract;
}

void Solve(long n){
	if (n == 1){
		cout << 1;
	}
	else{
		long long lcm = 1;
		for(long i = 2; i <= n; i++){
			lcm = LCM(lcm,i);
		}
		cout << lcm;	
	}
	
}

int main(){
	long n,input;
	
	inp.open("C:\\bt_c++\\HSG-2017-2018-ptnk\\LCM.INP");
	out.open("C:\\bt_c++\\HSG-2017-2018-ptnk\\LCM.OUT");
	
	inp >> n;
	
	Solve(n);
	
	inp.close();
	out.close();
}
