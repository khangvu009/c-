#include<bits/stdc++.h>

using namespace std;

struct Point {
    long start;
    long end;
};

vector<Point> A;

void Sort(){
	Point temp;
	
	cout << endl << endl;
	
	for(long i = 0; i < A.size()-1; i++){
		for(long j = i+1; j < A.size(); j++){
			if(A[i].start > A[j].start){
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}		
		}
	}
}

void FindMaxMin(long &min , long & maxx){
	for(long i = 0; i < A.size(); i++){
		if(min > A[i].start){
			min = A[i].start; 
		}
		if(maxx < A[i].end){
			maxx = A[i].end; 
		}
	}
}

void Print(){
	for(long i = 0; i < A.size(); i++){
		cout << A[i].start << " " << A[i].end << endl;
	}
	cout << endl << endl;
}

void Solve(long n, long m) {
	long count = 0;
    long max = -1,min = A[0].start, maxx = 1;

    Sort();
    FindMaxMin(min,maxx);
    Print();
    
    cout << "min = " << min << " maxx = " << maxx << endl << endl;
    for (long i = min; i <= maxx; i++) {
    	if(max == m){
    		cout << "max = " << max << endl;
    		break;
		}
		cout << "i = " << i << " max = " << max << endl;
        for(long j = 0; j < A.size(); j++){
        	if (A[j].start <= A[j].end && i >= A[j].start && i <= A[j].end) {
  				count++;
			}
			else if (A[j].start > A[j].end && (i >= A[j].start || i <= A[j].end)) {
    			count++;
			}
        	long temp = m - max;
        	if(j+1-count > temp && max != -1){
        		cout << "      j = " << j << " gap = " << j+1-count << " count = " << count << endl;
        		break;
			}
	   }
	   if(max < count ) max = count;
	   count = 0;
    }
    
    cout << max;
}

int main() {
    long n, m;
    Point p;
    cin >> n >> m;
    
    for (long i = 0; i < m; i++) {
        cin >> p.start >> p.end;
        A.push_back(p);
    }
    
    Solve(n,m);    
}

