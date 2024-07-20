#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (n); i > 0; --i)
// #define all(a) (a).begin, (a).end()
using ll = long long;
using P = pair<int,int>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int INF = 1001001001;
ll LINF = 1001001001001001001;
using mytpl = tuple<P,int>;
int main(){
  int n, t, p;
  cin >> n >> t >> p;
  vector<int> l(n);
  rep(i,n) cin >> l[i];
  sort(l.begin(),l.end());
  reverse(l.begin(),l.end());
  int lp = l[p-1];
  int ans = max(0,t-lp);
  cout << ans << endl;
  return 0;
}