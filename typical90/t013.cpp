#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<set<pair<int,ll>>> d(n);
  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    d[a].insert(pair<int,ll>(b,c));
    d[b].insert(pair<int,ll>(a,c));
  }
  const ll INF = 1001001001001001001;
  vector<ll> from_1(n,INF);
  vector<ll> from_n(n,INF);
  
  auto djkstra = [&](int p) -> vector<ll> {
    vector<ll> from_p(n,INF);
    priority_queue<pair<ll,int>> PQ;
    PQ.push(pair<ll,int>(-0,p));
    // from_p[p] = 0;
    while(!PQ.empty()){
      // priority_queue<pair<ll,int>> tmp = PQ;
      // while(!tmp.empty()){
      //   cerr << tmp.top().second << " " << tmp.top().first << endl;
      //   tmp.pop();
      // }
      // cerr << endl;
      int v;
      ll c;
      tie(c,v) = PQ.top();
      PQ.pop();
      if(from_p[v] != INF)continue;
      from_p[v] = -c;
      for(auto u : d[v]){
        if(from_p[u.first] != INF) continue;
        PQ.push(pair<ll,int>(c-u.second,u.first));
      }
    }
    return from_p;
  };
  
  from_1 = djkstra(0);
  from_n = djkstra(n-1);
  
  rep(i,n){
    cout << from_1[i] + from_n[i] << endl;
    // cout << from_n[i] << endl;
  }
  return 0;
}


