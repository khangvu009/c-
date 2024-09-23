#include<iostream>
#include <math.h>
#include <unistd.h>
#include<ctime>

using namespace std;

bool KT_DX(long long n)
{
	long long phan_du,phan_nguyen;
	long long tem = n;
	long long dao = 0;
	
	while (tem > 0){
		phan_du = tem % 10;
		phan_nguyen = tem / 10;
		dao = dao * 10 + phan_du;
		tem = phan_nguyen;	
	}
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
	for (long long i = 2; i <= sqrt(n)+1; i++){
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
	int time_before_loop_begins = time(NULL);
	
	long long n,m;
	long long count = 0;
	
	cin >> n;
	cin >> m;
	Solve(n,m,count);
	int time_after_loop_ends = time(NULL);
	int time_diff = time_after_loop_ends - time_before_loop_begins;
//	cout << "Time taken to run a for loop = " << time_diff << " seconds.";
}
