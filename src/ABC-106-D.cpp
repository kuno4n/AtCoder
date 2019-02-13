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

LL sum1[501][501];
LL sum2[501][501];
LL sum3[501][501];

void init() {

}

void input() {

}

// int l[200010], r[200010];

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  REP(i, 501) REP(j, 501) sum1[i][j] = 0;
  REP(i, 501) REP(j, 501) sum2[i][j] = 0;
  REP(i, 501) REP(j, 501) sum3[i][j] = 0;
  REP(i, m) {
    int l, r;
    cin >> l >> r;
    sum1[l][r]++;
  }
  REP(i, 501) FOR(j, i, 501) {
    FOR(k, i, j+1) sum2[i][j] += sum1[k][j];
  }
  REP(_, q){
    int l, r;
    cin >> l >> r;
    LL res = 0;
    FOR(i, l, r+1) res += sum2[l][i];
    cout << res << endl;
  }
}

int main() {
	init();
	input();
	solve();
	return 0;
}
