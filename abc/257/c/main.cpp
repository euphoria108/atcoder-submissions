#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <deque>

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
    // f(X) = max_{X} sum_i [I(s_i==0 && W_i < X) + I(s_i==1 && W_i >=X)]
    // 1 0 1 0 1
    // 60 45 30 40 80
    //
    // sort by weight
    // 30 40 45 60 80
    // 1 0 0 1 1
    // child cumsum (from left)  : 0 1 2 2 2
    // adult cumsum (from right) : 3 2 2 2 1

    int N;
    cin >> N;
    string S;
    cin >> S;
    vi Svec(N);
    rep(i, N) {
        if (S.at(i)=='0') Svec.at(i) = 0;
        else Svec.at(i) = 1;
    }
    vll W(N);
    rep(i, N) cin >> W.at(i);

    vector<pair<ll, int> > p;
    rep(i, N) {
        p.push_back(make_pair(W.at(i), Svec.at(i)));
    }
    sort(p.begin(), p.end());

    vi ch(N);
    rep(i, N) {
        auto [w, s] = p.at(i);
        if (s==0){
            if (i==0) ch.at(i) = 1;
            else ch.at(i) = ch.at(i-1) + 1;
        }
        else {
            if (i==0) ch.at(i) = 0;
            else ch.at(i) = ch.at(i-1);

        }
    }

    vi ad(N);
    for (int i=N-1; i>=0; i--){
        auto [w, s] = p.at(i);
        if (s==1){
            if (i==N-1) ad.at(i) = 1;
            else ad.at(i) = ad.at(i+1) + 1;
        }
        else {
            if (i==N-1) ad.at(i) = 0;
            else ad.at(i) = ad.at(i+1);
        }
    }

    // cout << "ch: ";
    // print(ch);
    // cout << "ad: ";
    // print(ad);

    map<ll, int> chm, adm;
    rep(i, N) {
        auto [w, s] = p.at(i);
        chm[w] = max(chm[w], ch.at(i));
        adm[w] = max(adm[w], ad.at(i));
    }

    

    deque<int> chv, adv;
    auto iad = adm.begin();
    auto ich = chm.begin();
    while (iad != adm.end()) {
        adv.push_back(iad->second);
        chv.push_back(ich->second);
        iad++;
        ich++;
    }
    adv.push_back(0);
    chv.push_front(0);

    // cout << "chv: " << endl;
    // for (auto v : chv) {
    //     cout << v << endl;
    // }
    // cout << "adv: " << endl;
    // for (auto v : adv) {
    //     cout << v << endl;
    // }

    int max_sum = 0;
    auto iad2 = adv.begin();
    auto ich2 = chv.begin();
    while (iad2 != adv.end()) {
        auto ad_v = *iad2;
        auto ch_v = *ich2;
        max_sum = max(ad_v+ch_v, max_sum);
        iad2++;
        ich2++;
    }

    cout << max_sum << endl;

    return 0;
}

