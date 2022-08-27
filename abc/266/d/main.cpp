#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/* alias */
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;

/* define short */
#define pb push_back
#define mp make_pair
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define rrepd(i,n) for(ll i=n;i>=1;i--)

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << endl;

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline string in_str() {string x; cin >> x; return x;}
// search_length: 走査するベクトル長の上限(先頭から何要素目までを検索対象とするか、1始まりで)
template <typename T> inline bool vector_finder(std::vector<T> vec, T element, unsigned int search_length) {
    auto itr = std::find(vec.begin(), vec.end(), element);
    size_t index = std::distance( vec.begin(), itr );
    if (index == vec.size() || index >= search_length) {return false;} else {return true;}
}
template <typename T> inline void print(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << "\n";}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}


int main() {
    int n;
    cin >> n;
    vi t(n), x(n), a(n);
    rep(i, n) cin >> t[i] >> x[i] >> a[i];

    int tmax = t[n-1];
    // cout << "tmax: " << tmax << endl;
    vvi points(tmax+1, vi(5, 0));
    rep(i, n) {
        points[t[i]][x[i]] = a[i];
        // cout << "ti: " << t[i] << ", xi: " << x[i] << ", ai: " << a[i] << endl;
    }

    vvll dp(tmax+1, vll(5, 0));
    reps(i, 1, 5) dp[0][i] = -1e18;
    dp[0][0] = points[0][0];

    reps(i, 1, tmax+1) {
        rep(j, 5) {
            if (j==0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + points[i][j];
            } else if (j==4) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + points[i][j];
            } else {
                dp[i][j] = max(max(dp[i-1][j], dp[i-1][j-1]), dp[i-1][j+1]) + points[i][j];
            }
        }
    }

    auto dp_last = dp[tmax];
    // print(dp_last);
    cout << *max_element(dp_last.begin(), dp_last.end()) << endl;

    return 0;
}

