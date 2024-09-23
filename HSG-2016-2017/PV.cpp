#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<vector<int>> A;

void Solve(){
	
}

int main(){
	vector<int> T;
	
	int n,m,input;
	
	inp.open("C:\\bt_c++\\HSG-2016-2017\\KB.INP");
	out.open("C:\\bt_c++\\HSG-2016-2017\\KB.OUT");
	
	inp >> m >> n;
	
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			inp >> input;
			T.push_back(input);
		}
		A.push_back(T);
		T.clear();
	}
	
	Solve();
	
	inp.close();
	out.close();
}
