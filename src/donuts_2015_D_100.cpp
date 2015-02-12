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


const int N = (1<<18);
int cnt[N<<1], sum[N<<1];

void add(int i , int x){ // 数iをx個、数列に加える
	i += N;
	cnt[i] += x;
	sum[i] += (i-N)*x;
	i >>= 1;
	while(i){
		cnt[i] = cnt[i<<1] + cnt[i<<1|1];
		sum[i] = sum[i<<1] + sum[i<<1|1];
		i >>= 1;
	}
}

int ksum(int k){ // 数列の小さい方からk個の和を求める
	int i = 1, res = 0;
	while(i < N){
		int l = i<<1, r = l|1;
		if(cnt[l] <= k){
			res += sum[l];
			k -= cnt[l];
			i = r;
		}
		else i = l;
	}
	res += (i-N) * k;
	return res;
}

int n, k;
int c[200010];
int q;
int d[200010];

void init() {
}

void input() {
	cin >> n >> k;
	REP(i, n) cin >> c[i];
	cin >> q;
	REP(i, q){
		cin >> d[i];
		d[i]--;
	}
}

set<int> s;
multiset<int> ms;
void solve() {
	REP(i, n) s.insert(c[i]);
	int pre = -1;
	MSET(cnt, 0), MSET(sum, 0);
	FIT(it, s){
		if(pre != -1){
			// ms.insert(*it - pre);
			add(*it-pre, 1);
		}
		pre = *it;
	}
	cout << ksum(n-k) << endl;
	REP(i, q){
		auto it = s.find(c[d[i]]);
		auto jt = it;
		int pre = -1;
		int nxt = -1;
		if(it != s.begin()){
			jt--;
			pre = *it - *jt;
			// ms.erase(ms.find(pre));
			add(pre, -1);
			jt++;
		}
		jt++;
		if(jt != s.end()){
			nxt = *jt - *it;
			// ms.erase(ms.find(nxt));
			add(nxt, -1);
		}
		s.erase(it);
		// if(pre != -1 && nxt != -1) ms.insert(nxt+pre);
		if(pre != -1 && nxt != -1) add(nxt+pre, 1);
		// else if(pre != -1) sum -= pre;
		// else if(nxt != -1) sum -= nxt;
		cout << ksum(n-k-i-1) << endl;
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}






