#include<bits/stdc++.h>

using namespace std;

ifstream inp;

struct LCS{
	long count;
	long x;
	long y;
};

LCS Lcs[10000][10000];

void Solve(string str, string str1){
	str = "a" + str;
	str1 = "a" + str1;
	string lcs = "";
	long n = str.length()-1;
	long m = str1.length()-1;
	
	for(long i = 0; i < str.length(); i++) {
		Lcs[0][i].count = 0;
		Lcs[0][i].x = 0;
		Lcs[0][i].y = 0;
	}
	for(long i = 0; i < str1.length(); i++) {
		Lcs[i][0].count = 0;
		Lcs[i][0].x = 0;
		Lcs[i][0].y = 0;
	}
	
	for(long i = 1; i < str.length(); i++) {
//		cout << "i = " << i << endl;
		for(long j = 1; j < str1.length(); j++) {
//			cout << "       j = " << j << endl;
			if (str[i] == str1[j]) {
				Lcs[i][j].count = Lcs[i-1][j-1].count + 1;
				Lcs[i][j].x = i-1;
				Lcs[i][j].y = j-1;
			} else {
				if(Lcs[i-1][j].count > Lcs[i][j-1].count){
					Lcs[i][j].count = Lcs[i-1][j].count;
					Lcs[i][j].x = i-1;
					Lcs[i][j].y = j;
				} else {
					Lcs[i][j].count = Lcs[i][j-1].count;
					Lcs[i][j].x = i;
					Lcs[i][j].y = j-1;
				}
			}
		}
	}
	long x = n;
	long y = m;
	
	
	for(long i = 0; i < str.length(); i++) {
		for(long j = 0; j < str1.length(); j++) {
			cout << "      " << Lcs[i][j].count;
		}
		cout << endl;
	}
	
	cout << endl << endl;
	
	for(long i = 0; i < str.length(); i++) {
		for(long j = 0; j < str1.length(); j++) {
			cout << "    " << Lcs[i][j].x << "," << Lcs[i][j].y;
		}
		cout << endl;
	}
	
	if(str[x] == str1[y]) {
			lcs = lcs + str[x];
	}
		
	while(x > 1 && y > 1){
//		cout << "x = " << x << " y = " << y << " next = " << Lcs[x][y].x << "," << Lcs[x][y].y << endl;
//		cout << "     str[x] = " << str[x] << " str1[y] = " << str1[y] << endl;
		if(str[x-1] == str1[y-1]) {
			lcs = lcs + str[x-1];
			x--;
			y--;	
		}
		else if(Lcs[x-1][y].count > Lcs[x][y-1].count) {
			x--;
		}
		else{
			y--;
		}
		
	
	}
	
	reverse(lcs.begin(),lcs.end());
	
	cout << lcs << endl;
	cout << Lcs[str.length()-1][str1.length()-1].count;
}

int main(){
	string str,str1;
	
	inp.open("C:\\bt_c++\\DP\\LCS.INP");
	
	getline(inp,str);
	getline(inp,str1);
	
	Solve(str,str1);
	
	inp.close();	
}
