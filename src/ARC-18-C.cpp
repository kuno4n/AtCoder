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
LL g[1010][1010];
pair<LL, pair<LL, LL> > tmp[1000010];
pair<LL, pair<LL, LL> > G[1010][1010];
LL x, a, p;

void init() {
}

void input() {
    cin >> n >> m >> x >> a >> p;
    REP(i, n) REP(j, m){
        if(i == 0 && j == 0){
            g[i][j] = x;
        }
        else{
            if(j == 0) g[i][j] = (g[i-1][m-1] + a) % p;
            else g[i][j] = (g[i][j-1] + a) % p;
        }
    }
}

void solve() {
    LL res = 0;
    REP(i, n) REP(j, m) tmp[i*m + j] = make_pair(g[i][j], make_pair(i, j));
    sort(tmp, tmp+n*m);
    REP(i, n) REP(j, m) G[i][j] = tmp[i*m + j];
    REP(i, n){
        REP(j, m) res += abs(i-G[i][j].second.first);
        VI vi;
        REP(j, m) vi.push_back(G[i][j].second.second);
        sort(ALL(vi));
        REP(j, m) res += abs(j-vi[j]);
    }
    
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






