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
  ll a , b , c;
  cin >> a >> b >> c;
  
  ll ab = gcd(a,b);
  ll abc = gcd(ab,c);
  
  cout << (a+b+c)/abc -3 <<endl;
  return 0;
}
