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
using P = pair<ll,ll>;
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
    ll n, m, x; cin >> n >> m >> x;
    // map<P,int> d;
    map<ll, set<P>> d;

    int invint = 1e6;
    rep(i,n){
        // d[P(i, i + invint)] = x;
        // d[P(i + invint, i)] = x;
        d[i].insert(P(i + invint, x));
        d[i + invint].insert(P(i, x));
    }

    rep(i,m){
        int u, v; cin >> u >> v;
        u--; v--;
        // d[P(u,v)] = 1;
        // d[P(invint + u, invint + v)] = 1;
        d[u].insert(P(v, 1));
        d[v + invint].insert(P(u + invint, 1));
    }

    // for(auto i : d){
    //     for(auto j : i.second){
    //         cout << i.first << " " << j.first << " " << j.second << endl;
    //     }
    // }

    int s = 0;
    priority_queue<P> q;
    vb visited(invint+n, false);
    q.push(P(0, s)); // cost, position

    while(!q.empty()){
        ll cost, v;
        tie(cost, v) = q.top();
        q.pop();
        cost *= -1;
        if(visited[v]) continue;
        visited[v] = true;
        if(v == n - 1 || v == n - 1 + invint){
            cout << cost << endl;
            return 0;
        }
        // cout << "v: " << v << " cost: " << cost << endl;
        for(auto nv : d[v]){
            ll u, costu;
            tie(u, costu) = nv;
            // cout << "costu: " << costu << " u: " << u << endl;
            if(visited[u]) continue;
            q.push(P(-(cost + costu), u));


        }
        // cout << endl;
    }

    cout << -1 << endl;

    return 0;



    


}