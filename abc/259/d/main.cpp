#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <tuple>
#include <cmath>

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


double dist(ll a_x, ll a_y, ll b_x, ll b_y) {
    double dist = sqrt(((double)a_x - (double)b_x)*(a_x - b_x)+((double)a_y - (double)b_y)*(a_y - b_y));
    return dist;
}


bool isAdj(ll a_x, ll a_y, ll a_r, ll b_x, ll b_y, ll b_r) {
    // double d = dist(a_x, a_y, b_x, b_y);
    bool cond1 = (a_x - b_x)*(a_x - b_x)+(a_y - b_y)*(a_y - b_y) <= (a_r+b_r)*(a_r+b_r);
    bool cond2 = (a_x - b_x)*(a_x - b_x)+(a_y - b_y)*(a_y - b_y) >= (a_r-b_r)*(a_r-b_r);
;
    // cout << "isAdj >>>>> " << endl;
    // cout << "a_r: " << a_r << " b_r: " << b_r << endl;
    // cout << "dist between (" << a_x << ", " << a_y << ") and (" << b_x << ", " << b_y << ") is " << d << endl;
    // cout << "cond1 (" << d << " <= " << a_r+b_r << ") is " << cond1 << endl;
    // cout << "cond2 (" << d << " >= " << abs(a_r-b_r) << ") is " << cond2 << endl;
    return cond1 && cond2;
}

vi findCircleInd(ll x, ll y, const vector<tuple<ll, ll, ll> > &pts) {
    vi inds;
    int i = 0;
    for (const auto& [a_x, a_y, a_r] : pts){
        // auto d = dist(x, y, a_x, a_y);
        // cout << "d: " << d << " a_r: " << a_r << " d-ar: " << d - a_r << endl;
        if ((a_x - x)*(a_x - x)+(a_y - y)*(a_y - y)==a_r*a_r) inds.pb(i);
        i++;
    }
    return inds;
}

void dfs(int start, vector<bool>& visited, const vector<vi>& adj)
{
 
    visited[start] = true;
 
    for (int i = 0; i < adj[start].size(); i++) {
 
        if (adj[start][i] == 1 && (!visited[i])) {
            dfs(i, visited, adj);
        }
    }
}

int main() {
    int N;
    cin >> N;
    ll s_x, s_y, t_x, t_y;
    cin >> s_x >> s_y >> t_x >> t_y;

    vector<tuple<ll, ll, ll> > pts;
    rep(i, N) {
        ll x, y, r;
        cin >> x >> y >> r;
        pts.pb(make_tuple(x, y, r));
    }
    
    vector<vi> adj(N, vi(N, 0));
    rep(i, N-1) {
        reps(j, i+1, N) {
            auto [a_x, a_y, a_r] = pts[i];
            auto [b_x, b_y, b_r] = pts[j];
            if (isAdj(a_x, a_y, a_r, b_x, b_y, b_r)) {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }

    // cout << "adj:" << endl;
    // for (auto a : adj) {
    //     print(a);
    // }

    auto start_cand = findCircleInd(s_x, s_y, pts);
    auto end_cand = findCircleInd(t_x, t_y, pts);
    // cout << "start_cand for (" << s_x << ", " << s_y << ") is ";
    // print(start_cand);
    // cout << "end_cand for (" << t_x << ", " << t_y << ") is ";
    // print(end_cand);

    bool res = false;
    for (auto s : start_cand) {
        for (auto t : end_cand) {
            vector<bool> visited(N, false);
            dfs(s, visited, adj);
            if (visited[t]) {
                res = true;
                break;
            }
        }
        if (res) break;
    }

    YesNo(res);
    return 0;
}

