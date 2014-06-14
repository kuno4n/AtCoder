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
int a[100010];
VI b;

void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> a[i];
}

void solve() {
    int s = 0;
    REP(i, n) s += a[i];
    if(s == 0 || s == n){
        cout << -1 << endl;
        return;
    }
    
    b.clear();
    int cnt = 0;
    int now = -1;
    REP(i, n){
        if(i != 0 && a[i] != now){
            b.push_back(cnt);
            cnt = 0;
        }
        cnt++;
        now = a[i];
    }
    b.push_back(cnt);
    if(a[0] == a[n-1]) b.push_back(b[0] + b[SZ(b)-1]);
    
    int mx = 0;
    REP(i, SZ(b)) chmax(mx, b[i]);
    cout << (mx - 1) / 2 + 1 << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






