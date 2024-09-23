#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;
vector<bool> B;

void Set(){
	for(long i = 0; i < A.size(); i++){
		B.push_back(true);
	}
}

long FindAllSastify(long a, long b, long d){
	long result = 1;
	long condition = A[a] + A[b];

	for(long i = 0; i < A.size()-1; i++){
		for(long j = i+1; j < A.size(); j++){
			if(B[i] == true && B[j] == true){
				if( abs((A[i] + A[j])-condition) <= d){
					cout << "-- A[i] = " << A[i] << " A[j] = " << A[j] << endl;
					result++;
					B[i] = false;
					B[j] = false;
				}		
			}
		}
	}
	
	B.clear();
	Set();
	return result;
}

void Solve(long d){
	long temp,max = 0;
	Set();
	for(long i = 0; i < A.size()-1; i++){
//		cout << "i = " << i << endl;
		for(long j = i+1; j < A.size(); j++){
			cout << "i = " << i  << " j = " << j << endl;
			B[i] = false;
			B[j] = false;
			temp = FindAllSastify(i,j,d);
//			cout << "result = " << temp << endl;
			if(max < temp) max = temp;			
		}
	}
	
	cout << max;
}

int main(){
	long n,d,input;
	
	inp.open("C:\\bt_c++\\HSG-2021-2022-chon-qg\\PAIR.INP");
	out.open("C:\\bt_c++\\HSG-2021-2022-chon-qg\\PAIR.OUT");
	
	inp >> n >> d;
	
	for(long i = 0; i <n; i++){
		inp >> input;
//		cout << input << " ";
		A.push_back(input);
	}
	
	Solve(d);
	
	inp.close();
	out.close();
}
