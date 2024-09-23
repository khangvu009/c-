#include <bits/stdc++.h>

using namespace std;

ifstream vdl_inp;

struct P{
	int c;
	int d;
}; 

struct Path{
	vector<P> arrP;
	int len;
	P end;	
};

int A[100][100];
int minLen = 0;
queue<Path> Paths;
Path MinPa;
vector <P> Directions {P{0,-1},P{-1,-1},P{-1,0},P{-1,1},P{0,1},P{1,1},P{1,0},P{1,-1}};
bool check (Path pa, P p)
{
	for (int i = 0; i < pa.arrP.size(); i++){
		if (pa.arrP[i].c == p.c && pa.arrP[i].d == p.d){
			return false;
		}
	}
	
	return true;
}

vector<P> Walk(Path pa, int slC, int slD)
{
	P p;
	vector<P> Ps;
	
	for (int i = 0; i < Directions.size(); i++){
		p.d = pa.end.d+Directions[i].d;
		p.c = pa.end.c+Directions[i].c;
		if (p.d >= 0 && p.d < slD && p.c < slC && p.c >= 0){ 
			if (check(pa,p) == true){
				Ps.push_back(p);
			}
		}
	}	
	return Ps;
}

void Loang(vector <P> Ps,Path pa, P endP)
{
	
	P p;
	Path Pn = pa;
	
	for (int i = 0; i < Ps.size(); i++){
		p.c = Ps[i].c;

		p.d = Ps[i].d;
		Pn.arrP.push_back(p);
		Pn.end = p;
		Pn.len += A[p.d][p.c];
		
		if (p.c == endP.c && p.d == endP.d){
			if (minLen == 0 || minLen > Pn.len){
				MinPa = Pn;
				minLen = Pn.len;
			}
		}
		Paths.push(Pn);
		Pn = pa;	
	}	
}

void Solve (int x, int y, P startP, P endP)
{
	int index = 0;
	vector<P> Ps;
	Path pa;
	P p;
	p = startP;
	pa.arrP.push_back(p);
	pa.end = p;
	pa.len = A[p.d][p.c];
	Paths.push(pa);
	
	while (Paths.size() > 0){
		pa = Paths.front();
		Paths.pop();
		Ps = Walk(pa,x,y);
		Loang(Ps,pa,endP);
	}
	cout << minLen << endl;
	int len = 0;
	
	for (int i = 0; i < MinPa.arrP.size(); i++){
		P p1;
		p1 = MinPa.arrP[i];
		len = len + A[p1.d][p1.c];
		cout << MinPa.arrP[i].d + 1 << "," << MinPa.arrP[i].c + 1 << " len = " << len <<endl;
	}
}

int main()
{
	int y,x,StartX,StartY,EndX,EndY;
	P startP, endP;
	vdl_inp.open("C:\\bt_c++\\de_hsg\\VDL.INP");
	
	vdl_inp >> y;
	vdl_inp >> x;
	vdl_inp >> startP.c;
	vdl_inp >> startP.d;
	vdl_inp >> endP.c;
	vdl_inp >> endP.d;
	
	
	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			vdl_inp >> A[i][j]; 
		}
	}
	
	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			cout << A[i][j] << " "; 
		}
		cout << endl;
	}
	
	startP.c--;
	startP.d--;
	endP.c--; 
	endP.d--; 
	Solve(x,y,startP,endP);		
	vdl_inp.close();
}
