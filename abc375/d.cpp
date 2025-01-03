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
int main(){
    string s;
    cin >> s;

    map<char, vi> mp;
    rep(i,(int)s.size()){
        mp[s[i]].push_back(i);
    }

    ll ans = 0;

    for(auto p : mp){
        vi v = p.second;
        int n = (int)v.size();

        ll res = 0;
        rep(i,n-1){
            res += (ll)(v[i+1] - v[i] - 1) * (i+1) * (n-(i+2)+1);
        }
        rep(i,n){
            res += (ll)i * ((n-1) - i);
        }

        cerr << p.first << " " << res << endl;

        ans += res;
    }

    cout << ans << endl;
    return 0;
}