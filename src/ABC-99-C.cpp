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

#define MAX 100010
#define INF 1<<29
int n;
int dp[MAX];

void init() {

}

void input() {
	cin >> n;
}

void solve() {
	dp[0] = 0;
	for (int i = 1; i < MAX; i++) ;
	FOR(i, 1, MAX) dp[i] = INF;
	REP(i, MAX-1) {
		chmin(dp[i+1], dp[i]+1);
		for(int j = 6; i+j < MAX; j *= 6) chmin(dp[i+j], dp[i]+1);
		for(int j = 9; i+j < MAX; j *= 9) chmin(dp[i+j], dp[i]+1);
	}
	cout << dp[n] << endl;

}

int main() {
	init();
	input();
	solve();
	return 0;
}
