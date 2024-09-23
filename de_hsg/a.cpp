#include <iostream>

using namespace std;

long Solve(long n)
{
	long tong = n / 5;
	long du = n % 5;
	
	if(du == 1 || du == 2 || du == 3){
		tong++;
	}
	if(du == 4){
		tong = tong + 2;
	}
	
	return tong;
}

int main()
{
	long n,result;
	
	cin >> n;
	
	result = Solve(n);
	
	cout << result;
	
}
