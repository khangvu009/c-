#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

bool Check(long a,long b,long n, long &t){

	t = 0;
	if((n-1) % a != 0 && (n-1) % b != 0) return false;
	if((a > n-1 && b > n-1)) return false;
	if((n-1) % a != 0 && b > n-1)  return false;
	if((n-1) % b != 0 && a > n-1) return false;
	
	if((n-1) % a == 0 && a > t) t = a;
	if((n-1) % b == 0 && b > t) t = b;
	
	
	return true;
}

void Solve(long n, long a,long b, long c,long d){
	long count = 0,t,ch;
	
	if(Check(a,b,n,t)){
		if(Check(c,d,n,ch)){
			count = (n-1) / t + (n-1) / ch;
			cout << count;
		}
		else{
			cout << -1;
		}
	}
	else{
		cout << -1;
	}
}

int main(){
	long n,a,b,c,d;
	
	inp.open("C:\\bt_c++\\HSG-2023-2024-tp\\ROBOT.INP");
	out.open("C:\\bt_c++\\HSG-2023-2024-tp\\ROBOT.OUT");
	
	inp >> n >> a >> b >> c >> d;
	
	Solve(n,a,b,c,d);
	
	inp.close();
	out.close();	
}
