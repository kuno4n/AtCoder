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

LL n, m;
map<LL, LL> ma;
vector<pair<LL, LL>> v;

void solve() {
  cin >> n >> m;
  REP(_, n) {
    LL a;
    cin >> a;
    ma[a]++;
  }
  REP(_, m) {
    LL b, c;
    cin >> b >> c;
    ma[c] += b;
  }
  for(auto x : ma) {
    LL num = x.first;
    LL cnt = x.second;
    v.push_back({num, cnt});
  }
  sort(ALL(v));
  reverse(ALL(v));
  LL res = 0;
  for(auto x: v) {
    LL num = x.first;
    LL cnt = x.second;
    res += num * min(cnt, n);
    n -= cnt;
    chmax(n, 0LL);
  }
  cout << res << endl;
}

int main() {
	solve();
	return 0;
}
