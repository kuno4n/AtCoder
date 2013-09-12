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

LL dp[1000010][26];
string s;
LL K;
LL INF = (1LL<<60);

void init() {
}

void input() {
	cin >> s >> K;
}

string dfs(int a, LL k){
	if(k == 0) return "";
	char c;
	REP(i, 26){
		if(dp[a][i] >= k){
			c = 'a'+i;
			break;
		}
		k -= dp[a][i];
	}
	while(s[a] != c) a++;
	return c+dfs(a+1, k-1);
}

void solve() {
	int n = SZ(s);
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			dp[i][s[i]-'a'] = min(INF, dp[i][s[i]-'a'] + dp[i+1][j]);
			if(s[i]-'a' != j) dp[i][j] = dp[i+1][j];
		}
		dp[i][s[i]-'a']++;
	}
	
	LL sum = 0;
	REP(i, 26) sum = min(INF, sum+dp[0][i]);
	if(sum < K){
		cout << "Eel" << endl;
		return;
	}
	
	cout << dfs(0, K) << endl;
	
	
}

int main() {
	init();
    input();
    solve();
	return 0;
}






