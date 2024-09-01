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
using edge = tuple<int,int,ll>;

void chmin(ll& a, ll b){
    if(a > b) a = b;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> e(m);
    vvl dist(n, vl(n, LINF));

    rep(i,m){
        int u, v;
        ll t;
        cin >> u >> v >> t;
        u--; v--;
        e[i] = {u,v,t};
        chmin(dist[u][v], t);
        chmin(dist[v][u], t);
    }

    rep(i,n) dist[i][i] = 0;
    rep(k,n)rep(i,n)rep(j,n){
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<int> b(k);
        rep(i,k){
            cin >> b[i];
            b[i]--;
        }

        ll ans = LINF;
        do{
            rep(i, 1 << k){
                ll sum = 0;
                int s = 0;
                rep(j,k){
                    auto [u, v, t] = e[b[j]];
                    if(i >> j & 1){
                        swap(u, v);
                    }
                    sum += dist[s][u] + t;
                    s = v;
                }
                sum += dist[s][n-1];
                ans = min(ans, sum);
            }
        }while(next_permutation(b.begin(), b.end()));
        cout << ans << endl;
    }

    return 0;
}