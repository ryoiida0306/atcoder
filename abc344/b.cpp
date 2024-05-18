#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  deque<int> a;
  
  while(1){
    int n;
    cin >> n;
    if(!n) break;
    a.push_front(n);
  }
  cout << 0 << endl;
  while(a.size()){
    cout << a.front() << endl;
    a.pop_front();
  }
  return 0;
}
