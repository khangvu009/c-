#include <iostream>

using namespace std;

double Solve (long n)
{
	double S = 0;
	double tam = 1;
	
	for (int i = 1; i <= n; i++){
		S = S + (tam / i);
	}	
	
	return S;
}

int main()
{
	long n;
	
	cin >> n;
	
	cout << Solve(n);
}
