#include<iostream>
#include <math.h>
#include <unistd.h>
#include<ctime>
#include<algorithm>

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
	if (dao == 1){
		return false;
	}
	if (dao == n){
		if 	(	dao < 10 || 
				(	(dao % 2 != 0) &&
					 (dao % 3 != 0) && 
					 (dao % 5 != 0) && 
					 (dao % 7 != 0)
				)
			){
			return true;
		}
	}
	else{
		return false;
	}
}

void san_snt (long long n, long long *A, long &index)
{	
	long count = index;
	
	
	for (long long i = 2; i <= sqrt(n)+1; i++){
		long so_luong = count;
		for (long long j = 0; j <= index-1; j++){
			if (A[j] % i == 0 && i < A[j]){
				A[j] = 0;
				count--;		
			}
		}
		so_luong = so_luong - count;
		cout << "-- i = " << i  << "-- count = " << count << " -- so luong = " << so_luong << endl;  
		
	}
	
}

void Solve (long long n, long long m, long long *A)
{
	bool kt_snt,kt_dx;
	long index = 0;
	
// 1: tao san
	for (long long i = n; i <= m; i++){
		kt_dx = KT_DX(i);
		if (kt_dx == true){
			A[index] = i;
			index++;
		}
	}
	
//	for (int i = 0; i <= index-1; i++){
//		cout << A[i] << " ";
//	}
//	cout << endl;
	
//   2: san

	san_snt(m,A,index);
	
// 3: in ket qua
	for (long long i = 0; i <= index; i++){
		if (A[i] != 0){
			cout << A[i] << endl;
		}
	}
	
	
	if (index == 0){
		cout << 0;
	}	
}

int main ()
{
	int time_before_loop_begins = time(NULL);
	
	long long n,m,A[20000];
	long long index = 0;
	long long count = 0;
	
	cin >> n;
	cin >> m;
	Solve(n,m,A);
	int time_after_loop_ends = time(NULL);
	int time_diff = time_after_loop_ends - time_before_loop_begins;
//	cout << "Time taken to run a for loop = " << time_diff << " seconds.";
}
