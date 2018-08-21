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
#define cpresent(c, e) (find(ALL(c), (e)) != (c).end())

int n, m;
int g[710][710], gg[710];

void init() {

}

void input() {
	cin >> n >> m;
	REP(i, n) REP(j, n) if (i != j) g[i][j] = 1;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a][b] = 0;
		g[b][a] = 0;
	}
}

bool go(int node, int num) {
	if (gg[node] == num) return true;
	if (gg[node] == -num) return false;
	gg[node] = num;
	REP(i, n) if (g[node][i]) {
		if (!go(i, -num)) return false;
	}
	return true;
}

void solve() {
	MSET(gg, 0);
	vector < pair<int, int> > v;
	REP(i, n) {
		if (gg[i] != 0) continue;
		int num = SZ(v) + 1;
		if (!go(i, num)) {
			cout << -1 << endl;
			return;
		}
		int c1 = 0;
		int c2 = 0;
		REP(j, n) {
			if (gg[j] == num) c1++;
			if (gg[j] == -num) c2++;
		}
		v.push_back(make_pair(c1, c2));
	}
	bool b[SZ(v)+1][n+1];
	REP(i, SZ(v)+1) REP(j, n+1) b[i][j] = false;
	b[0][0] = true;
	REP(i, SZ(v)) {
		REP(j, n+1) {
			if (b[i][j]) {
				b[i+1][j+v[i].first] = true;
				b[i+1][j+v[i].second] = true;
			}
		}
	}
	int res = 1<<30;
	REP(i, n+1) if (b[SZ(v)][i]) {
		chmin(res, i*(i-1)/2 + (n-i)*(n-i-1)/2);
	}
	cout << res << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}
