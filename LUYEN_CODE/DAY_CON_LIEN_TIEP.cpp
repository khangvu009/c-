#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long check_day_equal (long n, long *A, long sum,long *Index,long &j, long so_day_con)
{
	long tam = 0;
	long count = 0;
	long tb = sum / so_day_con;
	long tam1 = tb;
	bool result = false;
	
//	cout << "--tb = " <<  tb << endl;
	for (long i = 0; i < n; i++){
//		cout << "--index = " << i << endl;
		tam1 = tam1 - A[i];
//		cout << "----tam1 = " << tam1 << endl;
		if ( tam1 == 0 ){
			if (i == n - 1){
//				cout << "----phan tich duoc" << endl;
				result =  true;
			}
			
			Index[j] = i+1;
//			cout << "---- j = " << j << endl;
			j++;
			tam1 = tb;
		}
		if (tam1 > 0){
//			do nothing
		}
		
		if (tam1 < 0){
//			cout << "----phan tich ko dc " << endl;
//			break;
		}
	}
	
	return result;
//	cout << tb  << "--------" << so_day_con << "-----" << count << endl;
//	return count;
}

long divide_day (long n , long *A,long sum, long*Index, long &j)
{
	long tb;
	bool result;
	
	for (long i = n; i >= 1; i--){
		j = 0;
//		cout << "phan tich :" << i << endl;
		tb = sum % i;
		if (tb == 0){
			result = check_day_equal(n,A,sum,Index,j,i);
			if (result == true){
				break;
			}
		}
	}
	
	return result;
}
	
long Sum  (long n ,long *A)
{
	long result = 0;
	
	for (long i = 0; i < n; i++){
		result = result + A[i];
	}
	
	return result;
}
 
long Solve (long n, long *A,long *Index, long &j)
{
	long tong; 
	bool result;
	
	tong = Sum(n,A);
	cout << tong << endl;
	result = divide_day(n,A,tong,Index,j);
	return result;	
}

int main()
{
	
	ifstream day_bang_nhau_inp;
//	day_bang_nhau_inp.open("C:\\bt_c++\\LUYEN_CODE\\DBN.INP");

	long A[100],n,Index[100];
	long j = 0;
	bool result;
	long num_element = 0;
	long index = 0;
//	day_bang_nhau_inp >> n;
//	while (num_element < 100 && day_bang_nhau_inp >> A[num_element] ){
//		num_element++;
//	}
	cin >> n;
	for (long i = 0; i < n; i++) {
		cin >> A[i];
	}
	
	for (long i = 0; i <n; i++){
		Index[i] = 0;
	}
	result = Solve(n,A,Index,j);
	
	cout << j << endl;
	if (result == true){
		for (long i = 0; i < j; i++){
			cout << Index[i];
			if (i < j-1){
				cout << " ";
			}
		}	
	}
	else{
		cout << n;
	}

}
