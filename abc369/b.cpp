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
    bool l = false;
    bool r = false;
    int li = 0;
    int ri = 0;
    int cost = 0;
    rep(i,n){
        int a;
        cin >> a;
        char c;
        cin >> c;
        if(c == 'L' && !l){
            l = true;
            li = a;
            continue;
        }
        if(c == 'R' && !r){
            r = true;
            ri = a;
            continue;
        }

        if(c == 'L'){
            cost += abs(a - li);
            li = a;
            continue;
        }

        if(c == 'R'){
            cost += abs(a - ri);
            ri = a;
            continue;
        }

    }
    cout << cost << endl;
    return 0;
}