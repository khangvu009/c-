#include<bits/stdc++.h>

using namespace std;

ifstream inp;

string Lcs[1000][1000];

void Solve(string str, string str1){
	str = "a" + str;
	str1 = "a" + str1;
	
	for(long i = 0; i < str.length(); i++) {
		Lcs[0][i] = "";
	}
	for(long i = 0; i < str1.length(); i++) {
		Lcs[i][0] = "";
	}
	
	for(long i = 1; i < str.length(); i++) {
		cout << "i = " << i << endl;
		for(long j = 1; j < str1.length(); j++) {
			cout << "       j = " << j << endl;
			if (str[i] == str[j]) {
				Lcs[i][j] = Lcs[i-1][j-1] + str[i];
			} else {
				if(Lcs[i-1][j].length() >= Lcs[i][j-1].length()){
					Lcs[i][j] = Lcs[i-1][j];
				} else {
					Lcs[i][j] = Lcs[i][j-1];
				}
			}
		}
	}
	
	cout << Lcs[str.length()-1][str1.length()-1] << endl;
	cout << Lcs[str.length()-1][str1.length()-1].length();
}

int main(){
	string str,str1;
	
	inp.open("C:\\bt_c++\\DP\\LCS.INP");
	
	inp >> str >> str1;
	
	Solve(str,str1);
	
	inp.close();	
}
