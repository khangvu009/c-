#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

long UCLN(long a, long b)
{
	if (a == 0) return b;
	return UCLN(b % a,a);
}

bool IsDsquare (long n)
{
	for (long i = 2; i  < sqrt(n)+1; i++){
		if (n % (i * i) == 0) return true;	
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
	
	if (l == 1){
		l++;
	}
	
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
