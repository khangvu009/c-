#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

long CountSquareTriangle(long p){
	long c, count = 0;
	
	for(long a = 1; a < p / 3; a++){
		for(long b = a+1; b < p / 2; b++){
			c = p - b - a;
			if (c < b) break;
			if(a*a + b*b == c*c){
				cout << "a = " << a*a << " b = " << b*b << " c = " << c*c << endl;
				count++;
			}
		}
	}
	
	return count;
}

void Solve(){
	long count = 0;
	
	for(long i = 0; i < A.size()-1; i++){
		count = CountSquareTriangle(A[i]);
		cout << count << endl;
	}
	count = CountSquareTriangle(A[A.size()-1]);
	cout << count;
}

int main(){
	long n,input;
	
	inp.open("C:\\bt_c++\\HSG-2018-2019-ptnk\\PYTHAGORE.INP");
	out.open("C:\\bt_c++\\HSG-2018-2019-ptnk\\PYTHAGORE.OUT");
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);
	}
	
	Solve();

	inp.close();
	out.close();
}
