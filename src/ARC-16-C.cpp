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


int n, m;
int c[4];
double p[4][10];
int cost[4];



bool chk(){
    bool ok = true;
    REP(i, m) ok &= (c[i] == 1);
    return ok;
}

void init() {
}

void input() {
    cin >> n >> m;
    REP(i, 4) REP(j, 10) p[i][j] = 0.0;
    REP(i, m){
        cin >> c[i] >> cost[i];
        REP(j, c[i]){
            int idol, pp;
            cin >> idol >> pp;
            p[i][idol-1] += (pp/100.0);
        }
    }
}

void solve() {
    if(n == 1){
        double res = 1e20;
        REP(i, m){
            chmin(res, (double)cost[i]);
        }
        printf("%8lf", res);
    }
    else if(chk()){
        double res = 0.0;
        REP(i, n){
            double mn = 1e20;
            REP(j, m) if(p[j][i] > 0) chmin(mn, cost[j]/p[j][i]);
            res += mn;
        }
        printf("%8lf", res);
    }
    else if(n == 2){
        double min0 = 1e20;
        double min1 = 1e20;
        REP(i, m){
            if(p[i][0] != 0) chmin(min0, cost[i]/p[i][0]);
            if(p[i][1] != 0) chmin(min1, cost[i]/p[i][1]);
        }
        double res = 1e20;
        REP(i, m){
            chmin(res, (cost[i]+min1)*p[i][0] + (cost[i]+min0)*p[i][1]);
        }
        printf("%8lf", res);
    }
    else if(m == 1){
        double dp[1<<n];
        REP(i, (1<<n)) dp[i] = 0;
        for(int i = (1<<n)-2; i >= 0; i--){
            double p_sum = 0;
            REP(j, n) if(!((i>>j)&1)) p_sum += p[0][j];
            REP(j, n) if(!((i>>j)&1)) dp[i] += dp[i|(1<<j)] * p[0][j]/p_sum ;
            dp[i] += cost[0]/p_sum;
        }
        printf("%8lf", dp[0]);
    }
    
    cout << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






