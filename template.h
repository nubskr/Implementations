#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<typename T>
using ordered_set = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
#define        int               long long
#define        pb                push_back
#define        mp                make_pair
#define        nl                '\n'
#define        sz(v)             ((int)(v).size())
#define        fs                first
#define        exetime           cerr << "\nTime Elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"
#define        se                second
#define        all(x)            (x).begin(),(x).end()
#define        rall(x)           (x).rbegin(),(x).rend()
#define        rep(i,a,b)        for(int i=a;i<b;i++)
#define        per(i,a,b)        for(int i=b-1;i>=a;i--)
#define        trav(a,x)         for(auto &a:x)
#define        vin(x)            trav(i,x){cin>>i;}
#define        outv(x)            trav(i,x){cout<<i<<' ';} cout << '\n';
template<typename T,typename T1>T chkmax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T chkmin(T &a,T1 b){if(b<a)a=b;return a;}
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef pair <int, int> pi;
typedef map<int, int> mi;
typedef set <int> si;
typedef set <pair<int,int>> sii;
template<typename... T>
void rd(T&... args) {
    ((cin >> args), ...);
}
template<typename... T>
void wr(T&&... args) {
    ((cout << args << ' '), ...);
}
template<typename... T>
void wt(T&&... args) {
    ((cout << args << '\n'), ...);
}
#ifdef nubskr
#include</home/nubskr/debug.h>
#else
#define deb(...)
#define debv(a)
#define debp(a)
#endif

void solve(){

}

int32_t main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    exetime;
}
