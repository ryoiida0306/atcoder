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

void show(deque<int> a){
  while((int)a.size()){
    int b = a.front();a.pop_front();
    cerr << b << " ";
  }
  cerr << endl;
}

int main(){
  int n, q;
  cin >> n >> q;
  deque<int> a;
  rep(i,n){
    int aa;
    cin >> aa;
    a.push_back(aa);
  }
  rep(i,q){
    // show(a);
    int t,x,y;
    cin >> t >> x >> y;
    x--; y--;
    if(t == 1){
      switch(a[x],a[y]);
      int tmp = a[x];
      a[x] = a[y];
      a[y] = tmp;
      // cout << a[x] << a[y] << endl;
      continue;
    }
    if(t == 2){
      int aa = a.back();a.pop_back();a.push_front(aa);
      continue;
    }
    if(t == 3){
      cout << a[x] << endl;
      continue;
    }
  }
  show(a);
  return 0;
}