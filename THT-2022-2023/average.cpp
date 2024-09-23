#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

void Solve(long t) {
	double result,average,maxaverage = ((double(A[0]))+(double(A[1]))+(double(A[2]))) / 3;

	for(long i = 0; i < A.size()-2; i++){
		for(long j = i+1; j < A.size()-1; j++){
			for(long k = j+1; k < A.size(); k++){
				average = ((double(A[i]))+(double(A[j]))+(double(A[k]))) / 3;
				if(av)
			}
		}
	}	
}

int main() {
	long n,input;
	
	inp.open("C:\\bt_c++\\THT-2022-2023\\average.INP");
	out.open("C:\\bt_c++\\THT-2022-2023\\average.OUT");
	
	inp >> n >> t;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);
	}
	
	Solve(t);
	
	inp.close();
	out.close();
}
