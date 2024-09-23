#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct POINT{
	long long con1;
	long long con2;
};

void Solve(long long l , long long r ,long long t){
	POINT condition;
	POINT condition1;
	long long result;
	
	condition.con1 = t-l;
	condition.con2 = t-condition.con1;
	condition1.con1 = t-r;
	condition1.con2 = t-condition1.con1;
	
	cout << condition.con1 << " " << condition.con2 << " " << condition1.con1 << " " << condition1.con2 << endl;
	if (condition.con2 >= l && condition.con1 <= r){
		result = (condition.con1-condition.con2-1)/ 2 + 1;
	}
	else if (condition1.con1 < r-1 && condition1.con1 >= l){
		result = (condition1.con2-condition1.con1-1)/ 2 + 1;
	}
	else{
		result = 0;
	}
	
	cout << result;
}

int main() {
	long long l,r,t;
	
	inp.open("C:\\bt_c++\\THT-2022-2023\\cntpair.INP");
	out.open("C:\\bt_c++\\THT-2022-2023\\cntpair.OUT");
	
	inp >> l >> r >> t;
	
	Solve(l,r,t);
	
	inp.close();
	out.close();
}
