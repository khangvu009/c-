#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

void Reverse (string &S)
{
	reverse(S.begin(),S.end());	
}

bool KT_DX(long long n)
{
	string D = to_string(n);
	long long dao;
	
	Reverse(D);
	dao = stoi(D);
	if (dao == n){
		return true;
	}
	else{
		return false;
	}
}

bool Kt_snt (long long n)
{
	if (n == 1 ){
		return false;
	}
	if (n == 2 ){
		return true;
	}
	for (long long i = 2; i <= n/2+1; i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

void Solve (long long n, long long m, long long &count)
{
	bool kt_snt,kt_dx;
	
	for (long long i = n; i <= m; i++){
		kt_dx = KT_DX(i);
		if (kt_dx == true){
			kt_snt = Kt_snt(i);
			if(kt_snt == true){
				count++;
				cout << i << endl;
			}
		}
	}
	
	if (count == 0){
		cout << 0;
	}	
}

int main ()
{
	long long n,m;
	long long count = 0;
	
	cin >> n;
	cin >> m;
	Solve(n,m,count);
}
