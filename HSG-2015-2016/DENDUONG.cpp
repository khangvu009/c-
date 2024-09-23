#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

// store
vector<long> A;

// find the distance: 
double FindSumDistance(){
	double sum = 0;
	
	for(long i = 0; i < A.size()-1; i++){
		sum = sum + A[i+1]-A[i];
	}

	return tong;
}

double AverageDistance(){
	double sum; 
	
	sort(A.begin(),A.end());
	tong = FindSumDistance();
	double average = sum / (A.size()-1);
	return average;
}

string FixNumberal (double n){
	string str = to_string(n);
	string str1 = "";
	long countdown = 4;
	bool flag = false;
	
	for (long i = 0; i < str.length(); i++){
		if (str[i] == '.') flag = true;
		if (flag) countdown--;
 		if (countdown > 0) str1 = str1 + str[i];	
	}
	return str1;
}

void Solve(){
	double average = AverageDistance();
	string str = FixNumberal(result);

	cout << str;
}

int main(){
	long n,l,input;
	bool flag = true;
	
	inp.open("C:\\bt_c++\\HSG-2015-2016\\DENDUONG.INP");
	out.open("C:\\bt_c++\\HSG-2015-2016\\DENDUONG.OUT");
	
	inp >> n >> l;
	
	for (long i = 0; i < n; i++){
		inp >> input;
		if (input == l) flag = false;
		A.push_back(input);
	}
	if (flag) A.push_back(l);
	
	Solve();
	inp.close();
	out.close();
}
