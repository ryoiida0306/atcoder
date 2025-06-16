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
using mytpl = tuple<int, ll>;
int main(){
    int n, m; cin >> n >> m;
    // vector<vector<ll>> g(n, vector<ll>(n, -1));
    vector<vector<pair<int,ll>>> g(n);
    vector<set<ll>> dist(n);
    // rep(i,n) g[i][i] = 0;
    rep(i,m){
        int a, b; ll w; cin >> a >> b >> w;
        a--; b--;
        g[a].emplace_back(b, w);
        // g[a][b] = w;
    }

    deque<mytpl> que; // (node, distance)

    que.push_back({0, 0});

    while(!que.empty()) {
        auto [v, d] = que.front();
        que.pop_front();
        if(dist[v].count(d)) continue; // already visited
        dist[v].insert(d);
        for(auto [to, w] : g[v]) {
            ll nd = d ^ w; // XOR distance
            if(dist[to].count(nd)) continue; // already visited
            que.push_back({to, nd});
        }
    }

    if(dist[n-1].empty()) {
        cout << -1 << endl;
    } else {
        ll ans = *dist[n-1].begin();
        cout << ans << endl;
    }

    return 0;


}