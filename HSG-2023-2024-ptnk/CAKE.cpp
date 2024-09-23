#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<vector<long>> A;

long SumAcross(long sum, long n){
	for(long i = 0; i < A.size(); i++){
		sum += A[i][n];
	}
	
	return sum;
}

long CutAcross(long condition){
	long sum = 0,count = 0;
	bool flag = false;
	
	for(long i = 0; i < A[0].size(); i++){
		sum = SumAcross(sum,i);
		if (flag && sum != condition) break;
		if (sum == condition){
			flag = true;
			count++;
		}
	}
	
	return count;
}

long SumHorizon(long sum1, long n){
	for(long i = 0; i < A[0].size(); i++){
		sum1 += A[n][i];
	}
	
	return sum1;
}

long CutHorizon(long condition){
	long sum1 = 0,count = 0;
	bool flag = false;
	
	for(long i = 0; i < A.size(); i++){
		sum1 = SumHorizon(sum1,i);
		if (flag && sum1 != condition) break;
		if (sum1 == condition){
			flag = true;
			count++;
		}
	}
	
	return count;
}

void Solve(long k){
	long condition = k * 2;
	long count = CutAcross(condition);
	long count1 = CutHorizon(condition);
	
	cout << count * count1;
}

int main(){
	long m,n, x,y,k;
	vector<long> T;
	  
	inp.open("C:\\bt_c++\\HSG-2023-2024-ptnk\\CAKE.INP");
	out.open("C:\\bt_c++\\HSG-2023-2024-ptnk\\CAKE.OUT");
	
	inp >> m >> n >> k;
	
	for(long i = 0; i < m; i++){
		for(long j = 0; j < n; j++){
			T.push_back(0);
		}
		A.push_back(T);
		T.clear();
	}
	
	for(long i = 0; i < k * 4; i++){
		inp >> x >> y;
		A[x-1][y-1] = 1;
	}
	
//	for(long i = 0; i < m; i++){
//		for(long j = 0; j < n; j++){
//			cout << A[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	Solve(k);
	
	inp.close();
	out.close();
}
