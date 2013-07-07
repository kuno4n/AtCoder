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

int INF = (1<<29);
int dist[350][350];

int m;
int a[6];
int s, g;
int n[350];	

void init() {
}

void input() {
	cin >> m;
	REP(i, 6) cin >> a[i];
	cin >> s >> g; s--; g--;
	REP(i, m) cin >> n[i];
	
	
	
}

bool can(int pt){
	return (pt >= 0 && pt < m);
}

void solve() {
	REP(i, 350) REP(j, 350) dist[i][j] = (i == j ? 0 : INF);
	
	REP(i, m) REP(j, 6){
		int p1 = i + a[j];
		if(can(p1)) chmin(dist[i][p1+n[p1]], 1);
		int p2 = i - a[j];
		if(can(p2)) chmin(dist[i][p2+n[p2]], 1);
	}
	REP(k, m) REP(i, m) REP(j, m) chmin(dist[i][j], dist[i][k] + dist[k][j]);
	
	while(s != g){
		int dice;
		scanf("%d", &dice); dice--;
		int p1 = s + a[dice];
		int p2 = s - a[dice];
		
		int out = 0, d = dist[s][g];
		if(can(p1) && d > dist[p1+n[p1]][g]) out =  1, d = dist[p1+n[p1]][g], s = p1+n[p1];
		if(can(p2) && d > dist[p2+n[p2]][g]) out = -1, d = dist[p2+n[p2]][g], s = p2+n[p2];
		printf("%d\n", out); fflush(stdout);
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}






