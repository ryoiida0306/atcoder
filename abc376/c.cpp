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
    int n;
    cin >> n;
    vi a(n), b(n-1);
    rep(i,n) cin >> a[i];
    rep(i,n-1) cin >> b[i];
    b.push_back(0);

    vb flag(n, false);


    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int dul = 0;
    int x = -1;

    for(int i = n-1; i >= 0; i--){
        if(a[i - dul] <= b[i]){
            flag[i] = true;
        }else{
            if(dul == 0){
                dul = 1;
                x = a[i];
                i++;
                continue;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }
        // cerr << dul << " " << x << endl;
    }

    
    // for(auto f: flag){
    //     cerr << f << " ";
    // }
    // cerr << endl;

    cout << x << endl;

    return 0;

}