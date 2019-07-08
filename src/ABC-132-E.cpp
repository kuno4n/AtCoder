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
VI e[100010];

void solve() {
  cin >> n >> m;
  REP(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    e[u].push_back(v);
  }
  cin >> s >> t;
  s--;
  t--;

  set<int> vis1;
  set<int> vis2;
  set<int> vis3;
  vis3.insert(s);
  queue<pair <int, int> > q;
  q.push(make_pair(s, 0));
  while(q.size() > 0) {
    pair <int, int> node = q.front();
    q.pop();
    int v = node.first;
    int cost = node.second;
    if (v == t) {
      cout << cost << endl;
      return;
    }

    VI v1s;
    REP(i, SZ(e[v])) {
      if (vis1.count(e[v][i]) == 0) {
        v1s.push_back(e[v][i]);
        vis1.insert(e[v][i]);
      }
    }
    VI v2s;
    REP(i, SZ(v1s)) REP(j, SZ(e[v1s[i]])){
      int next = e[v1s[i]][j];
      if (vis2.count(next) == 0) {
        v2s.push_back(next);
        vis2.insert(next);
      }
    }
    REP(i, SZ(v2s)) REP(j, SZ(e[v2s[i]])) {
      int next = e[v2s[i]][j];
      if (vis3.count(next) == 0) {
        q.push(make_pair(next, cost+1));
        vis3.insert(next);
      }
    }

  }
  cout << -1 << endl;

}

int main() {
	solve();
	return 0;
}
