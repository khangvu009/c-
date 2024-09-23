#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void Solve(double s1, double v1, double s2, double v2){
	double x;
	
	if (s1 == s2 ) cout << 0;
	else{
		x = (s1-s2)/(-v1+v2);
		if (x < 0) cout << -1;
		else cout << (long)(x);
	}
}

int main(){
	double s1,v1,s2,v2;
	
	inp.open("C:\\bt_c++\\HSG-2021-2022-HaNoi\\DRB.INP");
	out.open("C:\\bt_c++\\HSG-2021-2022-HaNoi\\DRB.OUT");
	
	inp >> s1 >> v1 >> s2 >> v2;
	
	Solve(s1,v1,s2,v2);
	
	inp.close();
	out.close();
	
}
