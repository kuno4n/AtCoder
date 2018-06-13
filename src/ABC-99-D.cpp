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

int n, C;
int d[30][30];
int c[500][500];
int cal[3][30];

void init() {

}

void input() {
	cin >> n >> C;
	REP(i, C) REP(j, C) cin >> d[i][j];
	REP(i, n) REP(j, n) {
		cin >> c[i][j];
		c[i][j]--;
	}
}

void solve() {
	int res = 1<<30;
	MSET(cal, 0);
	REP(a, 3) REP(i, n) REP(j, n) if((i+j)%3 == a) REP(col, C) cal[a][col] += d[c[i][j]][col];
	REP(c0, C) REP(c1, C) REP(c2, C) {
		if (c0 == c1) continue;
			if (c1 == c2) continue;
				if (c2 == c0) continue;
		 chmin(res, cal[0][c0] + cal[1][c1] + cal[2][c2]);
	}
	cout << res << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}
