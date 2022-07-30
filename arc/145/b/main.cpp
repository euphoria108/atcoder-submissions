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
    ll n, a, b;
    cin >> n >> a >> b;

    // n=7, a=3, b=2
    // a=3 b=4
    // a=6 b=0(lose)
    // 相手の数以下の石を残せれば勝ち
    // a, b の大小で場合わけ
    // case1: a > b
    //   when n < a; a loses
    //   when n>=a & n%a < b; a wins
    //   when n>=a & n%a >=b; b wins
    // case2: a <= b
    //   when n < a; a loses
    //   when n>=a; a wins
    // a=5, b=3
    // n=1 2 3 4 5 6 7 8 9 10111213
    // m=        0 1 2 3 4 5 6 7 8
    //   o o o o o o o o o o o o o
    //   l l l l w w w l l w w w l
    // r=x x x x 0 1 2 3 4 0 1 2 3
    // q=x x x x 0 0 0 0 0 1 1 1 1

    if (n<a) cout << 0 << endl;
    else {
        if (a<=b) {
            cout << n-a+1 << endl;
        }
        else {
            ll res = 0;
            ll m = n-a;
            ll r = m%a;
            ll q = m/a;
            // r = 0 ... b ... a-1
            res += q*b;
            res += min(b, r+1);
            cout << res << endl;
        }
    }
    return 0;
}

