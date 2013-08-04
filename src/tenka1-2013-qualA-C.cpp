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
int res;
int h, w;
int tab[110][110];

void dfs(int x, int y){
    if(x == h){
        res++;
        return;
    }
    
    for(int c = 1; c <= 3; c++){
        for(int i = 1; i <= c; i++) if(x >= i && tab[x-i][y] == c) goto dmp;
        for(int i = 1; i <= c; i++) if(y >= i && tab[x][y-i] == c) goto dmp;
        tab[x][y] = c;
        dfs(x+(y+1)/w, (y+1)%w);
    dmp:;
    }
    
}

void init() {
}

void input() {
    cin >> h >> w;
    if(h > w) swap(h, w);
    res = 0;
}

void solve() {
    if(h <= 100 && w <= 100){
        dfs(0, 0);
        cout << res << endl;
        return;
    }
    else if(h == 1){
        int ans[4] = {10, 9, 8, 9};
        cout << ans[w%4] << endl;
    }
    else{
        int ans[4] = {18, 20, 18, 16};
        cout << ans[(h+w)%4] << endl;
    }
    
}

int main() {
    init();
    input();
    solve();
}
