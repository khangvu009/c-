#include<bits/stdc++.h>

using namespace std;

ifstream inp;

vector<char> Lcs[5000][5000];

void Solve(string str, string str1){
	
	cout << str << " " << str1 << endl;
	str = "a" + str;
	str1 = "a" + str1;
	
	cout << str << " " << str1 << endl;
	
	for(long i = 0; i < str.length(); i++) {
		vector<char> S;
		S.push_back(' ');
		Lcs[0][i] = S;
	}
	for(long i = 0; i < str1.length(); i++) {
		vector<char> S;
		S.push_back(' ');
		Lcs[i][0] = S;
	}
	
	for(long i = 1; i < str.length(); i++) {
		cout << "i = " << i << endl;
		for(long j = 1; j < str1.length(); j++) {
			cout << "       j = " << j << endl;
			if (str[i] == str[j]) {
				vector<char> S;
				S = Lcs[i-1][j-1];
				S.push_back(str[i]);
				Lcs[i][j] = S;
			} else {
				if(Lcs[i-1][j].size() >= Lcs[i][j-1].size()){
					Lcs[i][j] = Lcs[i-1][j];
				} else {
					Lcs[i][j] = Lcs[i][j-1];
				}
			}
		}
	}
	
	for(long i = 1; i < Lcs[str.length()-1][str1.length()-1].size(); i++) {
		cout << Lcs[str.length()-1][str1.length()-1][i];
	}
	cout << endl << Lcs[str.length()-1][str1.length()-1].size()-1;
}

int main(){
	string str,str1;
	
	inp.open("C:\\bt_c++\\DP\\LCS.INP");
	
	inp >> str >> str1;
	
	Solve(str,str1);
	
	inp.close();	
}
