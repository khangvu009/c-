#include<bits/stdc++.h>

using namespace std;

vector<long long> A,B,C;
ifstream inp;
ofstream out;

bool IsSquareTriangle(long long a, long long b, long long c){
	if (a*a == b*b + c*c){
		cout << a << "^2 = " << b << "^2 + " << c << "^2" << endl;
		return true;
	}
	if (c*c == b*b + a*a){
		cout << c << "^2 = " << a << "^2 + " << b << "^2" << endl;
		return true;
	}
	if (b*b == a*a + c*c){
		cout << b << "^2 = " << a << "^2 + " << c << "^2" << endl;
		return true;
	}
	return false;
}

void Solve(){
	int count = 0;
	
	for(int i = 0; i < A.size(); i++){
		for(int j = 0; j < B.size(); j++){
			for(int k = 0; k < C.size(); k++){
				if (IsSquareTriangle(A[i],B[j],C[k])) count++;	
			}
		}
	}
	
	cout << count;
}

int main(){
	long n,input;
	inp.open("C:\\bt_c++\\HSG-2016-2017\\TGV.INP");
	out.open("C:\\bt_c++\\HSG-2016-2017\\TGV.OUT");
	
	inp >> n;
	
	for (long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);
	}
	for (long i = 0; i < n; i++){
		inp >> input;
		B.push_back(input);
	}
	for (long i = 0; i < n; i++){
		inp >> input;
		C.push_back(input);
	}
	
	Solve();
	
	inp.close();
	out.close();
}
