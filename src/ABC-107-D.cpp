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

LL n;
LL a[100010];
LL sorted[100010];
int sum[100010];

void init() {

}

void input() {
	cin >> n;
	REP(i, n) cin >> a[i];
	REP(i, n) sorted[i] = a[i];
	sort(sorted, sorted+n);
}

pair <VI, LL> bu(int l, int r) {
	if (l == r) {
		vector<int> d{sum[l]};
		return make_pair(d, 0);
	}
	int m = (l+r) / 2;
	pair <VI, LL> L = bu(l, m);
	pair <VI, LL> R = bu(m+1, r);
	VI vl = L.first, vr = R.first;
	LL count = L.second + R.second;
	VI res;
	int pl = 0, pr = 0;
	while(1) {
		if (pl == SZ(vl) && pr == SZ(vr)) break;
		else if (pl == SZ(vl)) res.push_back(vr[pr++]);
		else if (pr == SZ(vr)) res.push_back(vl[pl++]);
		else {
			if (vl[pl] <= vr[pr]) res.push_back(vl[pl++]);
			else {
				res.push_back(vr[pr++]);
				count += SZ(vl)-pl;
			}
		}
	}
	return make_pair(res, count);
}

bool go(LL p) {
	sum[0] = 0;
	REP(i, n) {
		if(a[i] >= p) sum[i+1] = sum[i] + 1;
		else sum[i+1] = sum[i] - 1;
	}
	pair <VI, LL> B = bu(0, n);
	return (n*(n+1)/2+1)/2 >= B.second;
}

void solve() {
	int l = 0;
	int r = n;
	while(r > l+1) {
		int m = (l+r)/2;
		if (go(sorted[m])) l = m;
		else r = m;
	}
	cout << sorted[l] << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}
