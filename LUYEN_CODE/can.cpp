#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <vector>

const long long Zero = -30000;

using namespace std;

long long Tim_x(long long n)
{
	long long mu;
	long long i = 0;
	
	while (true){
		mu = pow(3,i);
		if (mu >= n){
			return i;
		}
		
		i++;
	}	
	
	return 0;
} 

void Tim_3_so (long long X, long long n, long long & mu1, long long & mu2, long long &tb)
{
	mu1 = pow(3,X-1);
	mu2 = pow(3,X);
	tb = (mu1 + mu2) / 2;
}

long long Tim_huong_di (long long mu1, long long mu2, long long tb, long long n)
{
	long long a = abs((n-mu1));
	long long b = abs((n-mu2));
	long long c = abs((n-tb));
	long long huong;
	
	if (a <= b && a <= c){
		huong = mu1;
	}
	if (b <= a && b <= c){
		huong = mu2;
	}
	if (c <= a && c <= b){
		huong = tb;
	}
	
	return huong;
} 

void Doi_dau(vector<long long> &Temp)
{
	long long len = Temp.size();
	
	for(long long i = 0; i < len; i++){
		if (Temp[i] == -Zero){
			Temp[i] = 0;
		}
		else if (Temp[i] == 0){
			Temp[i] = Zero;
		}
		else{
			Temp[i] = -1 * Temp[i];
		}
	}
}

long long Xu_li (long long n, vector<long long> &Temp, long long &n1)
{
	long long X;
	long long kt_am_duong = 1;
	long long mu1,mu2,tb,huong;
	
	Temp.clear();
	
	if (n < 0){
		kt_am_duong = -1;
		n = -n;
	}
	
	X = Tim_x(n);
	Tim_3_so(X,n,mu1,mu2,tb);
	huong = Tim_huong_di(mu1,mu2,tb,n);
		
	if (huong == mu1){
		Temp.push_back(X-1);
		n1 = n-mu1;
	}
	if (huong == mu2){
		Temp.push_back(X);
		n1 = n-mu2;
	}
	if (huong == tb){
		Temp.push_back(X);
		if (X-1 >0){
			Temp.push_back(-1*(X-1));
		}
		else{
			Temp.push_back(Zero);
		}
		n1 = n-(mu2-mu1);
	}	
	
	if (kt_am_duong == -1){
		Doi_dau(Temp);
		n1 = -n1;
	}
	
	return X;
}

void Print (vector<long long> &A, long long X)
{
	long long count = 0;
	
	for (long long i = 0; i < A.size(); i++){
		if (A[i] < 0){
			count = 1;
			if (A[i] == Zero){
				cout << 0 << " ";
			}
			else{
				cout << -A[i] << " ";
			}
		
		}
	}
	if (count == 0){
		cout << X+1;
	}
	cout << endl;
	
	for (long long i = 0; i < A.size(); i++){
		if (A[i] >= 0){
			if (A[i] == -Zero){
				cout << 0 << " ";
			}
			else{
				cout << A[i] << " ";
			}
		}
	}	
	
	if (count == 0){
		cout << X+1;
	}
}

void Print1 (vector<long long> &A, long long X)
{
	long long count = 0;
	
	for (long long i = 0; i < A.size(); i++){
		if (A[i] < 0){
			count = 1;
			if (A[i] == Zero){
				cout << "3^" << 0 << "+";
			}
			else{
				cout  << "3^" <<  -A[i] << "+";
			}
		
		}
	}
	if (count == 0){
		cout  << "3^" << X+1 << "+";
	}
	cout << endl;
	
	for (long long i = 0; i < A.size(); i++){
		if (A[i] >= 0){
			cout  << "3^"<< A[i] << "+";
		}
	}	
	
	if (count == 0){
		cout  << "3^" << X+1 << "+";
	}
}

void Solve (long long n)
{	
	vector<long long> A,Temp;
	long long n1,X;
	long long X1 = 0;
	
	while (n != 0){
		X = Xu_li(n,Temp,n1);
		if (X1 == 0){
			X1 = X;
		}
		n = n1;
		A.insert( A.end(), Temp.begin(), Temp.end() );
	}
	
	Print(A,X1);
}

int main()
{
	long long n;
	
	cin >> n;
	
	Solve(n);
}

