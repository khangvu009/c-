#include <bits/stdc++.h>

using namespace std;

ifstream market_inp;
ofstream market_out;

struct Market{
	long weight;
	long value;
};

int main()
{
	long n,k;
	Market inp;	
	vector<Market> A;
	
	market_inp.open("C:\\bt_c++\\de_hsg\\MARKET.INP");
	market_out.open("C:\\bt_c++\\de_hsg\\MARKET.OUT");
	
	market_inp >> n;
	market_inp >> k;
	
	for (long i = 0; i < n; i++){
		market_inp >> inp.weight;
		market_inp >> inp.value;
		A.push_back(inp);
	}
	
	market_inp.close();
	market_out.close();
}
