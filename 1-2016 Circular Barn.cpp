/*
	Written by Adam Galauner
	Feb. 19th, 2016

	Circular Barn Problem:
	http://usaco.org/index.php?page=viewproblem2&cpid=618
*/

#include<fstream> //fstream
#include<cmath>
#include<vector>

using namespace std;

vector<int> v;
vector<int> e;

int main() {
	int ret = 0;
	int n;
	ifstream cin ("cbarn.in");
	ofstream cout ("cbarn.out");
	cin >> n;
	int lz;
	int cows = 0;
	bool d = false;
	for (int i=0;i<n;i++) {
		int hi;
		cin >> hi;
		v.push_back(hi);
		e.push_back(0);
		cows+=hi;
		if (cows > 0) {cows--;}
		if (cows > 0) {if (d==false) {lz=(i-1); d = true;}}
		else {d = false;}
	}
	int i = 0;
	int sblz = 0; //sum_before_last_zero
	for (int i=0;i<lz;i++) {
		sblz+=v[i];
	}
	for (int i=0;i<n;i++) {
		int spot = fmod(n+lz-i,n);
		for (int r=spot+n;r>=spot-n;r--) {
			int rr = fmod(r,n);
			if (v[rr] > 0) {v[rr]--; v[spot]=1; if (spot-rr < 0) {ret+=pow(spot-rr+n,2);} else
			 {ret+=pow(spot-rr,2);} break;}
		}
	}
	cout << ret;
}
