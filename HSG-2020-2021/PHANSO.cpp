#include<bits/stdc++.h>

using namespace std;

ifstream inp; 
ofstream out;


struct Division{
	long equal;
	long divisor;	
};

vector<long> A,B;

void Sort (){
	
	for (long i = 0; i < A.size()-1; i++){
		for(long j = i+1; j < A.size(); j++){
			if (A[j] <= A[i]){
				long temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				long temp1 = B[i];
				B[i] = B[j];
				B[j] = temp1;
			}
		}
	}
}

long UCLN (long a, long b){
	if (a == 0) return b;
	return UCLN(b % a, a);
}

long long BCNN(long  a, long b){
	long ucln = UCLN(a,b);
	long bcnn = a*b / ucln;
	
	return bcnn;	
}

long long BcnnOfNumbers(){
	long long tam = 1,bcnn;
	
	for (long i = 0; i < B.size(); i++){
		bcnn = BCNN(tam,B[i]);
		tam = bcnn;
	}
	
	return bcnn;
}

vector<long> QuiDong (long long bcnn, vector<Division> &D){
	vector<long> C;
	Division Divide;
	long tam;
	
	for(long i = 0; i < A.size(); i++){
		tam = A[i] * (bcnn / B[i]);
		C.push_back(tam);
		Divide.equal = A[i];
		Divide.divisor = bcnn / B[i];
		D.push_back(Divide);
	}
	
	return C;
}

vector<long> AddIndexsToVector(vector<long> C, vector<Division> D){
	vector<long> E;
	
	for (long i = 0; i < C.size(); i++){
		for (long j = 0; j < D.size(); j++){
			if (C[i] / D[j].divisor == D[j].equal){
				E.push_back(j);
				D[j].divisor = 1;
				break;
			}
		}
	}	
	
	return E;
}

vector<long> Indexs (long long bcnn,vector<long> &C){
	vector<long> E;
	vector<Division> D;
	
	C = QuiDong(bcnn,D);
	
	for (long i = 0; i < C.size(); i++){
		cout << C[i] << " ";
	}
	cout << endl;
	
	for (long i = 0; i < D.size(); i++){
		cout << "divisor = " << D[i].divisor << " equal = " << D[i].equal << endl;
	}
	sort(C.begin(),C.end());
	
	E = AddIndexsToVector(C,D);
	
	for (long i = 0; i < E.size(); i++){
		cout << E[i] << " ";
	}
	cout << endl;
	return E;
}

void Print(vector<long> E){
	for (long i = 0; i < E.size(); i++){
		if (i <= E.size()-1) cout << A[E[i]] << " ";
		else cout << A[E[i]];
	}
	cout << endl;
	for (long i = 0; i < E.size(); i++){
		if (i <= E.size()-1) cout << B[E[i]] << " ";
		else cout << B[E[i]];
	}
}

void Solve(){
	vector<long> C,D,E;
	
	Sort();
	for (long i = 0; i < A.size(); i++){
		cout << A[i] << " ";
	}
	cout << endl;
	for (long i = 0; i < B.size(); i++){
		cout << B[i] << " ";
	}
	cout << endl;
	long long bcnn = BcnnOfNumbers();
	cout << "bcnn = " << bcnn << endl; 
	E = Indexs(bcnn,C);
	Print(E);	
}

int main(){
	long n,input;

	inp.open("C:\\bt_c++\\HSG-2020-2021\\PHANSO.INP");	
	out.open("C:\\bt_c++\\HSG-2020-2021\\PHANSO.OUT");
	
	inp >> n;
	
	for (long i = 0; i < n; i++){
		inp >> input;
		A.push_back(input);
	}
	for (long i = 0; i < n; i++){
		inp >> input;
		B.push_back(input);
	}	
	
	for (long i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
	for (long i = 0; i < n; i++){
		cout << B[i] << " ";
	}
	cout << endl;
	
	Solve();
	
	inp.close();
	out.close();
}
