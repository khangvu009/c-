#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void PrintSpace(long n){
	for (long i = 1; i <= n; i++){
		cout << " "; 
		out << " ";
	}
}

void PrintTree(long n){
	long count = n-1;
	
	for (long i = 0; i <= n-1; i++){
		PrintSpace(count);
		for (long j = n-i; j <= n; j++){
			out << "* ";
			cout << "* ";
		}
		if (i < n){
			out << endl;
			cout << endl;
		}
		count--;
	}
}

void Solve(long n){
	if (n != 0) PrintTree(n);
	else{
		out << "can not print";
		cout << "can not print";	
	}
}

int main(){
	long n;
	
	inp.open("C:\\bt_c++\\LUYEN_CODE\\CHRISTMASTREE.INP");
	out.open("C:\\bt_c++\\LUYEN_CODE\\CHRISTMASTREE.OUT");
	
	inp >> n;
	
	Solve(n);
	
	inp.close();
	out.close();
}
