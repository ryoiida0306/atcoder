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
    ll n; cin >> n;

    // unordered_set<ll> anss;

    ll ans = 0;


    for(ll a = 1; a <= 60; a++){
        ll tmp = n / (1LL << a);
        if(tmp == 0) break;

        ll l = 1, r = 1e9+1;
        while(r - l > 1LL){
            ll m = (l + r) / 2LL;
            // cout << m << endl;
            if(m * m <= tmp) l = m;
            else r = m;
        }

        // rep1(b, l){
            // cout << pow(2, a) * b * b << endl;
            // anss.insert(pow(2, a) * b * b);
        // }

        ans += (l+1) /2;
    }

    // cout << (ll)anss.size() << endl;
    cout << ans << endl;

    return 0;

}