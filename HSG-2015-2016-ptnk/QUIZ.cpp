#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

long CountDivisor(long n){
	long count = 2;
	
	if(n == 1) return 1;
	if(n == 2) return 2;
	
	for(long i = 2; i <= (n/2)+1; i++){
		if(n % i == 0) count++;
	}
	
	return count;
}

void Solve(long n, long k){
	long result = 0, count;
	for(long i = 1;i <= n; i++){
		count = CountDivisor(i);
		if(count == k){
			result++;
			cout << "i = " << i << " count = " << count << endl;
		}
	}
	
	cout << result;
}

int main(){
	long n,k;
	inp.open("C:\\bt_c++\\HSG-2015-2016-ptnk\\QUIZ.INP");	
	out.open("C:\\bt_c++\\HSG-2015-2016-ptnk\\QUIZ.OUT");
	
	inp >> n >> k;
	
	n++;
	
	Solve(n,k);
	
	inp.close();
	out.close();
}
