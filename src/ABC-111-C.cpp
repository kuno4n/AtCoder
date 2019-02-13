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

int n;
int a[100010];

map<int, int> m1, m0;
VI v0, v1;

void init() {

}

void input() {

}

int sol(map<int, int> m0, map<int, int> m1) {
  int res = 0;
  int m0max = 0;
  int m0key;
  for(auto x : m0) {
    if (x.second > m0max){
      m0max = x.second;
      m0key = x.first;
    }
  }
  for(auto x : m0) {
    if (x.first != m0key) res += x.second;
  }

  int m1max = 0;
  int m1key;
  for(auto x : m1) {
    if (x.second > m1max && x.first != m0key){
      m1max = x.second;
      m1key = x.first;
    }
  }
  for(auto x : m1) {
    if (x.first != m1key) res += x.second;
  }

  // cout << "m0key: " << m0key << endl;
  //   cout << "m0max: " << m0max << endl;
  //     cout << "m1key: " << m1key << endl;
  //       cout << "m1max: " << m1max << endl;
  //         cout << "res: " << res << endl;

  return res;
}

void solve() {
  cin >> n;
  REP(i, n) cin >> a[i];

  for(int i=0; i<n; i+=2) m0[a[i]]++;
  for(int i=1; i<n; i+=2) m1[a[i]]++;
  // for(auto x : m0) cout << x.first << " " << x.second << endl;
  // for(auto x : m1) cout << x.first << " " << x.second << endl;
  for(auto x : m0) v0.push_back(x.second);
  for(auto x : m1) v1.push_back(x.second);

  cout << min(sol(m0, m1), sol(m1,m0)) << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}
