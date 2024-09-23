#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<vector<long>> A;

void Solve(){
	vector<long> Temp,B;
	
	for(long i = 0; i < A.size(); i++){
		Temp = A[i];
		sort(Temp.begin(),Temp.end());
		if (Temp.size() % 2 != 0) B.push_back(Temp[Temp.size() / 2 ]);
		else  B.push_back(Temp[Temp.size() / 2 - 1]);
	}
	
	cout << endl;
	for(long i =0; i < B.size(); i++){
		cout << B[i] << " ";
	}
	if (B.size() % 2 != 0) out << B[B.size() / 2];
	else out << B[B.size() / 2 -1];
}

int main(){
	long input,n;
	vector<long> T;
	
	inp.open("C:\\bt_c++\\HSG-2009-2010\\TRUNGVI.INP");
	out.open("C:\\bt_c++\\HSG-2009-2010\\TRUNGVI.OUT");
	
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		for(long j = 0; j < n; j++){
			inp >> input;
			T.push_back(input);
		}
		A.push_back(T);
		T.clear();
	}
	
	
	for(long i = 0; i < n; i++){
		for(long j = 0; j < n; j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	
	Solve();
	
	inp.close();
	out.close();
}
