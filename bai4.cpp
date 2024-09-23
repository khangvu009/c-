#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;
using std:: cout;
using std:: endl;
const int MAX_SIZE = 100;

bool so_chinh_phuong (int n){
	bool bReturn;
	bReturn = false;
	double dCan;
	dCan = sqrt(n);
	if ( round(dCan) * round(dCan) == n	 ){
		return 1;
	}
	return 0;
}

int tao_mang (int n){
	int numRan;
	
	// open file to write
	std::ofstream inputFile;
    inputFile.open("C:\\bt_c++\\input.txt");
    inputFile << n << endl;
    
	// create rando numbers
	for (int i = 1; i <= n; i++){
		numRan = (int)rand() % 100 + 1;
		inputFile << numRan << endl;
	}
	
	inputFile.close();
}

int main() {
	
	srand((unsigned int)time(NULL));
	
    int numbers[MAX_SIZE];
    int numElements = 0;
	int n;
	bool tem;
	
	tao_mang (100	);
    std::ifstream inputFile;
    inputFile.open("C:\\bt_c++\\input.txt");
    std::ofstream outputFile;
	outputFile.open("C:\\bt_c++\\output.txt");

    if (!inputFile.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }
    
	inputFile >> n;
	
    while (numElements < MAX_SIZE && inputFile >> numbers[numElements])  {
    	if (so_chinh_phuong(numbers[numElements]) == 1 ){
    		std::cout << numbers[numElements] << std::endl;
    		outputFile << numbers[numElements] << std::endl;
		}
        numElements++;
    }

    inputFile.close();

    // Use the numbers array as needed
	
//	for(int i = 0; i < numElements; i++){
//		outputFile << numbers[i] << endl;
//	}
	
	outputFile.close();
	
    return 0;
}

