#include <iostream>

using namespace std;

long long UCLN (long long a, long long b)
{
	if(b == 0){
		return a;
	}	
	
	return UCLN(b,a%b); 
}


long long BCNN(long long a, long long b)
{
	long long ucln = UCLN(a,b);
	long long bcnn = a*b / ucln;
	cout << "-- bcnn = " << bcnn << endl;
	return bcnn;
}

long long QD(long long &a, long long &a1, long long &b, long long &b1)
{
	long long bcnn = BCNN(a1,b1);
	
	a = a * (bcnn / a1);
	a1 = a1 * (bcnn / a1);
	b = b *(bcnn / b1);
	b1 = b1 * (bcnn / b1);
//	cout << "-- a = " << a << "-- a1 = " << a1 << "-- b = " << b << "-- b1 = " << b1 << endl;
	
}

long long Sum_2_ps (long long &a, long long &a1, long long &b, long long &b1)
{
	long long sum = 0;
	
	QD(a,a1,b,b1);	
	sum = a+b;
	
//	cout << "-- a = " << a << " -- b = " << b << "-- sum = " << sum << endl;
	return sum;
	
}

void Rut_gon (long long &a, long long &a1, long long &b, long long &b1, long long &tu, long long &mau)
{
	long long sum = Sum_2_ps(a,a1,b,b1);
	long long ucln = UCLN(sum,b1);
	
//	cout << "-- sum = " << sum << "-- b1 = " << b1 << endl; 
	tu =  sum / ucln;
	mau =  b1 / ucln;
}

int main()
{
	long long a,a1,b,b1,tu,mau;

	cin >> a;
	cin >> a1;
	cin >> b;
	cin >> b1;
	
//	cout << a << " " << a1 << " " << b << " " << b1 << endl;
	Rut_gon(a,a1,b,b1,tu,mau);
	
	cout << tu << " " << mau;
}
