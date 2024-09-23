#include <bits/stdc++.h>

using namespace std;

ifstream count_inp;
ofstream count_out;

void Add (vector<long> &B, long n)
{
	bool result = true;
	
	for (long i = 0; i < B.size(); i++){
		if (B[i] == n){
			result = false;
			break;
		}	
	}
	
	if (result == true){
		B.push_back(n);
	}
}

long Count (long n, vector<long> A)
{
	long count = 0;
	
	for (long i = 0; i < A.size(); i++){
		if (A[i] == n){
			count++;
		}
	}
	
	return count;
}

void Solve(vector<long> A)
{
	vector<long> B;
	long max = 0;
	long count;
	
	B.push_back(A[0]);
	
	for (long i = 1; i < A.size(); i++){
		Add(B,A[i]);
	}
	
	for (long i = 0; i < B.size(); i++){
		count = Count(B[i],A);
		
		if (max <= count){
			max = count;
		}
	}
	
	count_out << B.size() << endl;
	count_out << max;
}

int main()
{
	long n,inp;
	vector<long> A;
	
	count_inp.open("C:\\bt_c++\\de_hsg\\COUNT.INP");
	count_out.open("C:\\bt_c++\\de_hsg\\COUNT.OUT");
	
	count_inp >> n;
	
	for (long i = 0; i < n; i++){
		count_inp >> inp;
		A.push_back(inp);
	}
	
	Solve(A);
	
	count_inp.close();
	count_out.close();
}
