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

int n, k, q;
int a[2010];

void init() {

}

void input() {
	cin >> n >> k >> q;
	REP(i, n) cin >> a[i];
}

void solve() {
	int res = 1<<30;
	REP(i, n) {
		vector < VI > v;
		VI _v;
		REP(j, n) {
			if (a[j] < a[i]) {
				if (SZ(_v) > 0) {
					v.PB(_v);
					_v.clear();
				}
			} else {
				_v.PB(a[j]);
			}
		}
		if (SZ(_v) > 0) {
			v.PB(_v);
		}

		VI mins;
		for (auto __v : v) {
			sort(ALL(__v));
			for (int j = 0; j <= SZ(__v)-k; j++) mins.PB(__v[j]);
		}
		if (SZ(mins) < q) continue;
		sort(ALL(mins));
		chmin(res, mins[q-1] - mins[0]);
	}
	cout << res << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}
