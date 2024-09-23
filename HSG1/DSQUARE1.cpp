#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

vector<long> A;

bool IsDsquare (long long n)
{
	long long tam;
	
	
	for (long i = 2; i  < sqrt(n)+1; i++){
		tam = i * i;
		if (n % tam == 0){
//			cout << " n = " << n << " " << " tam = " << tam << endl;
			A.push_back(tam);
			return true;
		}	
	}
	
	return false;
}

bool CheckDivisor(long long n)
{
	bool result = false;
	
	if (A.size() == 0){
		return result;
	}
	for (long i = 0; i < A.size(); i++){
		if (n % A[i] == 0){
			result = true;
			return result;
		}
	}
	
	return result;
}

bool Check(long a, long b)
{
	long long n = a * b;
	bool check;
	
//	cout << "n = " << n << endl;
	
	check = CheckDivisor(n);
	
	if (check == true){
		return true;
	}
	if(check == false){
		if (IsDsquare(n) == true){
			return true;
		}
		else{
			return false;
		}	
	}	
}

void Solve(long l , long r)
{
	long count = 0;
	
	if (l == 1){
		l++;
	}
	
	for (long i = l; i < r; i++){
		for (long j = i+1; j <= r; j++){
			if (Check(i,j) == true){
				count++;
//				cout << " count = " << count << endl;
			}
		}
	}
	
	cout << count;
	out << count;

}

int main()
{
	long l,r;
	
	inp.open("C:\\HSG1\\DSQUARE.INP");
	out.open("C:\\HSG1\\DSQUARE.OUT");
	
	inp >> l;
	inp >> r; 
	
	A.push_back(4);
	A.push_back(9);
	A.push_back(25);
	A.push_back(49);
	
	
	Solve(l,r);
	
	inp.close();
	out.close();
}
