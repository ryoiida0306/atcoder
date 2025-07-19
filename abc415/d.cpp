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
    ll n, m; cin >> n >> m;
    map<ll, ll> mp; //residual , cost (a = cost, b = cost - residual)
    rep(i, m){
        ll a, b; cin >> a >> b;
        ll residual = a - b;
        if (mp.count(residual)) {
            mp[residual] = min(mp[residual], a);
        } else {
            mp[residual] = a;
        }
    }

    ll ans = 0;
    ll now = n;
    for (auto& [residual, cost] : mp) {
        if(cost > now) {
            continue; // Skip if residual is greater than current amount
        }
        ll stanps = (now - cost) / residual + 1; // Calculate the number of stamps needed
        now -= stanps * residual;
        ans += stanps;
    }

    cout << ans << endl;

    // debug
    // cout << "Debugging information:" << endl;
    // for (const auto& [residual, cost] : mp) {
    //     cout << "Residual: " << residual << ", Cost: " << cost << endl;
    // }
    // cout << "Final amount: " << now << endl;


    return 0;
}