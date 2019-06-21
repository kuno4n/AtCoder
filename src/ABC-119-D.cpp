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

LL A, B, Q;
vector<LL> s, t;
LL INF = 1LL<<55;

void init() {

}

void input() {
  cin >> A >> B >> Q;
  REP(i, A) {
    LL l;
    cin >> l;
    s.PB(l);
  }
  s.PB(INF);
  s.PB(-INF);
  REP(i, B) {
    LL l;
    cin >> l;
    t.PB(l);
  }
  t.PB(INF);
  t.PB(-INF);
  sort(ALL(s));
  sort(ALL(t));
}

void solve() {
  REP(_, Q) {
    LL x;
    cin >> x;
    int prs = lower_bound(ALL(s), x) - s.begin();
    int pls = prs - 1;
    int prt = lower_bound(ALL(t), x) - t.begin();
    int plt = prt - 1;
    LL rs = s[prs] - x;
    LL ls = x - s[pls];
    LL rt = t[prt] - x;
    LL lt = x - t[plt];

    LL res = INF;
    chmin(res, rs + rt - min(rs, rt));
    chmin(res, ls + lt - min(ls, lt));
    chmin(res, rs + lt + min(rs, lt));
    chmin(res, ls + rt + min(ls, rt));
    cout << res << endl;
  }
}

int main() {
	init();
	input();
	solve();
	return 0;
}
