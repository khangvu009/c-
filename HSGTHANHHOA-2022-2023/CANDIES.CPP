#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

void Solve(){
	long sum = 0,average;
	
	for(long i = 0; i < A.size(); i++){
		sum += A[i];
	}

	average = (sum - A.size() * 3) / 3;
	
	out << A.size() << endl << average;
}

int main(){
	long n,input;
	
	inp.open("CANDIES.INP");
	out.open("CANDIES.OUT");
	
	
	inp >> n;
	
	for(long i = 0; i < n; i++){
		inp >> input;
		if(input % 3 == 0 && input != 0) A.push_back(input);
	}
	cout << endl;
	Solve();
	
	inp.close();
	out.close();
}
