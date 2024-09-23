#include <iostream>

using namespace std;

double GT (long n)
{
	double result = 1;
	
	for (int i = 1; i <= n; i++){
		result = result * i;
		cout << "---- giai thua = " << result << endl;
	}
	
	return result;
}

double Solve (long n)
{
	double S = 0;
	double Giai_thua;
	
	for (int i = 1; i <= n; i++){
		Giai_thua = GT(i);
		S = S + (i / Giai_thua);
		cout << "--i = " << i << " --Giai thua = " << Giai_thua << " --S = " << S << endl;
	}	
	
	return S;
}

int main()
{
	long n;
	
	cin >> n;
	
	cout << Solve(n);
}
