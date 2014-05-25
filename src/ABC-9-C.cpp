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

int n, k;
string s;

bool can(VI cnt1, VI cnt2, int k){
//    int cnt1[30], cnt2[30];
//    MSET(cnt1, 0), MSET(cnt2, 0);
//    int m = SZ(s1);
//    REP(i, n){
//        cnt1[s1[i]-'a']++;
//        cnt2[s2[i]-'a']++;
//    }
//    
    int diff = 0;
    REP(i, 26) diff += abs(cnt1[i]-cnt2[i]);
    return diff/2 <= k;
}

void init() {
}

void input() {
    cin >> n >> k;
    cin >> s;
}

void solve() {
    VI cnt(26, 0), cnt2(26, 0);
    REP(i, n) cnt[s[i]-'a']++;
    cnt2 = cnt;
    string res = "";
    
//    OUT(cnt);
    
    REP(_, n){
        char c = 'a'-1;
//        OUT(cnt);
//        OUT(cnt2);
        REP(i, 26) if(cnt[i] > 0){
            VI tmp1 = cnt;
            VI tmp2 = cnt2;
            tmp1[i]--;
            tmp2[s[_]-'a']--;
            if(i != s[_]-'a') k--;
            if(can(tmp1, tmp2, k)){
                
                cnt = tmp1;
                cnt2 = tmp2;
                c = i+'a';
                break;
            }
            if(i != s[_]-'a') k++;
        }
        res += c;
    }
    
    
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






