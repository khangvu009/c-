#include<bits/stdc++.h>

using namespace std;

void Solve(unsigned long long n){
	unsigned long long sum = 0,pre = 1,cur = 1,odd,even;
	int t = (n % 2);
//	if (n % 2 == 0){
//		odd = n / 2;
//		even = n / 2;
//	}
//	else{
//		odd = n / 2 +1;
//		even = n / 2 + 1 -1;
//	}
	
	odd = n / 2 + t;
	even = n / 2 + t -t;
//	cout << "odd = " << odd << " sumodd =  " << odd * odd << endl;
//	cout << "even = " << even << " sumeven =  " << even * 2 << endl;
	
	sum += odd * odd;
	sum +=  even * even;
	sum = sum % 100;
	
//	for(unsigned long long i = 1; i < n; i++){
//		if( (i+1) % 2 == 0){
//			cur = pre;
//		}
//		else{
//			cur = pre+2;
//		}
//		pre = cur;
//		sum = (sum % 100 + cur % 100) % 100;
//	}	
	
	cout << sum;
}


int main(){
	unsigned long long n;
	
	cin >> n;
	
	Solve(n);
}
