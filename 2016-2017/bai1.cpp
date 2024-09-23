#include <iostream>
using std:: cin;
using std:: cout;
using std:: endl;

int uoc (int n)
{
	int count;
	
	count = 0;
	
	for(int i = 1; i <= n; i++){
		if ( n % i == 0 ){
			count = count + 1;		
		}
	}
	return count;
}

int main ()
{
	int count,L,R,max,tam;
	
	cout << " Nhap L: ";
	cin >> L;
	cout << " Nhap R: ";
	cin >> R;
	max = 0;
	tam = 0;
	
	for (int i = L; i <= R; i++){
		count = uoc(i);
		if (max < count ){
			max = count;
			tam = i;
		}
	}
	
	cout << " So nhieu uoc nhat la " << tam << " va so luong uoc cua no la " << max;
}
