#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<vector<long>> A;
vector<bool> B;

long FindMinThatLargerThanH(long h, long a){
	long max = A[a][0];
	long min;
	
	for(long i = 0; i < A.size(); i++){
		if(A[a][i] > h && A[a][i] < max){
			max = A[a][i];
			min = A[a][i];
		}
	}
	
	return min;
}

void FindMin(vector<long> &C, long & h){
	long min = C[0];
	long index;
	
	if(C.size() > 0){
		for (long i = 0; i < C.size(); i++){
			if(min < C[i]){
				min = C[i];
				h = C[i];
				index = i;
			}
		}
		B[index] = false;
	}
	C.clear();
}

bool Processing(vector<long> & C,long h){
	long min,count = 0;
		
	for(long i = 0; i < A[0].size(); i++){
		if(B[i]){
			min = FindMinThatLargerThanH(h,i);
			C.push_back(min);
		}
		count++;
	}
	if(count == 0){
		return false;
	}
	return true;
}

void Solve(long h){
	long count = 0;
	vector<long> C;
	
	while(Processing(C,h)){
		FindMin(C,h);
		count++;
	}
}

int main(){
	long n,m,input,x,y,h;
	vector<long>T;
	
	inp.open("C:\\bt_c++\\HSG-2013-2014\\JROBOT.INP");
	out.open("C:\\bt_c++\\HSG-2013-2014\\JROBOT.OUT");	
	
	inp >> n >> m;
	
	for(long i = 0; i < n; i++){
		for(long j = 0; j < m; j++){
			inp >> input;
			T.push_back(input);	
		}
		A.push_back(T);
		T.clear();
	}
	
	inp >> x >> y;
	h = A[x][y];
	
	for(long i = 0; i <A[0].size(); i++){
		B.push_back(true);	
	}
	
	for(long i = 0; i < n; i++){
		for(long j = 0; j < m; j++){
			cout << A[i][j] << " ";	
		}
		cout << endl;
	}
	
	Solve(h);
	
	inp.close();
	out.close();
}

