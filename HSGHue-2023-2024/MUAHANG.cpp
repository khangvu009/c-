#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> C,W;


struct Store{
	long max;
	long x;
	long y;
	long c;
	long cw;
};

Store Dp[1000][1000];
vector<Store> Backtrack;

void Solve(long n,long m){
	Store Max;
	Max.max = -1;
	int last;
	
	long mass = 0;
	
	for(long i = 0; i <= m; i++){
		Dp[0][i].max = 0;
		Dp[0][i].x = -1;
	}
	for(long i = 0; i <= n; i++){
		Dp[i][0].max = 0;
		Dp[0][i].x = -1;
	}
	
	for(long i = 1; i <= m; i++){
//		cout << "i = " << i << endl;
		for(long j = 0; j <= n; j++){
//			cout << "	j  = " << j << endl;
			Dp[i][j].max = Dp[i-1][j].max;
			Dp[i][j].x = i-1;
			Dp[i][j].y = j;
			Dp[i][j].c = i;
			Dp[i][j].cw = j;
			if(j >= W[i] && Dp[i-1][j-W[i]].max + C[i] > Dp[i-1][j].max){
				Dp[i][j].max =  Dp[i-1][j-W[i]].max + C[i];
				Dp[i][j].y = j-W[i];
			}
			if(Max.max < Dp[i][j].max){
				Max = Dp[i][j];
			}
		}
	}
	Store Temp;
	Temp = Max;
	

	
	for(long i = 0; i <= m; i++){
		for(long j = 0; j <= n; j++){
//			cout << Dp[i][j].max << "," << Dp[i][j].x << ":" << Dp[i][j].y << ":" << Dp[i][j].c << "    ";
			cout << Dp[i][j].max << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	
	 
	while(Temp.x > -1){
		Backtrack.push_back(Temp);
		Temp = Dp[Temp.x][Temp.y];		
	}
	
	long temp = 0;
	
	cout << Max.max << endl;
	vector<long> Print;
	
	mass = Max.cw;
	for(long i = Backtrack.size()-1; i >= 0; i--){
		Temp = Backtrack[i];
		if(temp < Temp.max){
			temp = Temp.max;
			Print.push_back(Temp.c);
		}
	}
	for(long i = 0; i < Print.size()-1; i++){
		cout << Print[i] << " ";
	}
	cout << Print[Print.size()-1] << endl;

	cout << mass;
}

int main(){
	long n,m,input;
	
	inp.open("MUAHANG.INP");
	out.open("MUAHANG.OUT");
	
	inp >> m >> n;
	
	W.push_back(0);
	C.push_back(0);
	
	for(long i = 0; i < n; i++){
		inp >> input;
		W.push_back(input);
		inp >> input;
		C.push_back(input);
	}
	
	Solve(n,m);
	
	inp.close();
	out.close();
}
