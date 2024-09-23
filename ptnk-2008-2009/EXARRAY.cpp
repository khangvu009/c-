#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A,B,C,D,Result;

bool Check(){
	sort(C.begin(),C.end());
	sort(D.begin(),D.end());
	
	for(long i = 0; i < C.size(); i++){
		if(C[i] != D[i]) return false;
	}
	return true;
}

bool IsSame (){
	for(long i = 0; i < A.size(); i++){
		if(A[i] != B[i]) return false;
	}
	return true;
}

long Findindex(long n){
	for(long i = 0;  i < B.size(); i++){
		if(n == B[i]) return i;
	}
}

void Solve(){
	long index,count = 0,i = 0;
	bool flag = false;
	
	if(Check){
		if(IsSame) flag = false;
		while(flag){
			index = Findindex(A[0]);
			for(long i = 0; i <= index-1; i++){
				swap(A[i],A[i+1]);
				count++;
				Result.push_back(i+1);
			}
		}
		if(count != 0){
			cout << count << endl;
		
			for(long i = 0; i < Result.size(); i++){
			cout << Result[i] << " ";
		}
		else{
			cout << count;
		}
	}
	else{
		cout << -1;
	}
}

int main(){
	long n,input;
		
	inp.open("EXARRAY.INP");
	out.open("EXARRAY.OUT");
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		A.push_back(input);
	}
	cout << endl;
	for(long i = 0; i < n; i++){
		B.push_back(input);
	}
	C = A;
	D = B;
	
	Solve();
	
	inp.close();
	out.close();
}
