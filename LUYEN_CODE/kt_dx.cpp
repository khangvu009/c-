#include <iostream>

using namespace std;

int main()
{
	long n;
	long count = 0;
	long long tong = 0;
	
	cin >> n;
	
	for (int i = 1; i <= n; i++){
		tong = tong + i;
		cout << tong << endl;
	}
}
