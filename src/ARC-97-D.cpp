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

const int MAX_N = 100010;
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


int n, m;
int p[100010];
int pos[100010];


void input() {
	cin >> n >> m;
	REP(i, n) {
		cin >> p[i];
		p[i]--;
		pos[p[i]] = i;
	}
}

void solve() {
	init(n);
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		unite(a-1, b-1);
	}
	int res = 0;
	REP(i, n) {
		if (same(i, pos[i])) res++;
	}
	cout << res << endl;
}

int main() {
	input();
	solve();
	return 0;
}
