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

double dp[105][70][40][30];
int n;
LL d;

void init() {
}

void input() {
    cin >> n >> d;
}

void solve() {
    int p[3];
    MSET(p, 0);
    while(d % 2 == 0) d /= 2, p[0]++;
    while(d % 3 == 0) d /= 3, p[1]++;
    while(d % 5 == 0) d /= 5, p[2]++;
    if(d > 1){
        cout << 0 << endl;
        return;
    }
    
    int _2[6] = {0, 1, 0, 2, 0, 1};
    int _3[6] = {0, 0, 1, 0, 0, 1};
    int _5[6] = {0, 0, 0, 0, 1, 0};
    dp[0][0][0][0] = 1.0;
    for(int i = 0; i < n; i++) REP(j, 70) REP(k, 40) REP(l, 30) if(dp[i][j][k][l] > 0.0){
        REP(m, 6) dp[i+1][min(69, j+_2[m])][min(39, k+_3[m])][min(29, l+_5[m])] += dp[i][j][k][l] / 6.0;
    }
    double res = 0.0;
    FOR(j, p[0], 70) FOR(k, p[1], 40) FOR(l, p[2], 30) res += dp[n][j][k][l];
    printf("%.10lf\n", res);
    
}

int main() {
    init();
    input();
    solve();
}



