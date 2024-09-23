#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

bool kt_snt (long n)
{
	if (n == 1){
		return false;
	}
	
	for(int i = 2; i < n; i++){
		if(n % i == 0){
			return false;
		}
	}	
	
	return true;
}

void Xu_li(vector<int> &A, int n)
{
	long long result = pow(n,4);
	string str = to_string(result);
	cout << str;
	for(int i = 0; i < str.length(); i++){
		A.push_back(str[i] - '0');
	}
}

void Solve(long k)
{
	vector <int> A;
		
	long i = 1;
	bool result;
	
	while (A.size() <= k){
		result = kt_snt(i);
		if(result == true){
			Xu_li(A,i);	
		}
		
		i++;
	}
	
	cout << endl;
	cout << A[k-1];
}

int main()
{
	long k;
	
	cin >> k;
	
	Solve(k);
}
