#include <bits/stdc++.h>
using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

void FindMinMax(long &min1, long &max1, long start,long end){
	for(long i = start; i <= end; i++){
		min1 = min(A[i],min1);
		max1 = max(A[i],max1);
	}
}

void Solve() {
	long min1 = LONG_MAX,max1 = 0,count = 0;
	
	for(long i = 0; i < A.size()-1; i++){
		for(long j = i+1; j < A.size(); j++){
//			cout << "i = " << i+1 << " j = " << j+1 << endl;
			FindMinMax(min1,max1,i,j);
//			cout << "	min = " << min1 << " max1 = " << max1 << endl;
			
			if( (A[i] == min1 && A[j] == max1) || (A[i] == max1 && A[j] == min1)){
//				cout << "	 	A[i] = " << A[i] << " A[j] = " << A[j] << endl;
				count++; 
			}
			min1 = LONG_MAX;
			max1 = 0;
		}
	}
	
	out << count;
}

int main() {
    long n,input;
    
    inp.open("TrungThuong.inp");
    out.open("TrungThuong.out");
    
	inp >> n;
	
	cout << n << endl;
	
    for(long i = 0; i < n; i++){
    	inp >> input;
    	A.push_back(input);
	}
	
	cout << A.size() << endl;
	
	Solve();
    
	inp.close();	
    out.close();
}
