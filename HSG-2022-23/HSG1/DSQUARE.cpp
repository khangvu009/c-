#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

bool IsDsquare (long long n)
{
	long long tam;
	
	
	for (long i = 2; i  < sqrt(n)+1; i++){
		tam = i * i;
		if (n % tam == 0){
			return true;
		}	
	}
	
	return false;
}

bool Check(long a, long b)
{
	long long n = a * b;
	
	if (IsDsquare(n) == true){
		return true;
	}
	else{
		return false;
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
//				cout << i << " " << j << endl;
			}
		}
	}
	
//	cout << count;
	out << count;

}

int main()
{
	long l,r;
	
	inp.open("C:\\HSG1\\DSQUARE.INP");
	out.open("C:\\HSG1\\DSQUARE.OUT");
	
	inp >> l;
	inp >> r; 
	
	Solve(l,r);
	
	inp.close();
	out.close();
}
