#include<iostream>
using namespace std;

int main ()
{
	int n,max,hieu;
	
	cout << " Nhap n: ";
	cin >> n;
	max = 0;
	
	for (int i = 2; i < n; i++ ){
		if (n % i == 0){
			max = i;
		}
	}	
	
	hieu = n - max;
	
	cout << "N=" << n << endl;
	cout << "Hieu so giua N va uoc so lon nhat: " << hieu;
}
