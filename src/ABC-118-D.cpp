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

string mem[10010];
int use[10] = {0, 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
bool can[10];

string go(int a) {
  if (mem[a] != "") return mem[a];
  if (a == 0) {
    return "";
  }
  string res = "";
  for(int i = 9; i >= 1; i--) {
    if(can[i] && a >= use[i]) {
      string under = go(a-use[i]);
      if (under != "x") {
        string tmp = to_string(i) + under;
        if (SZ(tmp) > SZ(res)) res = tmp;
      }
    }
  }
  if (res == "") res = "x";
  mem[a] = res;
  return res;
}

void init() {

}

void input() {

}

void solve() {
  int n, m;
  cin >> n >> m;
  REP(i, 10010) mem[i] = "";
  REP(i, 10) can[i] = false;
  REP(i, m) {
    int a;
    cin >> a;
    can[a] = true;
  }
  cout << go(n) << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}
