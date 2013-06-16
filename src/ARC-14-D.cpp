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

LL all, N, M;
LL L[100010], x[100010], y[100010];

void init() {
}

void input() {
	cin >> all >> N >> M;
	REP(i, N) cin >> L[i];
	REP(i, M) cin >> x[i] >> y[i];
}

LL table[100010];
LL table2[100010];

void solve() {
	MSET(table, 0);MSET(table2, 0);
	REP(i, N-1) table[i] = L[i+1]-L[i]-1;
	sort(table, table+N-1);
	FOR(i, 1, N) table2[i] = table2[i-1] + table[i-1];
	
	REP(i, M){
		LL res = N + min(L[0]-1, x[i]) + min(all-L[N-1], y[i]);
		LL xy = x[i]+y[i];
		LL ptr = lower_bound(table, table+N-1, xy) - table;
		res += table2[ptr];
		res += xy * (N-1-ptr);
		cout << res << endl;
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}






