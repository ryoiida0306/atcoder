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
using mytpl = tuple<ll,int,int>;
int main(){
  int n,m;
  cin >> n >> m;
  vi k(m);
  vl c(m);
  vvi a(m);
  rep(i,m){
    cin >> k[i] >> c[i];
    rep(j,k[i]){
      int aa;
      cin >> aa;
      aa--;
      a[i].push_back(aa);
    }
  }
  dsu d(n);
  priority_queue<mytpl> pq;
  
  rep(i,m){
    rep(j,k[i]){
      if(!j)continue;
      pq.push(mytpl(-c[i],a[i][0],a[i][j]));
    }
  }
  ll ans = 0;
  while((int)pq.size()){
    ll cost;
    int v, u;
    tie(cost,v,u) = pq.top();pq.pop();
    if(d.same(v,u))continue;
    d.merge(v,u);
    ans -= cost;
  }
  // for(auto s : d.groups)
  if((int)d.groups().size() == 1)cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}