#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<string> S;
  for(int tmp = 0;tmp<(1 << n) ;tmp++){
    bitset<20> b(tmp);
    int sum = 0;
    string s;
    bool ok = true;
    rep(i,n){
      if(b.test(i)){
        sum++;
        s = s + "(";
      }else{
        sum--;
        s = s + ")";
      }
      if(sum <0){
        ok = false;
        break;
      }
    }
    if(ok && sum == 0) S.push_back(s);
    
  }
  sort(S.begin(),S.end());
  for(string s: S){
    cout << s << endl;
  }
  return 0;
}
