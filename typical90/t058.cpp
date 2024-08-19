#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (n); i > 0; --i)
using mint = modint998244353;
using mint2 = modint1000000007;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using vsi = vector<set<int>>;
using vsl = vector<set<ll>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int INF = 1001001001;
ll LINF = 1001001001001001001;
using mytpl = tuple<ll,int,int>;

int f(int x){
    int sum = 0;
    int tmp = x;
    while(tmp){
        sum += tmp % 10;
        tmp /= 10;
    }
    return (x + sum) % 100000;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vvi doubling(1e5, vi(60, -1));
    
    rep(j,60){
        rep(i,1e5){
            if(j == 0){
                doubling[i][j] = f(i);
            }else{
                doubling[i][j] = doubling[doubling[i][j-1]][j-1];
            }
        }
    }

    int now = n;
    int itr = 0;
    while(k){
        if(k % 2){
            now = doubling[now][itr];
        }
        itr++;
        k /= 2;
    }

    cout << now << endl;
    return 0;
}