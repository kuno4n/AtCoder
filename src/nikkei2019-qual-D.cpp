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

int n, m;
int r;
vector<int> e[100010];
vector<int> topo;
// bool used[100010];
int in[100010];
int parent[100010];

void init() {

}

// void dfs(int i) {
//   if (used[i]) return;
//   used[i] = true;
//   REP(j, SZ(e[i])) dfs(e[i][j]);
//   topo.push_back(i);
// }
//
// void makeTopo() {
//   topo.clear();
//   REP(i, n) dfs(i);
//   reverse(ALL(topo));
// }

void input() {
  REP(i, 100010) {
    e[i].clear();
    parent[i] = -1;
    in[i] = 0;
  }
  cin >> n >> m;
  REP(i, n+m-1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    in[b]++;
  }
  queue<int> q;
  REP(i, n) if (in[i] == 0) q.push(i);
  while(!q.empty()) {
    int i = q.front();
    // topo.push_back(i);
    q.pop();
    REP(j, SZ(e[i])) {
      in[e[i][j]]--;
      if (in[e[i][j]] == 0) {
        q.push(e[i][j]);
        parent[e[i][j]] = i;
      }
    }
  }
  // REP(i, n) {
  //   REP(j, SZ(e[topo[i]])) {
  //     parent[e[topo[i]][j]] = topo[i];
  //   }
  // }
  REP(i, n) printf("%d\n",parent[i]+1);
}

void solve() {

}

int main() {
	init();
	input();
	solve();
	return 0;
}
