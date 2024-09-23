	#include<iostream>
	using std:: cin;
	using std:: cout;
	using std:: endl;
	int main()
	{
		int n;
		double tong,tam;
		cout << " Nhap n: ";
		cin >> n;
		tong = 0;
		tam = 1;
		for (int x = 1;  x <= n; x = x + 1)
		{
			tam = tam / x;
			tong = tong + tam;
		}
		cout << " Tong = " << tong;
	}
