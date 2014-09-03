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



//const int MAX_V = 110;
//
//struct edge {int to, cap, rev;};
//vector <edge> G[MAX_V];
//bool used[MAX_V];
//
//int INF = (1<<30);
//
//void add_edge(int from, int to, int cap){
//    G[from].push_back((edge){to, cap, SZ(G[to])});
//    G[to].push_back((edge){from, 0, SZ(G[from])-1});
//}
//
//int dfs(int v, int t, int f){
//    if (v == t) return f;
//    used[v] = true;
//    for(int i = 0; i < SZ(G[v]); i++){
//        edge &e = G[v][i];
//        if(!used[e.to] && e.cap > 0){
//            int d = dfs(e.to, t, min(f, e.cap));
//            if(d > 0){
//                e.cap -= d;
//                G[e.to][e.rev].cap += d;
//                return d;
//            }
//        }
//    }
//    return 0;
//}
//
//int max_flow(int s, int t){
//    int flow = 0;
//    while(1){
//        memset(used, 0, sizeof(used));
//        int f = dfs(s, t, INF);
//        if(f == 0) return flow;
//        flow += f;
//    }
//}




const int MAX_V = 10000;

struct edge {int to, cap, rev;};
vector <edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

int INF = (1<<29);

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, SZ(G[to])});
    G[to].push_back((edge){from, 0, SZ(G[from])-1});
}

void bfs(int s){
    MSET(level, -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(SZ(que)){
        int v = que.front(); que.pop();
        REP(i, SZ(G[v])){
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f){
    if (v == t) return f;
    for(int &i = iter[v]; i < SZ(G[v]); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    while(1){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
}





int n, g, e;
int p[110];
int a[10000], b[10000];

void init() {
}

void input() {
    cin >> n >> g >> e;
    REP(i, g) cin >> p[i];
    REP(i, e) cin >> a[i] >> b[i];
}

void solve() {
    REP(i, e) add_edge(a[i], b[i], 1), add_edge(b[i], a[i], 1);
    REP(i, g) add_edge(p[i], n, 1);
    cout << max_flow(0, n) << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






