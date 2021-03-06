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

int n, q;
vector<pair<LL, LL>> imo;
set<LL> s;

void solve() {
  cin >> n >> q;
  REP(_, n) {
    LL s, t, x;
    cin >> s >> t >> x;
    s -= x;
    t -= x;
    imo.push_back({s, x});
    imo.push_back({t, -x});
  }
  sort(ALL(imo));
  int i = 0;
  REP(_, q) {
    LL d;
    cin >> d;
    while(i < SZ(imo) && imo[i].first <= d) {
      if (imo[i].second > 0) {
        s.insert(imo[i].second);
      } else {
        s.erase(-imo[i].second);
      }
      i++;
    }
    if (SZ(s) > 0) {
      cout << *s.begin() << endl;
    } else {
      cout << -1 << endl;
    }
  }
}

int main() {
	solve();
	return 0;
}
