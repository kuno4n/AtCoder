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

set<LL> s;
vector<pair<int, int> > vp;
VI v;
LL k, n;

bool pairCompare(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

void init() {

}

void input() {
  cin >> n >> k ;
  REP(i, n) {
    LL a, b;
    cin >> a >> b;
    vp.push_back(make_pair(a, b));
  }
}

void solve() {
  sort(vp.begin(), vp.end(), pairCompare);
  LL sum = 0;
  REP(i, k) {
    if (s.count(vp[i].first)) v.push_back(vp[i].second);
    s.insert(vp[i].first);
    sum += vp[i].second;
  }
  LL ret = sum + s.size()*s.size();
  sort(ALL(v));
  int ptr = k;
  REP(i, v.size()) {
    while(ptr < n) {
      if (s.count(vp[ptr].first) == 0) {
        s.insert(vp[ptr].first);
        sum -= v[i];
        sum += vp[ptr].second;
        chmax(ret, sum + (LL)(s.size()*s.size()));
        ptr++;
        break;
      }
      ptr++;
    }
  }
  cout << ret << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}
