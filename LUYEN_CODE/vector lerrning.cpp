#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> my_vector(5,5);
	
	for (int i : my_vector){
		cout << i << " ";
	}
}
