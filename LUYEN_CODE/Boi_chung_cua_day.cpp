#include <iostream>

using namespace std;


long long UCLN (long long a, long long b)
{
	if (b == 0){
		return a;
	}	

	return UCLN(b, a % b);
}

long long BCNN (long long a, long long b)
{
	long long bcnn;
	long long ucln;
	long long temp;

	ucln = UCLN(a,b);
	temp = (a / ucln);
	bcnn =  temp*b;
	return bcnn;
}

void truy_van (long long index, long long times, long long *A)
{
	A[index] = A[index] * times;	

}

long long Bcnn_cua_day (long long *A , long long n)
{
	long long bcnn = A[0];
	
	for(long long i = 1; i < n; i++){
		bcnn = BCNN(bcnn,A[i]);
	}
	
	return bcnn;
}

int main()
{
	long long n,q,times,index;
	long long A[100000];
	long long Q[100000];

	cin >> n;
	cin >> q;

	for(long long i = 0; i < n; i++){
		cin >> A[i];
	}	

	for(long long i = 0; i < q; i++){
		cin >> index;
		cin >> times; 
		truy_van(index-1,times,A);
		Q[i] = Bcnn_cua_day(A,n);
		Q[i] = Q[i] % (1000000000+7);
	}
	
	for(long long i = 0; i < q-1; i++){
		cout << Q[i] << endl;
	}
	cout << Q[q-1];
}
