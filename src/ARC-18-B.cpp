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
LL x[110], y[110];

void init() {
}

void input() {
    cin >> n;
    REP(i, n){
        cin >> x[i] >> y[i];
    }
}

void solve() {
    int res = 0;
    REP(i, n) FOR(j, i+1, n) FOR(k, j+1, n){
        LL ax = x[j]-x[i];
        LL bx = x[k]-x[i];
        LL ay = y[j]-y[i];
        LL by = y[k]-y[i];
        LL s = abs(ax*by - bx*ay);
        if(!(s&1) && s != 0) res++;
    }
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






