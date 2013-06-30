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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

struct P{
    LL x, y;
    P() {}
    P(LL x, LL y) : x(x), y(y){
    }
    P operator + (P p){
        return P(x+p.x, y+p.y);
    }
    P operator - (P p){
        return P(x-p.x, y-p.y);
    }
    P operator * (LL d){
        return P(x*d, y*d);
    }
    LL dot(P p){ // 内積
        return x*p.x + y*p.y;
    }
    LL det(P p){ // 外積
        return x*p.y - y*p.x;
    }
};

bool cmp_x(const pair<P, int>& p, const pair<P, int>& q){
    if(p.first.x != q.first.x) return p.first.x < q.first.x;
    return p.first.y < q.first.y;
}


pair<P, int> ps[300];

void init() {
}

void input() {
    int x, y;
    REP(i, 300) {
        cin >> x >> y;
        ps[i] = make_pair(P(x, y), i+1);
    }
    sort(ps, ps+300, cmp_x);
}

void solve() {
    cout << 100 << endl;
    REP(i, 300){
        cout << ps[i].second;
        if(i%3 != 2) cout << " ";
        else cout << endl;
    }
}

int main() {
	init();
    input();
    solve();
	return 0;
}






