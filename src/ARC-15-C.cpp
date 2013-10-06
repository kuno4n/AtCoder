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

double g[250][250];

int n;
string l[210];
double m[210];
string s[210];

int N;


void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> l[i] >> m[i] >> s[i];
}





void solve() {
    set<string> ss;
    REP(i, n){
        ss.insert(l[i]);
        ss.insert(s[i]);
    }
    N = SZ(ss);
    
    map<string, int> ms;
    int im = 0;
    FIT(it, ss) ms[*it] = im++;
    
    MSET(g, 0);
    REP(i, N) g[i][i] = 1.0;
    REP(i, n){
        g[ms[l[i]]][ms[s[i]]] = m[i];
        g[ms[s[i]]][ms[l[i]]] = (1.0/m[i]);
    }
//    REP(k, N) REP(i, N) REP(j, N) if(g[i][j] == 0 && g[i][k] > 0 && g[k][j] > 0) g[i][j] = g[i][k] * g[k][j];
    REP(k, N) REP(i, N) REP(j, N) if(g[i][k] > 0 && g[k][j] > 0) chmax(g[i][j], g[i][k] * g[k][j]);
    
    int root;
    string root_s;
    int leaf;
    string leaf_s;
    double M;
    
    
    M = 0.0;
    REP(i, N) REP(j, N) if(g[i][j] > M){
        M = g[i][j];
        root = i;
        leaf = j;
    }
    FIT(it, ms){
        if((*it).second == root) root_s = (*it).first;
        if((*it).second == leaf) leaf_s = (*it).first;
    }
    
    cout << "1" << root_s << "=" << (LL)(M+0.000001) << leaf_s << endl;
    
    
}

int main() {
    init();
    input();
    solve();
}







