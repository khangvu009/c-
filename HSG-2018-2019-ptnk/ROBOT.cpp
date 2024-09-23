#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

struct point{
	long s;
	long e;
	long d;
};
vector<point> A;
vector<long> B;

void CreateV(long l, long r){
	B.clear();
	
	for(long i = l; i <= r; i++){
		B.push_back(0);
	}
}

void Sort(){
	point temp;
	
	for(long i = 0; i < A.size()-1; i++){
		for(long j = i + 1; j < A.size(); j++){
			if(A[i].d < A[j].d){
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
} 

bool IsFull(point p,long qc, long &count){
	for(long i = p.s-qc; i <= p.e-qc; i++){
		if(B[i] == 0){
			count++;
		}
		B[i]++;
	}
	
//	cout << "size = " << B.size() << " count = " << count << endl;
	if(count == B.size()){
		return true;
	}
	return false;
}

bool Check(long removeI,long qc){
	long count = 0;
	
	for(long i = 0; i < A.size(); i++){
		if(i != removeI){
			if(IsFull(A[i],qc,count)){
				cout << endl;
				for(long i = 0; i < B.size(); i++){
					cout << B[i] << " ";
				}
				cout << endl;
				return true;
			}
		}
	}
//	cout << endl;
//	for(long i = 0; i < B.size(); i++){
//		cout << B[i] << " ";
//	}
//	cout << endl;
	
	return false;
}

void Solve(long l, long r){
	long qc = l, i = 0,result;
	
	CreateV(l,r);
	Sort();
	
	for(long i = 0; i < A.size(); i++){
		cout << A[i].s << " " << A[i].e << endl;
	}
	
	while(!Check(i,qc)){
		CreateV(l,r);
		i++;
		if (i >= r){
			cout << "khong co" << endl;
			A[i].d = -1;
			break;
		}
	}
	
	result = A[i].d;
	
	cout << result;
}

int main(){
	long n,l,r;
	point p;
	
	inp.open("C:\\bt_c++\\HSG-2018-2019-ptnk\\ROBOT.INP");
	out.open("C:\\bt_c++\\HSG-2018-2019-ptnk\\ROBOT.OUT");
	
	inp >> n >> l >> r;
	
	for(long i = 0; i < n; i++){
		inp >> p.s >> p.e;
		p.d = p.e-p.s;
		if(p.e > r){
			p.e = r;
		}
		A.push_back(p);
	}
	
	for(long i = 0; i < A.size(); i++){
		cout << A[i].s << " " << A[i].e << endl;
	}
	cout << endl;
	Solve(l,r);
	
	inp.close();
	out.close();
}
