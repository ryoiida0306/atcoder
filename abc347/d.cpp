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
  ll a, b, c;
  cin >> a >> b >> c;
  // bitset<60> ab = a;
  // bitset<60> bb = b;
  bitset<60> cb = c;
  ll c1 = 0;
  rep(i,60){
    if(cb.test(i)) c1++;
  }
  if((a+b-c1)%2 == 1){
    cout << -1 << endl;
    return 0;
  }
  if((a-b+c1)%2 == 1){
    cout << -1 << endl;
    return 0;
  }
  
  vi xb, yb;
  ll m = (a+b-c1)/2;
  ll n = (a-b+c1)/2;
  // cerr << m << " " << n << endl;
  // cerr << cb << endl;
  rep(i,60){
    if(cb.test(i)){
      int nn = (n>0) ? 1 : 0;
      xb.push_back(nn);
      yb.push_back(1-nn);
      n--;
    }else{
      int mm = (m>0) ? 1 : 0;
      // cerr <<  << endl;
      xb.push_back(mm);
      yb.push_back(mm);
      m--;
    }
    
    
    
  }
  vector<ll> pow2(60);
  pow2[0] = 1;
  rep(i,59){
    pow2[i+1] = pow2[i]*2;
  }
  
  ll X = 0;
  ll Y = 0;
  rep(i,60){
    X += xb[i]*pow2[i];
    Y += yb[i]*pow2[i];
  }
  int xc = 0;
  int yc = 0;
  rep(i,60){
    if(xb[i])xc++;
  }
  rep(i,60){
    if(yb[i])yc++;
  }
  
  vi cbb;
  rep(i,60){
    cbb.push_back(xb[i] ^ yb[i]);
  }
  ll ccbb = 0;
  rep(i,60){
    ccbb += cbb[i]*pow2[i];
  }
  
  
  if(xc!=a||yc!=b){
    cout << -1 << endl;
    return 0;
  }
  
  if(ccbb != c){
    cout << -1 << endl;
    return 0;
  }
  

  
  cout << X << " "<< Y << endl;
  return 0;
}


