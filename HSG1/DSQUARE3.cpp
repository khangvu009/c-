#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<bool> ISPRIME;
vector<long> Primes;

vector<bool> SanSnt(long n)
{
	vector<bool> IsPrime (n+1, true);
	
//	cout << " n = " << n << endl;
	for(long i = 2; i <= sqrt(n)+1; ++i){
		if (IsPrime[i]){
			for (long j = i * i; j <= n; j += i){	
				IsPrime[j] = false;		
			}
		}
	}
	
	for (long i = 2; i < IsPrime.size(); i++){
		if (IsPrime[i]) Primes.push_back(i);	
	}
	
//	cout << Primes[Primes.size()-1] << endl;
	return IsPrime;
}

long UCLN(long a, long b)
{
	if (a == 0) return b;
	return UCLN(b % a,a);
}

bool IsDsquare (long n)
{
	long k;
	
	for (long i = 0; i  < Primes.size(); i++){
		k = Primes[i];
//		k = k * k;
		if (n % (k * k) == 0) return true;
//		if (k*k > n) return false;
	}
	
	return false;
}

bool Check(long a, long b)
{
	long ucln = UCLN(a,b);
	
	if (ucln != 1) return true;	
	if (IsDsquare(a) == true) return true;
	if (IsDsquare(b) == true) return true;
	return false;
}

void Solve(long l , long r)
{
	long count = 0;
	
	if (l == 1)	l++;
	
	ISPRIME = SanSnt(sqrt(r)+1);
	
	
	for (long i = l; i < r; i++){
		for (long j = i+1; j <= r; j++){
			if (Check(i,j) == true) count++;
		}
	}
	
	cout << count;
	out << count;

}

int main()
{
	long l,r;
	
	inp.open("C:\\HSG1\\DSQUARE.INP");
	out.open("C:\\HSG1\\DSQUARE.OUT");
	
	inp >> l;
	inp >> r; 
	
	Solve(l,r);
	
	inp.close();
	out.close();
}
