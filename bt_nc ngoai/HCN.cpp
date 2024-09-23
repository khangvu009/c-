#include<bits/stdc++.h>

using namespace std;

struct Rectangle{
	long x1;
	long y1;
	long x2;
	long y2;
};


int FindMax(Rectangle rect, Rectangle rect1){
	long S1 = abs(rect.x1-rect.x2) * abs(rect.y1-rect.y2);
	long S2 = abs(rect1.x1-rect1.x2) * abs(rect1.y1-rect1.y2);
	
	if(S1 >= S2) return 0;
	return 1;
}

int CheckPlace(long x, long y, Rectangle rect){
	long mind,maxd,minc,maxc;
	
	mind = min(rect.x1,rect.x2);
	minc = min(rect.y1,rect.y2);
	maxd = max(rect.x1,rect.x2);
	maxc = max(rect.y1,rect.y2);
	
	if(x < maxd && x > mind && y < maxc && y > minc) return 0;
	if(( (x == mind|| x == maxd)&& y <= maxc && y >= minc) || ((y == minc || y == maxc) && x >= maxd && x <= mind)) return 1;
	if(x > maxd || x < mind || y > maxc || y < minc) return 2;
}

void Solve(Rectangle rect, Rectangle rect1){
	Rectangle temp;
	int cases = FindMax(rect,rect1);
	
	if(cases == 1){
		temp = rect;
		rect = rect1;
		rect1 = temp;
	}
	
	if (rect.x1 == rect1.x1 && rect.y1 == rect1.y1 && rect.x2 == rect1.x2 && rect.y2 == rect1.y2) {
        cout << "Hai hinh chu nhat trung nhau";
    }
    else{
		int place1 = CheckPlace(rect.x1,rect.y1,rect1);
		int place2 = CheckPlace(rect.x2,rect.y2,rect1);
		
		if (place1 == 0 && place2 == 0) {
	        cout << "Mot hinh chu nhat chua mot hinh chu nhat khac";
	    } 
	    else if ((place1 == 2 || place2 == 2) && (place1 == 0 || place2 == 0)){
	    	cout << "Hai hinh chu nhat cat nhau";
		}
		else if ((place1 == 1 || place2 == 1) && (place1 == 2 || place2 == 2)) {
	        cout << "Hai hinh chu nhat tiep xuc ngoai nhau";
	    } 
		else if ((place1 == 1 || place2 == 1) && (place1 == 0 || place2 == 0)) {
	        cout << "Hai hinh chu nhat tiep xuc trong nhau";
	    } 
		else {
	        cout << "Hai hinh chu nhat khong giao nhau";
	    }
	}
}

int main(){
	Rectangle rect,rect1;
	
	cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
	cin >> rect1.x1 >> rect1.y1 >> rect1.x2 >> rect1.y2; 
	
	Solve(rect,rect1);
}
