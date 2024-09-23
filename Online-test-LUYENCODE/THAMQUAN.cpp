#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void Solve(unsigned long long  t, unsigned long long start, unsigned long long end){
	int paid,paid1,sum = 0;
	
	if(t > 1 && t < 7){
		paid = 6;
		paid1 = 10;
	}
	else{
		paid = 10;
		paid1 = 15;
	}
	
	if(start < 6) start = 6;
	
	if(end <= 18 && start <= 12){
		sum += (12-start) * paid;
		sum += (end-12) * paid1;	
	}
	else if (end <= 18 && start > 12){
		sum += (end - start) * paid1;
	}
	else if(end <= 12 && start <= 12){
		sum += (end-start) * paid;
	}
	if(end > 18){
		sum += (end - 18) * 20;
	}
	
	cout << sum;
}

int main(){
	unsigned long long start,end,t;
	
	inp.open("C:\\bt_c++\\Online-test-LUYENCODE\\THAMQUAN.INP");
	out.open("C:\\bt_c++\\Online-test-LUYENCODE\\THAMQUAN.OUT");
	
	inp >> t >> start >> end;
	
	Solve(t,start,end);
	
	inp.close();
	out.close();
}
