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
int main(){
    int n, m;
    cin >> n >> m;

    vi a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    vi mapping(2000010, -1);

    int idx = 0;
    rrep(deliciousy,(int)mapping.size()){
        while(a[idx] > deliciousy){
            if(idx == n-1) break;
            idx++;
        }
        if(a[idx] <= deliciousy){
            mapping[deliciousy] = idx;
        }
    }

    rep(i,m){
        if(mapping[b[i]] == -1){
            cout << -1 << endl;
        }else{
            cout << mapping[b[i]] + 1 << endl;
        }
    }

    return 0;


}