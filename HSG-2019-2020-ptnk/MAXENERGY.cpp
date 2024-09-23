#include<bits/stdc++.h>

using namespace std; 

ifstream inp;
ofstream out;

vector<long> A;

void FindMinMax(long &min, long &max, long &index,long &index1){
	for(long i = 0; i < A.size(); i++){
		if(min > A[i]){
			min = A[i];
			index = i;
		}
		if(max < A[i]){
			max = A[i];
			index1 = i;	
		}
	}
}

long FindMaxEnergy(long min, long max,long index,long index1){
	long result = LONG_MIN;
	
	for(long i = 0; i < A.size(); i++) if (i != index && i != index1) if (result < (max-A[i])*(A[i]-min)) result = (max-A[i])*(A[i]-min);
	
	return result;
}

void Solve(){
	long min = LONG_MAX, max = LONG_MIN,index,index1;
	
	FindMinMax(min,max,index,index1);
	long energy = FindMaxEnergy(min,max,index,index1);
	
	cout << energy;
}

int main(){
	long n,input;
	
	inp.open("C:\\bt_c++\\HSG-2019-2020-ptnk\\MAXENERGY.INP");
	out.open("C:\\bt_c++\\HSG-2019-2020-ptnk\\MAXENERGY.OUT");
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);
	}
	
	Solve();
	
	inp.close();
	out.close();
}
