#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)

bool tukureruka(vector<int> v, int h){
  int iter = 0;
  rep(iter,h){
    // cout << iter << endl;
    int amount = 1;
    int i = iter - h + 1;
    int j = iter + h - 1;
    if(i<0){continue;}
    if(j>v.size()){continue;}
    while(i != j){
    cout << i << " ";
    cout << j << endl;
      if(v.at(i) >= amount && v.at(j) >= amount){
        i++;
        j--;
        amount++;
      }else{break;}
    }
    if(i == j && v.at(i) == h){return true;}
  }
  return false;
  
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  bool ok = false;
  ok = tukureruka(a,h);
  rep(h,n){
    if(!tukureruka(a,h)){
      cout << h-1 << endl;
    }
  }
  return 0;
}


//ce