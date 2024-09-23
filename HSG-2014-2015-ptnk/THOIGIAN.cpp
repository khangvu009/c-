#include<iostream>
#include<fstream>

using namespace std;

ifstream inp;
ofstream out;

void Convert(int n,int &vl, int &hz){
	switch (n){
		case 0:{
			vl += 4;
			hz += 2;
			break;
		}
		case 1:{
			vl += 1;
			break;
		}
		case 2:
		case 3:
		case 5:{
			vl += 2;
			hz += 3;
			break;
		}
		case 6:
		case 9:{
			vl += 3;
			hz += 3;
			break;
		}
		case 7:{
			vl += 1;
			hz += 1;
			break;
		}
		case 8:{
			vl += 4;
			hz += 3;
			break;
		}
	}
}

void Count(int &vl, int &hz, int h, int m, int m1){ 
	while(h >= 0){
		Convert(h%10,vl,hz);
		h = h / 10;
		if (h == 0){
			break;
		}
	}
	Convert(m,vl,hz);
	Convert(m1,vl,hz);
}

void Solve(long n, long m){
	bool flag = true;
	int vl = 0,hz = 0,hour;
	string minute = "";
//	hz ngang, vl dung
	cout << "n = " << n << "m = " << m << endl;
	for(int h = 0; h <= 23; h++){
		if (!flag){
			break;
		}
		for(int m1 = 0; m1 <= 5; m1++){
			if (!flag){
					break;
				}
			for(int m2 = 0; m2 <= 9; m2++){
				Count(vl,hz,h,m2,m1);
				if (vl == n && hz == m){
					hour = h;
					minute = minute + (char)(m1 + (int)('0'));
					minute = minute + (char)(m2 + (int)('0'));
					flag = false;
					break;
				}
				cout << "h = " << h << " m = " << m1 << m2 << " vl = " << vl << " hz = " << hz << endl;
				vl = 0;
				hz = 0;
			}
		}
	}
	cout << hour << ":" << minute;
}

int main(){
	int n,m;
	
	inp.open("C:\\bt_c++\\HSG-2014-2015-ptnk\\THOIGIAN.INP");
	out.open("C:\\bt_c++\\HSG-2014-2015-ptnk\\THOIGIAN.OUT");
	
	inp >> n >> m;
	
	Solve(n,m);	
	
	inp.close();
	out.close();
}
