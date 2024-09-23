#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;



void Solve(long x, long y ,long z){
	long result = ((x*z)-(y*z)) / y;
	
	if (((x*z)-(y*z)) % y != 0) result++;
	
	cout << result;
}

int main(){
	long x,y,z;
	
	inp.open("C:\\bt_c++\\HSG-2021-2022-HaNoi\\TBG.INP");
	out.open("C:\\bt_c++\\HSG-2021-2022-HaNoi\\TBG.OUT");
	
	inp >> x >> y >> z;
	
	
	Solve(x,y,z);
	
	inp.close();
	out.close();
	
}
