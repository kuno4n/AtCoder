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

string s;
bool dp[310][310];

bool isiwi(int a, int b, int c){
	if(s[a] == 'i' && s[b] == 'w' && s[c] == 'i') return true;
	return false;
}

void init() {
}

void input() {
	cin >> s;
}

int memo[310][310];
int rec(int L, int R){
	if(memo[L][R] >= 0) return memo[L][R];
	int n = R - L;
	memo[L][R] = 0;
	for(int len = 3; len <= n; len +=3){
		for(int l = L; l <= R-len; l++){
			int r = l + len;
			if(dp[l][r]) chmax(memo[L][R], len/3 + rec(L, l) + rec(r, R));
		}
	}
	return memo[L][R];
}

void solve() {
	MSET(dp, false);
	REP(i, 310) dp[i][i] = true;
	int n = SZ(s);
	for(int len = 3; len <= n; len += 3) for(int l = 0; l <= n-len; l++){
		int r = l + len;
		if(dp[l  ][r-3] && isiwi(r-3, r-2, r-1)) dp[l][r] = true;
		if(dp[l+3][r  ] && isiwi(l  , l+1, l+2)) dp[l][r] = true;
		for(int j = l+1; j < r-1; j += 3) if(isiwi(l, j ,r-1) && dp[l+1][j] && dp[j+1][r-1]) dp[l][r] = true;
	}
	
	MSET(memo, -1);
	cout << rec(0, n) << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






