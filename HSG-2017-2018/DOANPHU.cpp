#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct Street{
	long start;
	long end;
	long count = 0; 	
};

vector<long> A;

void CountSame(long a, long b, vector<Street> &B){
	bool flag = true;
	Street st;
	
	a = min(a,b);
	b = max(a,b);
	
	for(long i = a; i < b; i++){
		flag = true;
		for(long k = 0; k < B.size(); k++){
			if (i == B[k].start && i+1 == B[k].end){
				B[k].count++;
				flag = false;
				break;	
			}
		}
		if (flag){
			st.start = i;
			st.end = i+1;
			st.count = 1;
			B.push_back(st);
		}
	}
}

void Processing(vector<Street> &B){
	for(long i = 0; i < A.size()-1; i=i+2){
		CountSame(A[i],A[i+1],B);
	}
}

void Sort (vector<Street> &B){
	Street temp;
	
	for(long i = 0; i < B.size()-1; i++){
		for(long j = i+1; j < B.size(); j++){
			if(B[i].count < B[j].count){
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}
	}
}

long FindMaxSame(vector<Street> &B){
	Sort(B);
	long pattern = B[0].count;
	long count = 0;
	for(long i = 0; i < B.size(); i++){
		if (B[i].count != pattern) break;
		count++;	
	}
	
	return count;
}

void Solve(){
	vector<Street> B;
	
	Processing(B);
	long result = FindMaxSame(B);
	for(long i = 0; i < B.size(); i++){
		cout << B[i].start << " " << B[i].end << " " << B[i].count << endl;
	}
	cout << result;
}

int main(){
	long n,input;	

	inp.open("C:\\bt_c++\\HSG-2017-2018\\DOANPHU.INP");
	out.open("C:\\bt_c++\\HSG-2017-2018\\DOANPHU.OUT");

	inp >> n;	
	for(long i = 0; i < n*2; i++){
		inp >> input;
		A.push_back(input);
	}
	
	for(long i = 0; i < A.size()-1; i = i + 2) cout << A[i] << " " << A[i+1] << endl;
	cout << endl;
	Solve();
	
	inp.close();
	out.close();
}
