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
#define cpresent(c, e) (find(all(c), (e)) != (c).end())


int n, k;
int c[200010];
int q;
int d[200010];

void init() {
}

void input() {
	cin >> n >> k;
	REP(i, n) cin >> c[i];
	cin >> q;
	REP(i, q){
		cin >> d[i];
		d[i]--;
	}
}

VI v;
void solve() {
	sort(c, c+n);
	REP(i, n-1) v.push_back(c[i+1]-c[i]);
	sort(ALL(v));
	int res = c[n-1] - c[0];
	reverse(ALL(v));
	REP(i, k-1) res -= v[i];
	cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






