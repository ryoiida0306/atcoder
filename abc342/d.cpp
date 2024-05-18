#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i<(n); ++i)


int main() {
 int n;
 cin >> n;
 vector<int> a(n);
 
 rep(i,n){
   cin >> a[i];
 }
  
ll sum = 0;
int zeros = 0;
rep(i,n){
  if(a[i] == 0){
    zeros++;
  }
}
 
rep(i,n){
  if(a[i] == 0){
    a[i] = -1;
    continue;
  }
  rep(j,450){
    if(j == 0 || j == 1){continue;}
    while(a[i] >= (j*j)){
      if(a[i] % (j*j) == 0){
        a[i] = a[i]/(j*j);
      }else{break;}
    }
  }
}
 
vector<int> d(1000000);
 
rep(i,n){
  if(a[i] == -1){continue;}
  d[a[i]]++;
}

 
for(int i = 0 ; i < 1000000 ; i++){
  if(d[i] > 0){
    sum += d[i] * (d[i]-1) /2;
  }
}

sum += zeros * (n-1);
if(zeros>0)
sum -= zeros * (zeros-1) /2;


 
cout << sum << endl;
 
return 0;
 
}

//wa