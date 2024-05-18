#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
using mint = modint998244353;
using mint2 = modint1000000007;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n,c;
  cin >> n >> c;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> sum(n+1);
  rep(i,n+2) sum[i] = 0;
  rep(i,n) sum[i+1] = sum[i] + a[i];
  
  int s = -1;
  int t = -1;
  
  if(c>0){
    ll maxsum = 0;
    int snow = 0;
    int tnow = 0;
    for(int i = 0;i<=n;i++){
      tnow++;
      ll nowsum = sum[tnow] - sum[snow];
      if(maxsum<nowsum){
        s = snow;t=tnow-1;
        maxsum = nowsum;
      }
      if(nowsum<0){
        snow = i;tnow = i;
      }
    }
    cerr << maxsum << endl;
  }else{
    ll minsum = 0;
    int snow = 0;
    int tnow = 0;
    for(int i = 0;i<=n;i++){
      tnow++;
      ll nowsum = sum[tnow] - sum[snow];
      if(minsum>nowsum){
        s = snow;t=tnow-1;
        minsum = nowsum;
      }
      if(nowsum>0){
        snow = i;tnow = i;
      }
    }
    cerr << minsum << endl;
  }
  
  cerr << s << " " << t << endl;
  
  ll ans = 0;
  rep(i,n){
    if(s<=i&&i<=t){
      ans += a[i] *c;
    }else{
      ans += a[i];
    }
  }
  
  cout << ans << endl;
  return 0;
}
