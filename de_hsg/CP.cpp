#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

bool kt_snt (long long n)
{
//	cout << n << endl;
	for(int i = 2; i <= (int)(sqrt(n))+1; i++){
		if(n % i == 0){
			return false;
		}
	}
	
	return true;
}

bool kt_so_chinh_phuong_dac_biet (long long n)
{
	if( (int)(sqrt(n)) * (int)(sqrt(n)) == n){
		return true;
	}
	else{
		return false;
	}
}

long Solve(long long a, long long b)
{
	bool check_snt,check_cpdb;
	long count = 0;
	
	for(int i = a; i <= b; i++){
		check_snt = kt_snt(i);
		
		if(check_snt == true){
			check_cpdb = kt_snt;
			if(check_cpdb == true){
				count++;
			}
		}
	}	
	
	return count;
}

int main()
{
	long long a,b;
	long count;
	
	ifstream cp_inp;
	ofstream cp_out;
	
	cp_inp.open("C:\\bt_c++\\de_hsg\\CP.INP");
	cp_out.open("C:\\bt_c++\\de_hsg\\CP.OUT");
	
	cp_inp >> a;
	cp_inp >> b;
	
	count = Solve(a,b);
	
	cout << count;
}
