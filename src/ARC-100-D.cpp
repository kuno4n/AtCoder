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

int n;
LL a[200010];
LL sum[200010];
int l[200010];
int r[200010];

void init() {

}

void input() {
	cin >> n;
	REP(i, n) cin >> a[i];
}

LL ssum(int l, int r) {
	return sum[r] - sum[l];
}

void solve() {
	sum[0] = 0;
	REP(i, n) sum[i+1] = sum[i] + a[i];

	l[2] = 1;
	int pl = 1;
	for (int i = 3; i <= n-2; i++) {
		while(1) {
			LL sumll = ssum(0, pl);
			LL sumlr = ssum(pl, i);
			LL next_sumll = ssum(0, pl+1);
			LL next_sumlr = ssum(pl+1, i);
			if (abs(sumll-sumlr) < abs(next_sumll-next_sumlr)){
				l[i] = pl;
				break;
			}
			pl++;
		}
	}

	r[n-2] = n-1;
	int pr = n-1;
	for (int i = n-2; i >= 2; i--) {
		while(1) {
			LL sumrl = ssum(i, pr);
			LL sumrr = ssum(pr, n);
			LL next_sumrl = ssum(i, pr-1);
			LL next_sumrr = ssum(pr-1, n);
			if (abs(sumrl-sumrr) < abs(next_sumrl-next_sumrr)){
				r[i] = pr;
				break;
			}
			pr--;
		}
	}

	LL res = 1LL<<60;
	for (int i = 2; i <= n-2; i++) {
		LL sumll = ssum(0, l[i]);
		LL sumlr = ssum(l[i], i);
		LL sumrl = ssum(i, r[i]);
		LL sumrr = ssum(r[i], n);
		LL mx = max({sumll, sumlr, sumrl, sumrr});
		LL mn = min({sumll, sumlr, sumrl, sumrr});
		chmin(res, mx-mn);
	}
	cout << res << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}
