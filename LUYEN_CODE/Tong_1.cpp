#include <iostream>

using namespace std;

Solve (long n)
{
	long S = 0;
	
	for (int i = 1; i <= n; i++){
		S = S + (i*i);
	}	
	
	return S;
}

int main()
{
	long n;
	
	cin >> n;
	
	cout << Solve(n);
}
