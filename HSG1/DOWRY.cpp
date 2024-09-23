#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out; 

long Tongd(long start, long n,vector<vector<long>> A)
{
	long tong = 0;
	
	for (long i = start; i <= n; i++){
		for(long j = 0; j < A[i].size(); j++){
			tong += A[i][j];
		}	
	}
//	cout << " tong = " << tong;
	return tong;
}

long Tongc(long start, long n,vector<vector<long>> A)
{
	long tong = 0;
	
	for (long i = start; i <= n; i++){
		for(long j = 0; j < A.size(); j++){
 		    tong += A[j][i];
//			cout << " i = " << i << " j = " << j << endl; 
//			cout << A[j][i] << endl;
		}
	}
//	cout << tong;
	return tong;
}

bool Xuling (long start, long n, long &ng, long Asum,vector<vector<long>> A)
{
	vector<long> T;
	vector<vector<long>> B;
	
	long count = 0, tong = 0;
	
	for (long i = start; i <= n; i++){
		for (long j = 0; j < A[i].size(); j++){
			T.push_back(A[i][j]);
		}
		B.push_back(T);
		T.clear();
	}
	
	for (long i = 0; i < B.size(); i++){
		count++;
		tong = Tongd(0,i,B);
		if (tong == Asum/3){
			ng = count;
			return true;
		}
	}
	
	return false;
}

bool Xulid (long start, long n, long &d, long Asum,vector<vector<long>> A)
{
	vector<long> T;
	vector<vector<long>> B;
	
	long count = 0, tong = 0;
	
	for (long i = start; i <= n; i++){
		for (long j = 0; j < A[i].size(); j++){
//			cout << A[i][j] << " ";
			T.push_back(A[i][j]);
		}
//		cout << endl;
		B.push_back(T);
		T.clear();
	}
	
	for (long i = 0; i < B.size(); i++){
		count++;
		tong = Tongc(0,i,B);
		if (tong == Asum/3){
			d = count;
			return true;
		}
	}
	
	return false;
}

bool CatNgang(long Asum, long &ng, long &d,vector<vector<long>> A)
{
	bool result = false;
	long tong;
	
	for(long i = 0; i < A.size(); i++){
		tong = Tongd(0,i,A);
		if (tong+ (Asum / 3) == Asum ) result = Xulid(0,i,d,Asum,A);
		if (tong == Asum /3) result = Xulid(i+1, A.size()-1,d,Asum,A);
		if (result == true){
			ng = i+1;
			return true;
		}
	}
	
	return false;
}

bool CatDoc(long Asum, long &ng, long &d,vector<vector<long>> A)
{
	bool result = false;
	long tong;
	
	for(long i = 0; i < A.size(); i++){
		tong = Tongd(0,i,A);
		if (tong+ (Asum / 3) == Asum ) result = Xuling(0,i,d,Asum,A);
		if (tong == Asum /3) result = Xuling(i+1, A.size()-1,d,Asum,A);
		if (result == true){
			d = i+1;
			return true;
		}
	}
	
	return false;
}

void Print (int a, long ng, long d)
{
	if (a == 0) cout << "NO";
	else{
		cout << "YES" << endl;
		cout << "N " << ng << endl;
		cout << "D " << d << endl;
	}
}

void Solve(long sum, vector<vector<long>> A)
{
	long ng = 0, d = 0;
	
	if (sum % 3 != 0) Print(0,ng,d);	
	else if (CatNgang(sum,ng,d,A)) Print(1,ng,d);
	else if (CatDoc(sum,ng,d,A)) Print(1,ng,d);
	else Print(0,ng,d);
}

int main()
{
	vector<vector<long>> A;
	vector<long> T;
	long n,m,input;
	long sum = 0;
	
	inp.open("C:\\HSG1\\DOWRY.INP");
	out.open("C:\\HSG1\\DOWRY.OUT");	
	
	inp >> n;
	inp >> m;
	
	for (long i = 0; i  < n; i++){
		for (long j = 0;  j < m; j++){
			inp >> input;
			sum = sum + input;
			T.push_back(input);
		}
		A.push_back(T);
		T.clear();
	}
	
	Solve(sum,A);	
	
	inp.close();
	out.close();
}
