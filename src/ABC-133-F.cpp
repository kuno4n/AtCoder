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
struct edge{
  int to, c, d;
};
vector<edge> e[100010];

int parent[100010][20];
int depth[100010];

VI euler;
LL distFromRoot[100010];
map<int, int> eulerIdx;

vector<LL> eulerColor[100010], eulerColorSum[100010], eulerColorNum[100010], eulerColorIdx[100010];

void dfs(int v, int p, int d) {
  parent[v][0] = p;
  FOR(i, 1, 20) if((1<<i) <= d) {
    parent[v][i] = parent[parent[v][i-1]][i-1];
  }
  depth[v] = d;
  for (auto child : e[v]) if (child.to != p) {
    dfs(child.to, v, d+1);
  }
}

int lca(int u, int v) {
  while(depth[u] > depth[v]) swap(u, v);
  REP(i, 20) if ((depth[v]-depth[u]) & (1<<i)) {
    v = parent[v][i];
  }
  if (u == v) return u;
  for(int i = 19; i >= 0; i--) if (parent[u][i] != parent[v][i]) {
    u = parent[u][i];
    v = parent[v][i];
  }
  return parent[u][0];
}

void dfs2(int v) {
  for (auto child : e[v]) if (child.to != parent[v][0]) {
    distFromRoot[child.to] = distFromRoot[v] + child.d;
    euler.push_back(child.d);
    eulerIdx[child.to] = SZ(euler)-1;
    eulerColor[child.c].push_back(child.d);
    if (SZ(eulerColorSum[child.c]) == 0) {
      eulerColorSum[child.c].push_back(child.d);
      eulerColorNum[child.c].push_back(1);
    }
    else {
      eulerColorSum[child.c].push_back(eulerColorSum[child.c].back() + child.d);
      eulerColorNum[child.c].push_back(eulerColorNum[child.c].back() + 1);
    }
    eulerColorIdx[child.c].push_back(SZ(euler) - 1);

    dfs2(child.to);

    euler.push_back(-child.d);
    eulerColor[child.c].push_back(-child.d);
    eulerColorSum[child.c].push_back(eulerColorSum[child.c].back() - child.d);
    eulerColorNum[child.c].push_back(eulerColorNum[child.c].back() - 1);
    eulerColorIdx[child.c].push_back(SZ(euler) - 1);
  }
}

LL calColorDiff(int v, int x, int y) {
  if (v == 0) return 0;
  int idx = upper_bound(ALL(eulerColorIdx[x]), eulerIdx[v]) - eulerColorIdx[x].begin() - 1;
  if (idx < 0) return 0;
  return -eulerColorSum[x][idx] + eulerColorNum[x][idx]*y;
}

void solve() {
  MSET(parent, 0);
  cin >> n >> q;
  REP(i, n-1) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    e[a].push_back(edge{b, c, d});
    e[b].push_back(edge{a, c, d});
  }
  dfs(0, -1, 0);
  distFromRoot[0] = 0;
  dfs2(0);

  // for(auto a: euler) cout << a << " ";
  // cout << endl;
  // REP(i, n) cout << distFromRoot[i] << " " ;
  // cout << endl;
  // for(auto [k, v]: eulerIdx) cout << v << " ";
  // cout << endl;
  // REP(i, n) {
  //   cout << i << " : ";
  //   for(auto j : eulerColor[i]) cout << j << " ";
  //   cout << endl;
  //   cout << i << " : ";
  //   for(auto j : eulerColorSum[i]) cout << j << " ";
  //   cout << endl;
  //   cout << i << " : ";
  //   for(auto j : eulerColorNum[i]) cout << j << " ";
  //   cout << endl;
  //   cout << i << " : ";
  //   for(auto j : eulerColorIdx[i]) cout << j << " ";
  //   cout << endl;
  // }

  REP(_, q) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    u--; v--;
    int l = (lca(u, v));
    LL res = distFromRoot[u] + distFromRoot[v] - distFromRoot[l]*2;
    // OUT2(u, v);
    // OUT2(x, y);
    // OUT(calColorDiff(u, x, y));
    // OUT(calColorDiff(v, x, y));
    // OUT(calColorDiff(lca(u, v), x, y));
    cout << res + calColorDiff(u, x, y) + calColorDiff(v, x, y) - calColorDiff(lca(u, v), x, y)*2 <<  endl;
  }
}

int main() {
	solve();
	return 0;
}
