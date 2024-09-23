#include<bits/stdc++.h>

using namespace std;

ifstream inp;
ofstream out;

void Solve(long x, long y, long x1, long y1){
	long dis = abs(x1 - x);
	long dis1 = abs(y1 - y);
	long result = max(dis,dis1);
	
	out << result;
}

int main(){
	long x,y,x1,y1;
	
	inp.open("ROBOT.INP");
	out.open("ROBOT.OUT");
	
	
	inp >> x >> y >> x1 >> y1;
	
	Solve(x,y,x1,y1);
	
	inp.close();
	out.close();
}
