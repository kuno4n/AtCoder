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


const int INF = (1<<30);


LL str2int(string s){
    LL res = 0;
    REP(i, SZ(s)){
        res *= 10;
        res += s[i]-'0';
    }
    return res;
}

int b, l, n;
string s;
string stk[1010];

void init() {
}

void input() {
    cin >> b >> l >> n >> s;
}

void solve() {
    int pt = 0, st = 0;
    REP(i, 1010) stk[i] = "";
    
    while(pt < n){
        if(s[pt] == '('){
            pt++;
            st++;
            stk[st] = "";
        }
        else if(s[pt] == ')'){
            pt++;
            st--;
            string pos = "";
            while(pt < n && s[pt] >= '0' && s[pt] <= '9'){
                pos += s[pt++];
            }
            int itr = str2int(pos);
            REP(_, itr) stk[st] += stk[st+1];
        }
        else{
            stk[st] += s[pt];
            pt++;
        }
    }
    
    int m = SZ(stk[0]);
    REP(i, l){
        cout << stk[0][(m+b+i)%m];
    }
    cout << endl;
    
}

int main() {
    init();
    input();
    solve();
}
