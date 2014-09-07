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

int n, k, x[100010];
int a[100010];
bool chk[100010];

void init() {
    MSET(chk, false);
}

void input() {
    cin >> n >> k;
    REP(i, n) cin >> x[i];
    REP(i, n) a[x[i]] = i+1;
}

void solve() {
    int i = 0, ptr = 0;
    for(; i < k; i++){
        chk[x[i]] = true;
        if(x[i] > ptr) ptr = x[i];
    }
    
    cout << a[ptr] << endl;
    for(; i < n; i++){
        chk[x[i]] = true;
        if(x[i] < ptr){
            ptr--;
            while(!chk[ptr]) ptr--;
        }
        cout << a[ptr] << endl;
    }
}

int main() {
	init();
    input();
    solve();
	return 0;
}






