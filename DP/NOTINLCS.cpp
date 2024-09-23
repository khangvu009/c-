#include<bits/stdc++.h>

using namespace std;

ifstream inp;

int Lcs[10000][10000];

struct POINT{
	long x = -1;
	long y = -1;
};

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
	POINT ps;
	POINT pe;
	bool flag = true;
	string temp;
	vector<string> A,B;

	if(str[x] == str1[y]){
		ps.x = x;
		ps.y = y;
		flag = false;
		lcs = lcs + str[x];	
	}
	
	while(x > 0 && y > 0){
		if(str[x-1] == str1[y-1]) {
			if(flag){
				ps.x = x-1;
				ps.y = y-1;
				flag = false;
			} else {
				pe.x = x-1;
				pe.y = y-1;
				cout << "start(" << ps.x << "," << ps.y << ")" << endl; 
				cout << "end(" << pe.x << "," << pe.y << ")" << endl; 
				if(ps.x > pe.x+1){
					temp = str.substr(pe.x+1,ps.x-pe.x-1);
					cout << " Sa = " << temp << endl;
					A.push_back(temp);
				}
				
				if(ps.y > pe.y+1){
					temp = str1.substr(pe.y+1,ps.y-pe.y-1);	
					cout << " Sb = " << temp << endl;
					B.push_back(temp);
				}				
				ps.x = pe.x;
				ps.y = pe.y;
			}
			lcs = lcs + str[x-1];
			cout << "Lcs = " << lcs << endl;
			x--;
			y--;
		}
		else{
			cout << "x = " << x << " y = " << y << endl;
			if(Lcs[x-1][y] > Lcs[x][y-1]){
				x--;
			}
			else{
				y--;
			}
			
//			if(x == 1 || y == 1) {
//				cout << "start(" << ps.x << "," << ps.y << ")" << endl; 
//				cout << "end(" << pe.x << "," << pe.y << ")" << endl; 
//				pe.x = 1;
//				pe.y = 1;
//				if(ps.x > pe.x+1){
//					temp = str.substr(pe.x+1,ps.x-pe.x-1);
//					cout << " Sa = " << temp << endl;
//					A.push_back(temp);
//				}
//				
//				if(ps.y > pe.y+1){
//					temp = str1.substr(pe.y+1,ps.y-pe.y-1);	
//					cout << " Sb = " << temp << endl;
//					B.push_back(temp);
//				}		
//			}
		}
	}
	for(long i = 0; i < str.length(); i++) {
		for(long j = 0; j < str1.length(); j++) {
			cout << "      " << Lcs[i][j];
		}
		cout << endl;
	}
	
	cout << endl << endl;
	
	cout << "A = " << str << endl;
	cout << "B = " << str1 << endl;
	cout << " diff str1: ";
	for(long i = A.size()-1; i >= 0; i--){
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "diff str2: ";
	for(long i = B.size()-1; i >= 0; i--){
		cout << B[i] << " ";
	}
	cout << endl;
	reverse(lcs.begin(),lcs.end());
	
	cout << "lcs = " << lcs << endl;
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
