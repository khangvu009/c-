#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

long A[9];

long Max(long a, long b, long c){
	long max1 = max(a,b);
	long Fmax = max(max1,c);
	
	return Fmax;
}

long Sum(){
	long tong = 0;
	
	for (long i = 1; i <= 9; i++){
		tong = tong + A[i];
	}
	
	return tong;
}

void Solve(){
	long max1 = Max(A[1],A[4],A[7]);
	long max2 = Max(A[2],A[5],A[8]);
	long max3 = Max(A[3],A[6],A[9]);
	long tong,result;
	
	tong = Sum();
	
	result = tong - max1 - max2 - max3;
	cout << "max1 = " << max1 << " max2 = " << max2 << " max3 = " << max3 << " tong = " << tong << endl;
	cout << result;
}

int main(){
	inp.open("C:\\bt_c++\\HSG-2022-2023\\PHANLOAI.INP");	
	out.open("C:\\bt_c++\\HSG-2022-2023\\PHANLOAI.OUT");
	
	for (long i = 1; i <= 9; i++){
		inp >> A[i];
	}
	
	for (long i = 1; i <= 9; i++){
		cout << " A[" << i << "] = " << A[i] << " ";
		if (i % 3 == 0) cout << endl;
	}
	
	Solve();
	
	inp.close();
	out.close();	
}
