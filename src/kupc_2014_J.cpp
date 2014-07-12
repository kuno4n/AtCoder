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

LL n, m, p;
LL x[25];
LL X[25];
LL dp[150][150];

void init() {
}

void input() {
    cin >> n >> m >> p;
    REP(i, m) cin >> x[i];
    LL cnt = 0;
    REP(i, m){
        cnt += x[i];
        X[i] = cnt;
    }
}

void solve() {
    MSET(dp, -1);
    dp[0][0] = 0;
    REP(day, 110){
        if(day != 0){
            REP(i, 110) dp[day][i] = dp[day-1][i];
        }
        REP(i, 110) if(dp[day][i] != -1) dp[day][i] += p;
        for(int i = 110; i >= 0; i--){
            REP(j, m) if(dp[day][i] >= X[j]) chmax(dp[day][i+j+1], dp[day][i] - X[j]);
        }
        if(dp[day][n] != -1){
            cout << day+1 << endl;
            return;
        }
    }
}

int main() {
    init();
    input();
    solve();
}







