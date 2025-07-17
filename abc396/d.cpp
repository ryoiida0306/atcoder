#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <atcoder/all>
using namespace atcoder;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
using ll = long long;
using P = pair<int, ll>;
const ll LINF = 1LL << 60; // INFを大きくする

int main(){
    ll n, m; 
    cin >> n >> m;
    vector<vector<P>> d(n);
    
    rep(i, m){
        ll u, v, w; 
        cin >> u >> v >> w;
        --u, --v;
        d[u].push_back({v, w});
        d[v].push_back({u, w});
    }

    ll ans = LINF;
    queue<tuple<ll, ll, bitset<60>>> q;
    q.push({0, 0, bitset<60>().set(0)}); // 初期状態

    while(!q.empty()){
        auto [u, res, visited] = q.front();
        q.pop();

        if(u == n - 1){
            ans = min(ans, res);
            continue;
        }

        for(auto [v, w] : d[u]){
            if(visited.test(v)) continue;
            bitset<60> next_visited = visited;
            next_visited.set(v);
            q.push({v, res ^ w, next_visited});
        }
    }

    cout << (ans == LINF ? -1 : ans) << endl;
    return 0;
}
