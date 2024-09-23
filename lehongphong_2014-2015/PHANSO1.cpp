#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int Tim_mau (string str_du)
{
	int result = 1;
	int len = str_du.length();
	for (int i = 1; i <= len; i++){
		result = result * 10;
	}	
	return result;
}

int Tim_ucln (int a, int b)
{
	if(b == 0){
		return a;
	}	
	return Tim_ucln(b, a % b);
} 


int Solve (int phan_nguyen, string str_du, int &result_tu_rut_gon, int &result_mau_rut_gon)
{
	int tu,mau;
	int num_pd = atoi(str_du.c_str());
	int ucln;

	mau = Tim_mau(str_du);
	tu = phan_nguyen * mau + num_pd;
	ucln = Tim_ucln(tu,mau);
	cout << ucln << "---------" << tu << "------------" << mau<<endl;
	result_tu_rut_gon = tu / ucln;
	result_mau_rut_gon = mau / ucln;
	return 0;
}

int main()
{
	ifstream phan_so_inp;
	phan_so_inp.open("C:\\bt_c++\\lehongphong_2014-2015\\PHANSO.INP");
	ofstream phan_so_out;
	phan_so_out.open("C:\\bt_c++\\lehongphong_2014-2015\\PHANSO.OUT");
	string str_du;
	int result_tu_rut_gon = 0;
	int result_mau_rut_gon = 0;
	int phan_nguyen;
	
	phan_so_inp >> phan_nguyen;
	phan_so_inp >> str_du;
	
	Solve(phan_nguyen,str_du, result_tu_rut_gon, result_mau_rut_gon);
	
	phan_so_out << result_tu_rut_gon << " " ;
	phan_so_out << result_mau_rut_gon;
	
	cout << result_tu_rut_gon << " " << result_mau_rut_gon;
	
	phan_so_inp.close();
	phan_so_out.close();
}
