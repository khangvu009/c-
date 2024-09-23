#include<iostream>
using std:: cin;
using std:: cout;
using std:: endl;
int main()
{
	int	n,a;
	long double tong,tam;
	cout << " Nhap n: ";
	cin >> n;
	a = 2;
	tam = 0; 		
	tong = 0;
	for	(int x = 1; x <= n; x = x + 1)	
	{
		tam = 1;
		tong = tong + tam / (a * x);
		cout << a << endl;
		cout << x << endl;
		cout << tong << endl;
		a = a + 1;	
	}
}
