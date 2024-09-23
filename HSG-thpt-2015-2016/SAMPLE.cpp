#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct Jewery{
	long mass;
	long value;
	bool flag = true;
};

vector<Jewery> A;
vector<long> B;

long long Find(long mass){
	long max1 = -1,max2 = -1,index;
	
	for(long i = 0; i < A.size(); i++){
		if(A[i].flag && A[i].mass > max1 && A[i].mass <= mass){
			if(A[i].value > max2){
				max2 = A[i].value;
				index = i;
			}
		}	
	}
	
	A[index].flag = false;
	if(max2 == -1) return 0;
	return max2;
}

void Solve(){
	long long result = 0;
	
	sort(B.begin(),B.end());
	
	for(long i = 0; i < B.size(); i++){
		result += Find(B[i]);	
	}
	
	cout << result;
}

int main(){
	Jewery je;
	long n,m,input;
	
	inp.open("C:\\bt_c++\\HSG-thpt-2015-2016\\SAMPLE.INP");
	out.open("C:\\bt_c++\\HSG-thpt-2015-2016\\SAMPLE.OUT");
	
	inp >> n >> m;

	for(long i = 0; i < n; i++){
		inp >> je.mass >> je.value;
		A.push_back(je);	
	}
	for(long i = 0; i < m; i++){
		inp >> input;
		B.push_back(input);
	}
	
	Solve();
	
	inp.close();
	out.close();
	
}
