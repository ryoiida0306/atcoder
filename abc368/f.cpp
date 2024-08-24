#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (n); i > 0; --i)
using mint = modint998244353;
using mint2 = modint1000000007;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using vsi = vector<set<int>>;
using vsl = vector<set<ll>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int INF = 1001001001;
ll LINF = 1001001001001001001;
using mytpl = tuple<ll,int,int>;

set<int> divisor(int n){
    set<int> s;
    for(int i = 1; i*i <= n; ++i){
        if(n%i == 0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    return s;
}

int mex(set<int> s){
    int g = 0;
    while(s.count(g)) g++;
    return g;
}

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];

    vector<int> grundy_table(100010, -1);
    grundy_table[0] = 0;
    grundy_table[1] = 0;



    rep(i, 100010){
        if(i == 0 || i == 1) continue;
        set<int> s;
        for(auto x : divisor(i)){
            if(x == i) continue;
            s.insert(grundy_table[x]);
        }
        grundy_table[i] = mex(s);
    }

    int g = 0;
    rep(i,n){
        g ^= grundy_table[a[i]];
    }

    if(g == 0){
        cout << "Bruno" << endl;
    }else{
        cout << "Anna" << endl;
    }

    return 0;

}