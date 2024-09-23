#include <iostream>

using namespace std;

double Solve (long n)
{
	double S = 0;
	double sbc = 1;
	double sc = 1;
	
	for (int i = 1; i <= n; i++){
		S = S + sbc / sc;
		sc = sc + 2; 
	}
	
	return S;
}

int main()
{
	long n;
	
	cin >> n;
	
	cout << Solve(n);
}
