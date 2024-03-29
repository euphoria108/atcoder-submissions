#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>

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

void makeCombiUtil(vector<vector<int> >& ans,
    vector<int>& tmp, int n, int left, int k)
{
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }
 
    for (int i = left; i <= n; ++i)
    {
        tmp.push_back(i);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);
 
        tmp.pop_back();
    }
}
 
vvi makeCombi(int n, int k)
{
    vvi ans;
    vi tmp;
    makeCombiUtil(ans, tmp, n, 1, k);
    return ans;
}

bool solve(vvi a, vvi b, vvi row_cand, vvi col_cand, int h1, int w1, int h2, int w2) {
    for (auto row_ind : row_cand) {
        for (auto col_ind : col_cand) {
            // reduce matrix a
            vvi new_a;
            rep(i, h1) {
                if (find(row_ind.begin(), row_ind.end(), i)==row_ind.end()) continue;
                vi new_row;
                rep(j, w1) {
                    if (find(col_ind.begin(), col_ind.end(), j)==col_ind.end()) continue;
                    new_row.pb(a[i][j]);
                }
                new_a.pb(new_row);
            }

            // compare
            rep(i, h2) {
                rep(j, w2) {
                    if (new_a[i][j]!=b[i][j]) continue;
                }
            }
            cout << "new a" << endl;
            rep(i, h2) print(new_a[i]);

            cout << "b" << endl;
            rep(i, h2) print(b[i]);
            return true;
        }
    }
    return false;
}

int main() {
    int h1, w1;
    cin >> h1 >> w1;
    vvi a(h1, vi(w1));
    rep(i, h1) rep(j, w1) cin >> a[i][j];
    int h2, w2;
    cin >> h2 >> w2;
    vvi b(h2, vi(w2));
    rep(i, h2) rep(j, w2) cin >> b[i][j];

    vvi row_cand = makeCombi(h1, h2);
    vvi col_cand = makeCombi(w1, w2);

    auto res = solve(a, b, row_cand, col_cand, h1, w1, h2, w2);
    YesNo(res);

    return 0;
}

