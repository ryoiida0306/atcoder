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
        set<int> s;
        int s0; cin >> s0;
        rep(i, n-2){
            int x; cin >> x;
            s.insert(x);
        }
        s.insert(-1);
        s.insert(INF);
        int sn; cin >> sn;

        int nowsize = s0;
        int ans = 0;
        while(nowsize*2 < sn){
            auto it = s.upper_bound(nowsize * 2);
            it--;
            if(*it == -1 || it == s.end()){
                ans = -3;
                break;
            }
            nowsize = *it;
            s.erase(it);
            // cout << nowsize << " ";
            ans++;
        }
        cout << ans+2 << endl;
    }
}