#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<pair<int,vector<int>>> a(n);
  rep(i,n){
    a[i].first = i;
    rep(j,n){
      int ai;
      cin >> ai;
      a[i].second.push_back(ai);
    }
  }
  int m;
  cin >> m;
  vi x(m), y(m);
  rep(i,m) cin >> x[i] >> y[i];
  rep(i,m){
    x[i]--;
    y[i]--;
  }
  
  const int INF = 1001001001;
  int ans = INF;
  do{
    bool ok = true;
    rep(i,n-1){
      rep(j,m){
        // cout << x[j] << y[j] << a[i].first << a[i+1].first << endl;
        if(P(x[j],y[j]) == P(a[i].first,a[i+1].first)){
          ok = false;
          i = n;
          break;
        }
        if(P(x[j],y[j]) == P(a[i+1].first,a[i].first)){
          ok = false;
          i = n;
          break;
        }
      }
    }
    
    if(!ok)continue;
    int nowans = 0;
    rep(i,n){
      nowans += a[i].second[i];
    }
    ans = min(ans,nowans);
    
  }while(next_permutation(a.begin(),a.end()));
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}


