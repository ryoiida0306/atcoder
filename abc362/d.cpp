#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (n); i > 0; --i)
// #define all(a) (a).begin, (a).end()
using mint = modint998244353;
using mint2 = modint1000000007;
using ll = long long;
using P = pair<int,int>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int INF = 1001001001;
ll LINF = 1001001001001001001;
using mypair = pair<ll,int>;
//cost,id,

// void show(priority_queue<mypair> pq){
//   while((int)pq.size()){
//     mypair val = pq.top();pq.pop();
//     cerr << val.first << " " << val.second << endl;
//   }
//   cerr << endl;
// }

int main(){
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<set<pair<ll,ll>>> d(n);
  rep(i,n) cin >> a[i];
  rep(i,m){
    int u, v, b;
    cin >> u >> v >> b;
    u--;v--;
    d[u].insert(pair<ll,ll>(v,b));
    d[v].insert(pair<ll,ll>(u,b));
  }
  
  vector<ll> ans(n,0);
  vector<bool> G(n,false);
  
  priority_queue<mypair> pq;
  pq.push(mypair(-a[0],0));
  while((int)pq.size()){
    mypair now = pq.top();pq.pop();
    ll precost = -now.first;
    ll prev = now.second;
    if(G[prev])continue;
    ans[prev] = precost;
    G[prev] = true;
    for(pair<ll,ll> nowv : d[prev]){
      ll cost = nowv.second;
      ll v = nowv.first;
      // cerr << v << endl;
      if(G[v])continue;
      ll nextcost = precost + cost + a[v];
      // cerr << nextcost << endl;
      pq.push(mypair(-nextcost,v));
      // cerr << "---------" << endl;
      // show(pq);
    }
  }
  
  rep(i,n){
    if(i == 0)continue;
    cout << ans[i] << " ";
  }
  cout << endl;
  
  return 0;
}