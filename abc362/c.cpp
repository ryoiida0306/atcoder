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
using mytpl = tuple<P,int>;

int main(){
  int n;
  cin >> n;
  vector<ll> l(n),r(n),ans(n);
  rep(i,n) cin >> l[i] >> r[i];
  rep(i,n) ans[i] = l[i];
  ll limit = 0;
  vector<ll> delta(n);
  rep(i,n){
    delta[i] = r[i] -l[i];
    limit += r[i] -l[i];
  }
  ll sum = 0;
  rep(i,n) sum += l[i];
  bool ok = false;
  if(sum <= 0 && sum+limit >= 0) ok =true;
  
  ll del = -sum;
  if(ok)rep(i,n){
    if(del <= 0)break;
    if(del >= delta[i]){
      ans[i] += delta[i];
      del -= delta[i];
    }else{
      ans[i] += del;
      del = 0;
    }
  }
  
  if(ok){
    cout << "Yes" << endl;
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
  }else{
    cout << "No" << endl;
  }
  
  return 0;
}