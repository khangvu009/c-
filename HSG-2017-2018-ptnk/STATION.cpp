#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;


struct circle{
	long index;
	long coordinate;
};

vector<long> A;

vector<circle> FindAllSastify(long n,long temp,long r, long a){
	vector<circle> B;
	long index;
	circle c;		
	
	for(long i = 0; i < A.size(); i++){
		if(A[i] <= a+r+temp){
			c.coordinate = A[i];
			c.index = i+1;
			B.push_back(c);
		}
	}
	
	for(long i = 0; i < B.size(); i++){
		cout<< B[i].coordinate << " ";
	}
	cout << endl;
	return B;
}

void FindMax(vector<circle> B, vector<long> &C, long & a){
	long index,max = -1;
	for(long i = 0; i < B.size(); i++){
		if(max < B[i].coordinate){
			max = B[i].coordinate;
			index = B[i].index;
		}
	}
	
	a = max;
	C.push_back(index);
}

void Solve(long n, long r){
	long i = 0,count = 0,temp = 0;
	vector<circle> B;
	vector<long> C;
	
	while(i+r < n-r){
		B = FindAllSastify(n,temp,r,i);
		FindMax(B,C,i);
		count++;
		temp = r;
	}
	
	cout << count << endl;
	for(long i = 0; i < C.size()-1; i++){
		cout << C[i] << " ";
	}
	
	cout << C[C.size()-1];
}

int main(){
	long n,input,r,m;
	
	inp.open("C:\\bt_c++\\HSG-2017-2018-ptnk\\STATION.INP");
	out.open("C:\\bt_c++\\HSG-2017-2018-ptnk\\STATION.OUT");
	
	inp >> n >> m >> r;
	
	for(long i = 0; i < m; i++){
		inp >> input;
		A.push_back(input);
	}
	
	Solve(n,r);
	
	inp.close();
	out.close();
}
