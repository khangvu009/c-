#include<iostream>
#include<fstream>

using namespace std;

int kq (int n , int k)
{
	int i = 1;
	int five = 1;
	int s;
	int ten = 1;
	
	if(k > 0){
		while (i <= k){
			five = five * 10 + 5;
			ten = ten * 10;
		}
		
		s = five % ten;
		if (s > n){
			return s;
		}
		
		else if ( five > n){
			return five;
		}
		else{
			while(s <= n){
				s = 
			}
		}
	}
}

int main()
{
	ifstream may_man_inp;
	may_may_inp.open("C:\\bt_c++\\2019-2020\\MAYMAN.INP");
	ofstream may_man_out;
	may_may_out.open("C:\\bt_c++\\2019-2020\\MAYMAN.OUT");
	
	int n,k;
	
	may_may_inp >> n;
	may_man_inp >> k;
	
	may_may_inp.close();
	may_may_out.close();
}
