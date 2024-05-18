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
  int t;
  cin >> t;
  int l,x,y;
  cin >> l >> x >> y;
  int q;
  cin >> q;
  const double pi = 3.14159265358979;
  rep(i,q){
    int e;
    cin >> e;
    e = e%t;
    double a = (double)360/t*e;
    a = a/360*2*pi;
    double ya = (double)l/2*(-sin(a));
    double za = (double)l/2*(1-cos(a));
    cerr << ya << " " << za << endl;
    double A = abs(0-x);
    double B = abs(y-ya);
    double C = abs(0-za);
    double ans = 180/pi*acos(sqrt((A*A+B*B)/(A*A+B*B+C*C)));
    printf("%.12lf",ans);
    cout << endl;
  }
  return 0;
}


