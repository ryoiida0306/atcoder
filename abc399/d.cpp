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
        int ans = 0;
        int n; cin >> n;
        vi a(2*n); rep(i,2*n) cin >> a[i];

        map<P, vector<int>> mp;

        rep(i,2*n-1){
            int x1 = a[i];
            int x2 = a[i+1];
            if(x1 > x2) swap(x1,x2);
            mp[{x1,x2}].push_back(i);
        }

        for(auto p : mp){
            if((int)p.second.size() == 3){
                ans++;
                continue;
            }
            if((int)p.second.size() < 2) continue;
            int i = p.second[0];
            int j = p.second[1];
            if(i > j) swap(i,j);
            cerr << "i: " << i << " j: " << j << endl;
            if(j-i == 1) continue;
            if(j-i > 2){
                ans++;
                continue;
            }

            // if(j-i == 2) cout << "error" << endl;
            //1331
        }

        cout << ans << endl;
    }

    return 0;


}