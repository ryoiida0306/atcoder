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
  string s;
  cin >> s;
  int ss = s.size();
  if(s[0] != '<') {cout << "No" << endl;return 0;}
  if(s[ss-1] != '>') {cout << "No" << endl;return 0;}
  for(int i = 1; i<ss-1;i++){
    if(s[i] != '=') {cout << "No" << endl;return 0;}
  }
  
  
  cout << "Yes" << endl;
  return 0;
  
}
