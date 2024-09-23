#include <iostream>
#include <fstream>

using namespace std;
const int  MAX_SIZE = 255;

int Boi_11 (int digit1, int digit2, int digit3,char *A)
{
	bool result = false;
	int sum = 0;
	int combine_digit = 0;
	
	int Idigit1 = (int)A[digit1] - '0';
	int Idigit2 = (int)A[digit2] - '0';
	int Idigit3 = (int)A[digit3] - '0';
	
	sum = Idigit1 + Idigit3;
	combine_digit = ((Idigit1 * 10) + Idigit2) * 10 + Idigit3;
	cout << sum << " ------- " << combine_digit << endl;
	
	if (sum == Idigit2 && combine_digit % 11 == 0){
		result = true;
	}
	
	return result;
} 

int Solve_max_case (char *A, int num_element)
{
	bool result;
	int count = 0;
	
	for(int i = 0; i < num_element-2; i++){
		result = Boi_11(i,i+1,i+2,A);
		if(result == true){
			count++;
			cout << "-----------------------------------------" << count << endl;
		}
	}
	
	return count;
}

int main()
{
	char A[MAX_SIZE];
	int num_element = 0;
	int result = 0;
	ifstream boi_so_inp;
	boi_so_inp.open("C:\\bt_c++\\lehongphong_2014-2015\\BOISO.INP");
	ofstream boi_so_out;
	boi_so_out.open("C:\\bt_c++\\lehongphong_2014-2015\\BOISO.OUT");
	
	while (num_element < MAX_SIZE && boi_so_inp >> A[num_element]){
		num_element++;
	}

	result = Solve_max_case (A,num_element);
	
	boi_so_out << result;
	boi_so_inp.close();
	boi_so_out.close();
}
