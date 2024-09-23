#include<bits/stdc++.h>

using namespace std;

struct Branch{
	long left;
	long right;
};

struct Spread{
	vector<long> Ancestor;
	long distance;
};

vector<Branch> A;
vector<long> B;
vector<Spread> C;

void eraseElementByIndex(size_t index) {
    A.erase(A.begin() + index);
}

void Sonof1(){
	long a = 1;
	
	for(long i = 0; i < A.size(); i++){
		if(A[i].left == 1){
			C[A[i].right].Ancestor.push_back(1);
			C[A[i].right].distance = 1;
			eraseElementByIndex(i);
		}
		else if (A[i].right == 1){
			C[A[i].left].Ancestor.push_back(1);
			C[A[i].left].distance = 1;
		}
	}
}

void Solve(long n){
	long min;
	Spread sp;
	
	for(long i = 0;  i <= n; i++){
		C.push_back(sp);
	}
	
	Sonof1();
	Board();
	
	min = FindMinDistance();
	
	cout << min << endl;
}

int main(){
	long n,q,input,k;
	Branch br;
	
	cin >> n >> q;
	
	for(long  i = 1; i < n; i++){
		cin >> br.left >> br.right;
		A.push_back(br);
	}
	
	for(long i = 0; i < q; i++){
		cin >> k;
		for(long j = 0; j < k; j++){
			cin >>  input;
			B.push_back(input);
		}
		Solve(n);
		B.clear();
	}
}
