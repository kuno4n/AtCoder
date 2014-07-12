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



const int MAX_N = 1000;
int par[MAX_N];  //親
int _rank[MAX_N]; //木の深さ

// n要素で初期化
void init(int n){
    REP(i, n){
        par[i] = i;
        _rank[i] = 0;
    }
}
//木の根を求める
int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}
//xとyの属する集合を結合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(_rank[x] < _rank[y]) par[x] = y;
    else{
        par[y] = x;
        if(_rank[x] == _rank[y]) _rank[x]++;
    }
}
//xとyが同じ集合に属するか
bool same(int x, int y){
    return find(x) == find(y);
}


int n, m, q;
int c[210], d[210];

bool onaji[40010];
int ptr;


void init() {
}

void input() {
    cin >> n >> m >> q;
    REP(i, q){
        cin >> c[i] >> d[i];
        c[i]--;
        d[i]--;
        d[i] += n;
    }
}

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

long long lcm(long long a, long long b){
    return a*b/gcd(a,b);
}

bool NG(){
    bool ape[1010]; MSET(ape, false);
    REP(i, n+m) ape[find(i)] = true;
    int cnt = 0;
    REP(i, 1010) if(ape[i]) cnt++;
    if(cnt == 1) return true;
    return false;
}

void upd(){ // return : 上下に繋がってる点
    int tmp = ptr;
    while(1){
        tmp--;
        if(tmp < 0) break;
        if(!same(tmp%n, tmp%m+n)) break;
    }
    ptr = tmp + 1;
}

void solve() {
    init(n+m);
    REP(i, q) unite(c[i], d[i]);
    int cnt = 0;
    int a = 0;
    int b = 0;
    int l = lcm(n, m);
    
    ptr = l;
    upd();
    if(ptr == 0){
        cout << 0 << endl;
        return;
    }
    
    while(1){
        if(cnt == l-1) break;
//        if(NG()) break;
        unite(a, b+n);
        upd();
        if(ptr <= cnt) break;
        a = (a+1) % n;
        b = (b+1) % m;
        cnt++;
    }
    cout << cnt+1 << endl;
}

int main() {
    init();
    input();
    solve();
}







