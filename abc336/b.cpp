#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)

int main() {
  long long n;
  cin >> n;
  
  int ans = 0;
  while(1){
    if(n%2==0){
      n /= 2;
      ans++;
    }else{break;}
  }
  
  cout << ans << endl;
  
 
  return 0;
}