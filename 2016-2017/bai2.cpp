#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX_SIZE = 100;

int doi1(char n)
{
	int convert;
	
	convert = (int)(n)-48;
	return convert;
}

int doi_slm (char c)
{
	int n = 0;
	switch(c){
		case 'I':
			n = 1;
			break;
		case 'V':
			n = 5;
			break;
		case 'X':
			n = 10;
			break;
		case 'L':
			n = 50;
			break;
		case 'C':
			n = 100;
			break;
		case 'D':
			n = 500;
			break;
		case 'M':
			n = 1000;
			break;
			
		default:
			n = 0;
			
	}
	return n;
}

int main() {
    std::string str;
    int tong = 0;
    int n, m,num1;

    std::ifstream hon_hop_inp("C:\\bt_c++\\2016-2017\\HONHOP.INP.txt");
    std::ofstream hon_hop_out("C:\\bt_c++\\2016-2017\\HONHOP.OUT.txt");

    while (hon_hop_inp >> str) {
    }

    int cd = str.length();

    for (int i = 0; i < cd; i++) {
        if (i % 2 == 0) {
            num1 = doi1(str[i]);
        } 
		if (i % 2 == 1 ) {
			n = doi_slm(str[i]);
			if (i+2 > cd){
				tong = tong + (num1 * n);
				cout << n << " " << tong << endl;
			}
			else{
			
				m = doi_slm(str[i+2]);

                if (n >= m) {
                    tong = tong + (num1 * n );
                } 
				else {
                    tong = tong - (num1 * n);
                }
                cout << n  << " " << m << " " << tong << endl;     
            }
        }
    }
    hon_hop_out << tong;
    hon_hop_inp.close();
    hon_hop_out.close();
}
