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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())


int n, x, m;
int l[12], r[12], s[12];
int table[10];

int mx;
int res[10];

void rec(int a){
	if(a == n){
		bool ok = true;
		REP(i, m) ok &= (s[i] == accumulate(table+l[i], table+r[i], 0));
		if(!ok) return;
		int sum = accumulate(table, table+n, 0);
		if(sum > mx){
			mx = sum;
			REP(i, n) res[i] = table[i];
		}
		return;
	}
	
	for(int i = 0; i <= x; i++){
		table[a] = i;
		rec(a+1);
	}
}

void init() {
}

void input() {
	cin >> n >> x >> m;
	REP(i, m){
		cin >> l[i] >> r[i] >> s[i];
		l[i]--;
	}
}

void solve() {
	mx = -1;
	rec(0);
	
	if(mx == -1) cout << -1 << endl;
	else{
		REP(i, n){
			cout << res[i];
			if(i == n-1) cout << endl;
			else cout << " ";
		}
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}






