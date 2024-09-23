#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out; 

long n,m;

void PrintV(vector<vector<long>> A)
{
	for (long i = 0; i < A.size(); i++){
		for (long j = 0; j < A[i].size(); j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

long Tong (long top, long left, long bottom, long right, vector<vector<long>> A)
{
	long tong = 0;
	
	for (long i = top; i <= bottom; i++){
		for (long j = left; j <= right; j++){
//			cout << " A = " << A[i][j] << endl;
//			cout << " i = " << i << " j = " << j << endl;
			tong += A[i][j];
		}
	}
	
	return tong;
}

vector<vector<long>> CreateV (long top, long left, long bottom, long right, vector<vector<long>> A)
{
	vector<vector<long>> B;
	vector<long> T;
	
	for(long i = top; i <= bottom; i++){
		for(long j = left; j <= right; j++){
			T.push_back(A[i][j]);
		}
		B.push_back(T);
		T.clear();
	}
	
	return B;
}

vector<vector<long>>  CatDong (long Asum,vector<vector<long>> A,long &dong, bool OnlyOneThird)
{
	long tong = 0;
	vector<vector<long>> B;
	dong = -1;
	
	for(long i = 0; i < A.size(); i++){
		tong = Tong(0,0,i,A[0].size()-1,A);
//		cout << " tong = " << tong << " dong = " << i << endl;
		if (tong == Asum / 3){
			cout << " tong = " << tong << " dong = " << i << endl;
			B = CreateV(i+1,0,A.size()-1,A[0].size()-1,A);
			dong = i+1;
			return B;
		}
		else if (tong == 2*Asum/3 && !OnlyOneThird){
			cout << " tong = " << tong << " dong = " << i << endl;
			B = CreateV(0,0,i,A[0].size()-1,A);
			dong = i+1;
			return B;
		} 
	}
	
	return B;
}

vector<vector<long>> CatCot (long Asum,vector<vector<long>> A,long &cot, bool OnlyOneThird)
{
	long tong = 0;
	vector<vector<long>> B;
	cot = -1;
	
	for(long i = 0; i < A[0].size(); i++) {
		tong = Tong(0,0,A.size()-1,i,A);
		if (tong == Asum / 3){
			cout << " tong = " << tong << " cot = " << i << endl;
			B = CreateV(0,i+1,A.size()-1,A[0].size()-1,A);
			cot = i+1;
			return B;
		} 
		if (tong == 2*Asum/3 && !OnlyOneThird){
			cout << " tong = " << tong << " dong = " << i << endl;
			B = CreateV(0,0,A.size()-1,i,A);
			cot = i+1;
			return B;
		}
	}
	
	return B;
}

bool Solution1 (long Asum,vector<vector<long>> A, long &cot, long &dong)
{
	long tong = 0;
	vector<vector<long>> B,C;
	
	B = CatDong(Asum,A,dong,false);
//	PrintV(B);
	if (dong != -1) C = CatCot(Asum,B,cot,true);
	cout << " Fdong = " << dong << " Fcot = " << cot << endl;
	if (dong != -1 && cot != -1) return true;
	return false;
}


bool Solution2 (long Asum,vector<vector<long>> A, long &cot, long &dong)
{
	dong = -1;
	cot = -1;
	long tong = 0;
	vector<vector<long>> B,C;
	
	B = CatCot(Asum,A,cot,false);
	if (cot != -1) C = CatDong(Asum,B,dong,true);
	cout << " Fdong = " << dong << " Fcot = " << cot << endl;
	if (dong != -1 && cot != -1) return true;
	return false;
}

void Print(bool result, long cot, long dong, int solution)
{
	if (result == true){
		cout << "YES" << endl;
		if (solution == 1){
			cout << "N " << dong << endl;
			cout <<  "D " << cot << endl;	
		}
		else{
			cout <<  "D " << cot << endl;
			cout << "N " << dong << endl;
		}
	}
	else cout << "NO";
}

void Solve(long sum,vector<vector<long>> A)
{
	long cot,dong;
	cout << " sum = " << sum << endl;
	if (sum % 3 != 0) Print(false,-1,-1,0);
	else if (Solution1(sum,A,cot,dong)) Print(true,cot,dong,1);
	else if (Solution2(sum,A,cot,dong)) Print(true,cot,dong,2);
	else Print(false,-1,-1,0);
}

int main()
{
	vector<vector<long>> A;
	vector<long> T;
	long input;
	long sum = 0;
	
	inp.open("C:\\HSG1\\DOWRY4.INP");
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
	
//	PrintV(A);
	Solve(sum,A);	
	
	inp.close();
	out.close();
}
