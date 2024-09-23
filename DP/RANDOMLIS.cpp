#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include<fstream>

using namespace std;

ofstream out;

int LISLength(const vector<int>& nums) {
    int n = nums.size();
    vector<int> lis(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    return *max_element(lis.begin(), lis.end());
}

vector<int> LIS(const vector<int>& nums) {
    int n = nums.size();
    vector<int> lisLength(n, 1);
    vector<int> prevIndex(n, -1);
    int maxLengthIndex = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && lisLength[i] < lisLength[j] + 1) {
                lisLength[i] = lisLength[j] + 1;
                prevIndex[i] = j;
            }
        }
        if (lisLength[i] > lisLength[maxLengthIndex]) {
            maxLengthIndex = i;
        }
    }

    vector<int> lis;
    while (maxLengthIndex != -1) {
        lis.push_back(nums[maxLengthIndex]);
        maxLengthIndex = prevIndex[maxLengthIndex];
    }

    reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
	long n = 50000;
	out.open("C:\\bt_c++\\DP\\LIS.INP");
    // Seed the random number generator
    srand(time(0));

    // Generate a random array of 1000 elements
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = rand() % n; // Random numbers between 0 and 999
    }

	out << n << endl;
    for (int num : nums) {
        out << num << " ";
    }
    cout << endl;
	out.close();
	
	
	// Calculate the length of LIS
    int lisLength = LISLength(nums);
    cout << "Length of LIS: " << lisLength << endl;

    // Calculate the LIS itself
    vector<int> lis = LIS(nums);
    cout << "LIS: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

