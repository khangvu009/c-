#include<bits/stdc++.h>
#include <string>

using namespace std;

ifstream inp;
ofstream out;

struct point{
	long s;
	long e;
};

vector<point> A;

long Sum(long n, long &temp){
	long result;
	
	temp = 0;
	
	// Convert the long to a string
    string numString = to_string(n);
	cout << numString << " " << n << endl;
    // Create a vector of integers using constructor with iterators
    vector<int> digits;
    transform(numString.begin(), numString.end(), back_inserter(digits), [](char c) {
        return c - '0'; // Convert character to integer
    });
    result = accumulate(digits.begin() , digits.end(), 0);
    cout << "result = " << result << endl;
//    result = 0;
//	while(n > 0){
//		result = result + (n % 10); 
////		temp = temp * 10 + (n % 10);
//		n = n / 10;
//	}
		
	return result;
}

bool IsPrime(long n){
	if (n == 1) return false;
	if (n == 2) return true;
	
	for(long i = 2; i <= sqrt(n)+1; i++){
		if(n % i == 0) return false;
	}
	
	return true;
}

long Processing(point p){
	long start,end,count = 0,sum,temp;
	
	if (p.s == 1){
		start = 1;
	}
	else{
		start = pow(10,p.s-1)+1;
	}
	end = pow(10,p.e)-1;
	
	cout << "start = " << start << " end = " << end << endl;
	for(long i = start; i <= end; i++){
		sum = Sum(i,temp);
		if(IsPrime(sum)){
			count++;
		}
	}
	
	return count;
}

void Solve(){
	long result;
	
	for(long i = 0; i < A.size()-1; i++){
		result  = Processing(A[i]);
		cout << result << endl;
	}
	result = Processing(A[A.size()-1]);
	cout << result;
	
}

int main(){
	long q;
	point p;
	
	inp.open("C:\\bt_c++\\HSG-2023-2024-tp\\SDIGIT.INP");
	out.open("C:\\bt_c++\\HSG-2023-2024-tp\\SDIGIT.OUT");
	
	inp >> q;
	
	for(long i = 0; i < q; i++){
		inp >> p.s >> p.e;
		A.push_back(p);
	}
	
	Solve();
	
	inp.close();
	out.close();
}
