#include <bits/stdc++.h>

using namespace std;

ifstream che_inp;
ofstream che_out;

struct point {
	int x;
	int y;	
};

struct square {
	vector<point> arrPoints;	
	int h;
	int intCase;
};

struct base {
	vector<square> arrSquare;	
};

long m,n;
vector<int> arrTree;
vector<int> arrCover;
int A[1000][1000];

void Input()
{
	int inp;
	
	che_inp >> m;
	che_inp >> n;
	
	for(int i = 0; i < n*m; i++){
		che_inp >> inp;
		arrTree.push_back(inp);	
	}	
	
}

square CreateOne (point p)
{
	square sq;
	
	sq.arrPoints.push_back(p);
	
	return sq;	
}


square CreateOneTwo (point p)
{
	square sq;
	
	sq.arrPoints.push_back(p);
	
	point p1;
	
	p1.y = p.y;
	p1.x = p.x + 1;
	
	sq.arrPoints.push_back(p1);
	
	return sq;	
}

square CreateTwoOne (point p)
{
	square sq;
	
	sq.arrPoints.push_back(p);
	
	point p1;
	
	p1.x = p.x;
	p1.y = p.y + 1;
	
	sq.arrPoints.push_back(p1);
	
	return sq;	
}

square CreateFour (point p)
{
	square sq;
	
	sq.arrPoints.push_back(p);
	
	point p1,p2,p3;

	p1.y = p.y + 1;
	p1.x = p.x;
	
	sq.arrPoints.push_back(p1);
	
	p2.y = p.y;
	p2.x = p.x + 1;
	
	sq.arrPoints.push_back(p2);
	
	p3.y = p.y + 1;
	p3.x = p.x + 1;
	
	sq.arrPoints.push_back(p3);
	
	return sq;	
}


square InitSquare (point p, int intCase)
{
	square sq;
	
	switch (intCase){
		case 1:{
			sq = CreateOne(p);
			break;
		}
		case 2:{
			sq = CreateOneTwo(p);
			break;
		}
		case 3:{
			sq = CreateTwoOne(p);
			break;
		}
		case 4:{
			sq = CreateFour(p);
			break;
		}
	}	
	
	return sq;
}


base InitBase()
{
	base ba;
	point p;
	square sq;
	
	int c = 0;
	int d = 0;
	int intCase;
	
	while (true){
		p.x = c;
		p.y = d;
		
		if (c + 1  < n - 1 && d + 1 < m-1){
			intCase = 4;
			sq = InitSquare(p,intCase);
			ba.arrSquare.push_back(sq);
			d = d + 2;
			if (d > m -1){
				d = 0;
				c = c + 2;
			}
			
		}
		else if (d == m-1 && c + 1 < n-1){
			intCase = 2;
			sq = InitSquare(p,intCase);
			ba.arrSquare.push_back(sq);
			d = d + 1;
			if (d > m -1){
				d = 0;
				c = c + 2;
			}
		}
		else if (c == n -1 && d < m -1){
			intCase = 3;
			sq = InitSquare(p,intCase);
			ba.arrSquare.push_back(sq);
			
			d = d + 2;
			
			if (d > m -1){
				d = 0;
				c = c + 2;
			}
		}
		else if(c == n -1 && d == m - 1){
			intCase = 1;
			sq = InitSquare(p,intCase);
			ba.arrSquare.push_back(sq);
			break;
		}
		else{
			break;
		}
	}	
	
	return ba;
}

void AddTree (base &ba)
{
	vector<vector<long>> B;
	square *sq;
	point p;
	int count = 0;
	
	for (int i = 0; i < ba.arrSquare.size(); i++){
		sq = &ba.arrSquare[i];
		(*sq).h = arrTree[count];
		for(int j = 0; j < (*sq).arrPoints.size(); j++){
			p = (*sq).arrPoints[j];
			A[p.x][p.y] = arrTree[count];
			count++;
		}
	}
}


void Print1 (base ba)
{
	for (int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			che_out << A[i][j] << " ";
			}
		che_out << endl;
	}
	
	che_out << ba.arrSquare.size() << endl;
}

void CoverFour (point p)
{
	A[p.x][p.y] = A[p.x][p.y] + 1;
	arrCover.push_back( A[p.x][p.y]);
}

void CoverOneTwo(point p)
{
	A[p.x][p.y] = A[p.x][p.y] + 1;
	
	if (A[p.x-2][p.y] == A[p.x][p.y]){
		A[p.x][p.y] = A[p.x][p.y] + 1;
	}	
	
	arrCover.push_back( A[p.x][p.y]);
}

void CoverTwoOne(point p)
{
	A[p.x][p.y] = A[p.x][p.y] + 1;
	
	if (A[p.x][p.y-2] == A[p.x][p.y]){
		A[p.x][p.y] = A[p.x][p.y] + 1;
	}	
	
	arrCover.push_back( A[p.x][p.y]);	
}

void CoverOne (point p)
{
	A[p.x][p.y] = A[p.x][p.y] + 1;
	
	if (A[p.x-2][p.y] == A[p.x][p.y]){
		A[p.x][p.y] = A[p.x][p.y] + 1;
	}	
	if (A[p.x][p.y-2] == A[p.x][p.y]){
		A[p.x][p.y] = A[p.x][p.y] + 1;
	}	
	if (A[p.x-2][p.y-2] == A[p.x][p.y]){
		A[p.x][p.y] = A[p.x][p.y] + 1;
	}	
	
	arrCover.push_back( A[p.x][p.y]);	
}

void BuildRoof(base ba)
{
	point p;
	
	int c = 0;
	int d = 0;
	int intCase = 0;
	
	while (true){
		p.x = c;
		p.y = d;
		
		if (c + 1  < n - 1 && d + 1 < m-1){
			intCase = 4;
			CoverFour(p);
			d = d + 2;
			if (d > m -1){
				d = 0;
				c = c + 2;
			}
			
		}
		else if (d == m-1 && c + 1 < n-1){
			intCase = 2;
			CoverOneTwo(p);
			d = d + 1;
			if (d > m -1){
				d = 0;
				c = c + 2;
			}
		}
		else if (c == n -1 && d < m -1){
			intCase = 3;
			CoverTwoOne(p);			
			d = d + 2;
			
			if (d > m -1){
				d = 0;
				c = c + 2;
			}
		}
		else if(c == n -1 && d == m - 1){
			intCase = 1;
			CoverOne(p);
			break;
		}
		else{
			break;
		}
	}	
}

void Print2(base ba)
{
	for (int i = 0; i < arrCover.size()-1; i++){
		che_out << arrCover[i] << " ";
	}
	che_out << arrCover[arrCover.size()-1];
}

void Solve()
{
	base ba;
	
	ba = InitBase();
	sort(arrTree.begin(), arrTree.end());
	reverse(arrTree.begin(), arrTree.end());
	AddTree(ba);
	Print1(ba);
	BuildRoof(ba);
	Print2(ba);
}

int main()
{
	
	che_inp.open("C:\\bt_c++\\de_hsg\\CHEVUON.INP");
	che_out.open("C:\\bt_c++\\de_hsg\\CHEVUON.OUT");
	
	Input();
	Solve();
	che_inp.close();
	che_out.close();
}
