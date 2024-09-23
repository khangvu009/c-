#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

long long GCD(long long a, long long b){
	if(a == 0) return b;
	return GCD(b % a, a);
}

void Solve(long long a,long long b){
	long long gcd = GCD(a,b);
	
	
	if(gcd == 1) out << "YES";
	if(gcd > 1) out << "NO";
}

int main(){
	long long a,b;
	
	inp.open("COPRIME.inp");
	out.open("COPRIME.out");
	
	inp >> a >> b;
	
	Solve(a,b);
	
	inp.close();
	out.close();
}
