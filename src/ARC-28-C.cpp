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

int n;
int p[100010];
VI g[100010];
int pa[100010];
int a[100010];
int b[100010];

int rec(int m){
    int res = 1;
    REP(i, SZ(g[m])) res += rec(g[m][i]);
    return a[m] = res;
}

void sol(int m){
    int res = 0;
    REP(i, SZ(g[m])) chmax(res, a[g[m][i]]);
    chmax(res, n-a[m]);
    b[m] = res;
    REP(i, SZ(g[m])) sol(g[m][i]);
}


void init() {
    MSET(a, 0);
    MSET(b, 0);
}

void input() {
    cin >> n;
    REP(i, n) cin >> p[i];
}

void solve() {
    REP(i, n-1){
        if(i+1 < p[i]) g[i+1].push_back(p[i]), pa[p[i]] = i+1;
        else g[p[i]].push_back(i+1), pa[i+1] = p[i];
    }
    rec(0);
//    REP(i, n) OUT(pa[i]);
    sol(0);
    REP(i, n) cout << b[i] << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






