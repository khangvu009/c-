#include <bits/stdc++.h>

using namespace std;

ifstream f_inp;
ofstream f_out;

int A[100][100];


void AddWells (long n)
{
	long c,d;
	
	for (int i = 0; i < n; i++){
		f_inp >> c;
		f_inp >> d;
		A[c-1][d-1] = 1;
		
		cout << c-1 << " " << d-1 << endl;
				
	}
	
	for (int i = 0; i < d; i++){
		for (int j = 0; j < c; j++){
//			cout << A[i][j] << " ";
		}
//		cout << endl;
	}
}


void Solve (long n)
{
	AddWells(n);
}

int main()
{
	long c,d,n;
	
	f_inp.open("C:\\bt_c++\\de_hsg\\FARM.INP");	
	f_out.open("C:\\bt_c++\\de_hsg\\FARM.OUT");	
	
	f_inp >> d;
	f_inp >> c;
	f_inp >> n;
	
	for (int i = 0; i < d; i++){
		for (int j = 0; j < c; j++){
			A[i][j] = 0;
		}
	}	
	
	Solve(n);
	
	f_inp.close();	
	f_out.close();	
}
