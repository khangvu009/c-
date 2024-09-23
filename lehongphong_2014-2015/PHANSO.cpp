#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int Times (int len,int phan_nguyen)
{
	int result = 1;
	for (int i = 1; i <= len; i++){
		result = result * 10;
	}	
	return result;
}

int Divisor (int phan_du,int len,int phan_nguyen)
{
	int max;
	int times;
	
	times = Times(len,phan_nguyen);
	if (phan_du > times){
		max = phan_du;
	}
	else{
		max = times;
	}
	
	for (int i = max; i >= 1; i--){
		if (phan_du % i == 0 && times % i == 0){
			return i;
			break;
		}
	}
}

int Decimal_to_int (int len,int phan_nguyen, string str)
{
	int result = 0;
	int phan_du = 0;
	int times;
	
	for (int i = 0; i < len; i++){
		phan_du = phan_du * 10 + ((int)str[i] - '0');
	}	
	
	times = Times(len,phan_nguyen);
	result = phan_nguyen * times + phan_du;
	
	return result;
}

int Solve_Fraction (string &str, int phan_nguyen,int *result,int *result1)
{
	int len = 0;
	int decimal,divisor;
	int times;
	len = str.length();
	
	times = Times(len,phan_nguyen);
	decimal = Decimal_to_int(len,phan_nguyen,str);
	divisor = Divisor(decimal,len,phan_nguyen);
	*result = decimal / divisor;
	*result1 = times / divisor;
	
	
}

int main()
{
	ifstream phan_so_inp;
	phan_so_inp.open("C:\\bt_c++\\lehongphong_2014-2015\\PHANSO.INP");
	ofstream phan_so_out;
	phan_so_out.open("C:\\bt_c++\\lehongphong_2014-2015\\PHANSO.OUT");
	string str;
	int result1 = 0;
	int result = 0;
	int phan_nguyen;
	
	phan_so_inp >> phan_nguyen;
	phan_so_inp >> str;
	
	Solve_Fraction(str,phan_nguyen, &result, &result1);
	
	phan_so_out << result << " " ;
	phan_so_out << result1;
	
	phan_so_inp.close();
	phan_so_out.close();
}

