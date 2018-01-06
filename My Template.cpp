#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define DEBUG cout<<"ok"<<endl;
#define _(x) cout<< #x<<"->"<<x
#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)
#define set(N,pos) N|1<<pos
#define reset(N,pos) N&~(1<<pos)
#define toggle(N,pos) N^1<<pos
#define check(N,pos) N&1<<pos
#define uptoKsame(N,k) N&((1<<k)-1)
#define FAST_LOG2(x) (sizeof(unsigned long)*8 - 1 - __builtin_clzl((unsigned long)(x)))
#define FAST_LOG2_UP(x) (((x) - (1 << FAST_LOG2(x))) ? FAST_LOG2(x) + 1 : FAST_LOG2(x))
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
template <class T> T power(T x,T n){ if(n==0) return 1; return x*pow(x,n-1);} 
template <class T> T bigmod(T a,T b,T M){ if(b==0)return 1%M; T x=bigmod(a,b/2,M); x=(x*x)%M; if(b%2) x=(x*a%M)%M; return x; }
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main()
{
    cout<<power(3,3);
    cout<<bigmod(2,1000000,10000);
}
