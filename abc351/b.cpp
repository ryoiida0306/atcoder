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
  int n;
  cin >> n;
 vector<string> A(n), B(n);
 rep(i,n){
   cin >> A[i];
 }
 rep(i,n) cin >> B[i];
 
 rep(i,n)rep(j,n){
   if(A[i][j] != B[i][j]){
     cout << i+1 << " " << j+1 << endl;
     return 0;
   }
 }
  return 0;
}
