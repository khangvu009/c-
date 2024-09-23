#include<bits/stdc++.h>

using namespace std;

ifstream inp;

int Lcs[10000][10000];

void Solve(string str, string str1){
	str = "a" + str;
	str1 = "a" + str1;
	long n = str.length()-1;
	long m = str1.length()-1;
	string lcs = "";
	
	for(long i = 0; i <= n; i++){
		Lcs[0][i] = 0;
	}
	for(long i = 0; i <= m; i++){
		Lcs[i][0] = 0;
	}
	
	for(long i = 1; i <= n; i++){
		for(long j = 1; j <= m; j++){
			if(str[i] == str1[j]){
				Lcs[i][j] = Lcs[i-1][j-1]+1;			
			}
			else{
				if(Lcs[i-1][j] > Lcs[i][j-1]){
					Lcs[i][j] = Lcs[i-1][j];
				}
				else{
					Lcs[i][j] = Lcs[i][j-1];
				}
			}
		}
	}
	
	long x = n;
	long y = m;
	
	if(str[x] == str1[y]){
		lcs = lcs + str[x];	
	}
	
	while(x > 1 && y > 1){
		if(str[x-1] == str1[y-1]){
			lcs = lcs + str[x-1];
			x--;
			y--;
		}
		else{
			if(Lcs[x-1][y] > Lcs[x][y-1]){
				x--;
			}
			else{
				y--;
			}
		}
	}
	
	reverse(lcs.begin(),lcs.end());
	
	cout << lcs << endl;
	cout << Lcs[n][m];
	
}

int main(){
	string str, str1;
	
	inp.open("C:\\bt_c++\\DP\\LCS.INP");
	
	getline(inp,str);
	getline(inp,str1);
	
	Solve(str,str1);
	
	inp.close();
}
