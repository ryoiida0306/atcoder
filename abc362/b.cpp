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

int dot(int a, int b, int c, int d){
  return a*c+b*d;
}

bool f(int x0, int y0, int x1, int y1, int x2, int y2){
  int X1 = x1 -x0;
  int Y1 = y1 -y0;
  int X2 = x2 -x0;
  int Y2 = y2 -y0;
  int nowdot = dot(X1,Y1,X2,Y2);
  if(nowdot == 0) return true;
  return false;
}


int main(){
  int xa,ya,xb,yb,xc,yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  bool ok = false;
  ok = ok || f(xa,ya,xb,yb,xc,yc);
  ok = ok || f(xb,yb,xc,yc,xa,ya);
  ok = ok || f(xc,yc,xa,ya,xb,yb);
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}