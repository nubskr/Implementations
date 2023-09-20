
#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3,unroll-loops")
#define        pb                push_back
#define        int               long long
#define        sz(v)             ((int)(v).size())
#define        nl                '\n'
#define        se                second
#define        fs                first
#define        rall(x)           (x).rbegin(),(x).rend()
#define        all(x)            (x).begin(),(x).end()
#define        trav(a,x)         for(auto &a:x)
#define        per(i,a,b)        for(int i=b-1;i>=a;i--)
#define        rep(i,a,b)        for(int i=a;i<b;i++)
typedef vector<int> vi;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T,typename T1>T chkmin(T &a,T1 b){if(b<a)a=b;return a;}
template<typename T,typename T1>T chkmax(T &a,T1 b){if(b>a)a=b;return a;}
#ifdef DEBUG
#include</home/nubskr/debug.h>
#else
#define deb(...) 44
#define debv(a) 44
#define debp(a) 44
#endif


const int MOD = 1e9 + 7;


int modpow(int b,int e) {
    int ans = 1;
    for (; e; b = b * b % MOD, e /= 2)
        if (e & 1) ans = ans * b % MOD;
    return ans;
}


const int N = 1e5;

int a[N][2];

int gogo(int idx,int prev){
	if(idx==n){
		// base case 1
	}
	if(prev){
		// base case 2
	}
	int &ans = a[idx][prev];
	if(ans==-1){
		// whatever
	}
	return ans;
}

int32_t main(){ios::sync_with_stdio(0); cin.tie(0); // use functions above this
auto solve = [&]() {
    int n;
    cin >> n;
    rep(i,0,n){
    	rep(j,0,2){
    		a[i][j] = -1;
    	}
    }
    vector<int> v(n);
    trav(i,v){
    	cin >> i;
    }
    cout << gogo(0,0) << nl;
};

int t = 1;
cin >> t;

rep(_i,1,t+1){
    //cout << "Case #" << _i << ": ";
    solve();
}
cerr << "\nTime Elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
