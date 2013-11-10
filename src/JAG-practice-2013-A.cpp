#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int n;
const LL INF = 1LL<<50;
LL tab[1010];

void init() {
}

void input() {
	REP(i, n){
		string s;
		cin >> s;
		if(s == "x") tab[i] = INF;
		else tab[i] = atoi(s.c_str());
	}
}

void solve() {
	REP(i, n-1) if(tab[i] == INF && tab[i+1] == INF){
		cout << "none" << endl;
		return;
	}
	REP(i, n-1) if(tab[i] != INF && tab[i+1] != INF){
		if((i&1) && tab[i] <= tab[i+1]){
			cout << "none" << endl;
			return;
		}
		if(!(i&1) && tab[i] >= tab[i+1]){
			cout << "none" << endl;
			return;
		}
	}
	
	
	LL l, r;
	l = -INF, r = INF;
	REP(i, n) if(tab[i] == INF){
		if(i > 0 && tab[i-1] != INF){
			if(i&1) chmax(l, tab[i-1]+1);
			else chmin(r, tab[i-1]-1);
		}
		if(i < n-1 && tab[i+1] != INF){
			if(i&1) chmax(l, tab[i+1]+1);
			else chmin(r, tab[i+1]-1);
		}
		if(l > r){
			cout << "none" << endl;
			return;
		}
		
	}
	if(r - l > 0) cout << "ambiguous" << endl;
	else cout << r << endl;
}

int main() {
	while(1){
		cin >> n;
		if(n == 0) break;
		input();
		solve();
	}
	return 0;
}






