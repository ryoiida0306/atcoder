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

vector<int> add(vector<int> a, vector<int> b){
    vector<int> c((int)a.size());
    rep(i, (int)a.size()){
        c[i] = min(a[i] + b[i], 2);
    }
    return c;
}

map<vector<int>, ll> merge(map<vector<int>, ll> dp, map<vector<int>, ll> newdp){
    for(auto [key, value] : newdp){
        if(dp.find(key) == dp.end()){
            dp[key] = value;
        }else{
            dp[key] = min(dp[key], value);
        }
    }
    return dp;
}

int main(){
    int n, m; cin >> n >> m;
    vector<ll> costsub(n); rep(i, n) cin >> costsub[i];
    vector<ll> Cost(2*n); rep(i, n){
        Cost[2*i+0] = costsub[i];
        Cost[2*i+1] = costsub[i];
    }
    vector<vector<int>> parks(2*n, vector<int>(m,0));

    rep(i,m){
        int k; cin >> k;
        rep(j,k){
            int a; cin >> a; a--;
            // parks[a][2*i+0] = 1;
            // parks[a][2*i+1] = 1;
            parks[2*a+0][i] = 1;
            parks[2*a+1][i] = 1;
        }
    }

    // rep(i, (int)parks.size()){
    //     for(auto k : parks[i]){
    //         cerr << k << " ";
    //     }
    //     cerr << endl;
    // }

    map<vector<int>, ll> dp;
    dp[vector<int>(m,0)] = 0;

    rep(i, (int)parks.size()){
        map<vector<int>, ll> dp2;
        for(auto [key, value] : dp){
            vector<int> key2 = add(key, parks[i]);
            if(dp2.find(key2) == dp2.end()){
                dp2[key2] = value + Cost[i];
            }else{
                dp2[key2] = min(dp2[key2], value + Cost[i]);
            }
        }

        dp = merge(dp, dp2);
        // swap(dp, dp2);


        // for(auto [key, value] : dp){
        //     cout << "key: ";
        //     for(auto k : key) cout << k << " ";
        //     cout << "value: " << value << endl;
        // }
    }

    ll ans = dp[vector<int>(m, 2)];

    cout << ans << endl;




    return 0;



}