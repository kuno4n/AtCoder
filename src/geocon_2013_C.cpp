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

double EPS = 1e-10;

double add(double a, double b){
    if(abs(a+b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
}

struct P{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y){
    }
    P operator + (P p){
        return P(add(x, p.x), add(y, p.y));
    }
    P operator - (P p){
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator * (double d){
        return P(x*d, y*d);
    }
    double dot(P p){ // 内積
        return add(x*p.x, y*p.y);
    }
    double det(P p){ // 外積
        return add(x*p.y, -y*p.x);
    }
};

bool intersect(P p1, P p2, P p3, P p4){
    double t1 = (p1.x - p2.x) * (p3.y - p1.y) + (p1.y - p2.y) * (p1.x - p3.x);
    double t2 = (p1.x - p2.x) * (p4.y - p1.y) + (p1.y - p2.y) * (p1.x - p4.x);
    double t3 = (p3.x - p4.x) * (p1.y - p3.y) + (p3.y - p4.y) * (p3.x - p1.x);
    double t4 = (p3.x - p4.x) * (p2.y - p3.y) + (p3.y - p4.y) * (p3.x - p2.x);
    if(t1*t2 <= 0 && t3*t4 <= 0) return true;
    return false;
}

bool cmp_x(const P& p, const P& q){
    if(p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}



vector<P> convex_hull(P* ps, int n){
    sort(ps, ps+n, cmp_x);
    int k = 0;
    vector<P> qs(n*2);
    REP(i, n){
        while(k>1 && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    for(int i=n-2, t=k; i>=0; i--){
        while(k>t && (qs[k-1] - qs[k-2]).det(ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}


LL ccw(P p1, P p2, P p3){
    return (p2-p1).det(p3-p1);
}

bool on_seg(P p1, P p2, P q){
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}



int n;
P ps[1010]; int m;

void init() {
}

void input() {
    cin >> n;
}



void solve() {
    vector<P> qs;
    m = 0;
    REP(num, n){
        string s; double x, y;
        cin >> s >> x >> y;
        if(s == "MONITOR"){
            ps[m++] = P(x, y);
            qs = convex_hull(ps, m);
        }
        else{
            int qn = SZ(qs);
            bool ok = true;
            REP(i, qn){
                if(on_seg(qs[i], qs[(i+1)%qn], P(x, y))) ok = false;
            }
            if(qn >= 3){
                double cc = ccw(qs[qn-1], qs[0], P(x, y));
                bool all = true;
                REP(i, qn-1) if(cc * ccw(qs[i], qs[i+1], P(x, y)) <= 0) all = false;
                if(all) ok = false;
            }
            if(ok) cout << "SAFE" << endl;
            else cout << "DANGER" << endl;
        }
    }
}

int main() {
	init();
    input();
    solve();
	return 0;
}






