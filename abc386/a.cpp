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
    vi a(5);
    rep(i,4) cin >> a[i];

    rep1(i, 13){
        vi b = a;
        b[4] = i;

        sort(b.begin(), b.end());

        int ok = 0;

        if((b[0] == b[1] && b[1] == b[2]) && (b[3] == b[4])){
            ok = 1;
        }
        if((b[0] == b[1]) && (b[2] == b[3] && b[3] == b[4])){
            ok = 1;
        }

        if(b[0] == b[1] && b[1] == b[2] && b[2] == b[3] && b[3] == b[4]){
            ok = 0;
        }

        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}