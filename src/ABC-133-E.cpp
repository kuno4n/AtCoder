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

VI a[100010];

void solve() {
  LL n, k;
  cin >> n>> k;
  REP(i, n-1) {
    int b, c;
    cin >> b >> c;
    b--;c--;
    a[b].push_back(c);
    a[c].push_back(b);
  }

  queue<pair<int,pair<int, int>>> q;
  q.push(make_pair(0, make_pair(0, -1)));
  LL res = k;
  while(SZ(q) > 0) {
    pair <int, pair<int, int>> node = q.front();
    q.pop();
    int depth = node.second.first;
    int d = depth;
    if (d > 1) d = 1;
    int parent = node.second.second;
    for(auto p : a[node.first]) if (p != parent){
      d++;
      // OUT2(a[node.first][i], d);
      res = (res * (k-d)) % 1000000007;
      q.push(make_pair(p, make_pair(depth+1, node.first)));
    }
  }
  cout << res << endl;
}

int main() {
	solve();
	return 0;
}
