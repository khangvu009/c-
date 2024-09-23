#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

long long A[10000][10000];

void Solve(long n , long max){
	long i = 0, j = 0,sum = 0;
	long mind = 1, maxd = n, minc = 1, maxc = n,count = 1, k = 1, l = n;
	
	while(maxd >= mind){
		long x = mind;
		long y = minc;
		i = mind;
		j = minc;
		while(true){
			A[i][j] = count;
			if (i == mind && j < maxc) j++;
			else if (i < maxd && j == maxc) i++;
			else if (i == maxd && j > minc) j--;
			else if (i > mind && j == minc) i--;
			count++;
			if (i == x && j == y) break;
		}
		mind++;
		minc++;
		maxd--;
		maxc--;
	}
	while (k <= n){
		sum+= A[k][l];
		k++;
		l--;
	}
	
	cout << sum;
}

int main(){
	long n;
	
	inp.open("C:\\bt_c++\\HSG-2018-2019-ptnk\\SPIRAL.INP");
	out.open("C:\\bt_c++\\HSG-2018-2019-ptnk\\SPIRAL.OUT");
	
	inp >> n;

	Solve(n, n*n);
	
	inp.close();
	out.close();
}
