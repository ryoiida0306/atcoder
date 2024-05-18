#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
// #define all(a) (a).begin, (a).end()
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

using mytpl = tuple<ll,int,int,int>;
vl dijkstra(int n, vsi d, map<P, ll> c, int s){
  vl ans(n);ans[s] = 0;
  priority_queue<pair<ll,int>> Q;
  vb G(n, false);
  Q.push(pair<ll,int>(0,s));
  while((int)Q.size()){
    auto [cost, v] = Q.top();Q.pop();
    if(G[v])continue;
    G[v] = true;
    ans[v] = -cost;
    for(auto u : d[v]){
      if(G[u])continue;
      Q.push(pair<ll,int>(cost-c[P(v,u)], u));
    }
  }
  return ans;
}

int main(){
  int n, k;
  cin >> n >> k;
  priority_queue<int> pq;
  rep(i,n){
    int a, b;
    cin >> a >> b;
    pq.push(b);
    pq.push(a-b);
  }
  ll ans = 0;
  rep(i,k){
    ans += pq.top();pq.pop();
  }
  cout << ans << endl;
  return 0;
}