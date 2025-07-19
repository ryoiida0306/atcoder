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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vb f(1<<n, false);

        rep(i, 1 << n){
            if(i == 0){
                f[i] = true;
                continue;
            }
            if(s[i-1] == '1'){
                // f[i] = false;
                continue;
            }

            // cout << "Processing subset: " << i << endl;

            rep(j, n){
                if(i >> j & 1){
                    if(f[i ^ (1 << j)]){
                        // cout << "i: " << i << ", j: " << j << ", f[i ^ (1 << j)]: " << (i ^ (1 << j)) << endl;
                        f[i] = true;
                        break;
                    }
                }
            }

        }

        cout << (f[(1 << n) - 1] ? "Yes" : "No") << endl;
        // Debugging output
        // rep(i, 1 << n) {
        //     cout << "f[" << i << "] = " << f[i] <<
        // endl;
        // }

    }

    return 0;
}