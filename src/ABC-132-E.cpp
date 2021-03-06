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

int n, m, s, t;
VI e[300010];

void solve() {
  cin >> n >> m;
  REP(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    e[u*3].push_back(v*3+1);
    e[u*3+1].push_back(v*3+2);
    e[u*3+2].push_back(v*3);
  }
  cin >> s >> t;
  s--;
  t--;
  s *= 3;
  t *= 3;

  set<int> vis;
  vis.insert(s);
  queue<pair <int, int> > q;
  q.push({s, 0});
  while(q.size() > 0) {
    pair <int, int> node = q.front();
    q.pop();
    int v = node.first;
    int cost = node.second;
    if (v == t) {
      cout << cost/3 << endl;
      return;
    }

    for (auto a: e[v]) {
      if (vis.count(a) == 0) {
        q.push({a, cost+1});
        vis.insert(a);
      }
    }

  }
  cout << -1 << endl;

}

int main() {
	solve();
	return 0;
}
