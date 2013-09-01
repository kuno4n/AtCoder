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


const int INF = (1<<30);

int k;
double dp[1050][13];
int r[1050];

double getp(int rp, int rq){
    return 1.0/(1.0+pow(10.0, (rq-rp)/400.0));
}

void input() {
    cin >> k;
    REP(i, (1<<k)) cin >> r[i];
}

void solve() {
    REP(i, (1<<k)) dp[i][0] = 1.0;
    for(int round = 1; round <= k; round++){
        REP(i, (1<<k)){
            int lo = i/(1<<round)*(1<<round);
            int hi = lo + (1<<round);
            int mid = (lo+hi) /2;
            for(int j = (i < mid ? mid : lo); j < (i < mid ? hi : mid); j++) dp[i][round] += dp[j][round-1] * getp(r[i], r[j]);
            dp[i][round] *= dp[i][round-1];
        }
    }
    REP(i, (1<<k)) printf("%.9lf\n", dp[i][k]);
}

int main() {
    input();
    solve();
}







