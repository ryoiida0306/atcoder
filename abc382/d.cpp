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

void generateSequences(int n, int length, vi& current, vvi& results) {
    if (length == 0) {
        if (n == 0) {
            results.push_back(current);
        }
        return;
    }
    
    for (int i = 0; i <= n; ++i) {
        current.push_back(i);
        generateSequences(n - i, length - 1, current, results);
        current.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int d = m - 10*(n-1);

    vi current;
    vvi results;

    
    rep(i, d){
        generateSequences(i, n, current, results);
    }

    sort(results.begin(), results.end());
    cout << (int)results.size() << endl;
    for (const auto& seq : results) {
        int acc = 1;
        int cnt = 0;
        for (int num : seq) {
            acc += num;
            cout << acc + cnt*10 << " ";
            cnt++;
        }
        cout << endl;
    }


    return 0;
}
