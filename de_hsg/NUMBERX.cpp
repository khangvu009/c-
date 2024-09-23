#include <bits/stdc++.h>

using namespace std;

ifstream x_inp; 
ofstream x_out;

long UCLN (long a, long b)
{
	
	if (a == 0){
		return b;
	}
	else{
		return UCLN(b % a, a);
	}
}

long long BCNN (long a, long b, long ucln)
{
	long long bcnn = a * b / ucln;
	
	return bcnn;
}

long long Solve( long a, long b)
{
	long ucln;
	long long bcnn;
	
	if 	(a % b == 0){
		return a - b;
	}
	else if (b % a == 0){
		return b - a;
	}
	else{
		ucln = UCLN(a,b);
		bcnn = BCNN(a,b,ucln);
		
		return bcnn - a - b;
	}
}

int main()
{
	long a,b;
	long long result;
	
	x_inp.open("C:\\bt_c++\\de_hsg\\NUMBERX.INP");
	x_out.open("C:\\bt_c++\\de_hsg\\NUMBERX.OUT");
	
	x_inp >> a;
	x_inp >> b;
	
	result = Solve(a,b);
	
	x_out << result;
	
}
