#include <iostream>

using namespace std;


long UCLN (long  a, long  b)
{
	if (b == 0){
		return a;
	}	

	return UCLN(b,a%b);
}

long long BCNN (long a, long  b)
{
	long long bcnn;
	long ucln;

	ucln = UCLN(a,b);
	bcnn = a*b / ucln;
	return bcnn;
}

void truy_van (long n, long q, long &i, long *A)
{
	for(long j = 0; j < n; j++){
		if (A[j]  == A[i]){
			A[j] = A[j] * A[i+1];
			i = i + 2;
			break;
		}
	}

}

long long Bcnn_cua_day (long *A , long n)
{
	long long bcnn = BCNN(A[0],A[1]);
	
	for(long i = 2; i < n; i++){
		bcnn = BCNN(bcnn,A[i]);
	}
	
	return bcnn;
}

void Solve(long  n, long  q, long  *A)
{
	long i = n;
	long long bcnn;
	
	while(true){
		if (i+2 > n+q*2){
			break;
		}
		truy_van(n,q,i,A);
		bcnn = Bcnn_cua_day(A,n);
		bcnn = bcnn % (1000000000+7);
		cout << bcnn << endl;
	}
}

int main()
{
	long n,q;
	long A[100000];

	cin >> n;
	cin >> q;

	for(long i = 0; i < n+q*2; i++){
		cin >> A[i];
	}	

	Solve(n,q,A);
}
