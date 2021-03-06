#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ldb;
typedef vector<ll> vll;
typedef ll __T;
typedef tree<__T, null_type, less<__T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ff first
#define ss second
#define pll pair<ll,ll>
#define CL(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)x.size())
#define lp0(i,n) for(ll i=0;i<n;i++)
#define lp1(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define mpr make_pair
#define op(a) cout << a << "\n";
#define tc ll testcase; cin>>testcase; while(testcase--)
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(x)                     cout <<"lol"<<x<<"\n";
#define trace1(x)                cout <<#x<<":"<<x<< endl;
#define trace2(x, y)             cout <<#x<<":"<<x<<" | "<<#y<<":"<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<":"<<x<<" | "<<#y<<":"<<y<<" | "<<#z<<":"<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<" | "<<#d<<":"<<d<<endl;

const ll mod = 1e9+7;
const ldb PI = acos(-1);
const ll maxn = 1e6+4;
ll POWER[65];
void precompute() {POWER[0]=1; for(ll i=1;i<63;i++) POWER[i]=POWER[i-1]<<1LL; }
ll fastMul(ll a,ll b,ll mod){ll res = 0; a %= mod; while (b){   if (b & 1){res = (res + a) % mod;} a = (2 * a) % mod; b >>= 1;} return res;}
ll power(ll x,ll y,ll mod2) {ll res=1; x%=mod2; while(y) {if(y&1) res=fastMul(res,x,mod2); y>>=1; x=fastMul(x,x,mod2); }return res;}
ll inv(ll x,ll mod){return power(x,mod-2,mod);}

// freopen("testfile.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// order_of_key , find_by_order

/* Look at the stars , look how they shine for you ! */

/*
    Binary index tree is also a very powerful data structure
    to implement range queries , this is less powerful than segment tree
    to do query on BIT function must have inverse of it .
    but it is very simpiler to code and take O(n) also works on bits
    which makes its constant before logn small.
    both update and query are done in O(logn) time
*/
int BIT[maxn];
int A[maxn];

void update(int idx,int val){
    for(;idx<maxn;idx+=idx&-idx)
        BIT[idx] += val;
}

int query(int idx){
    int res = 0;
    for(;idx>0;idx-=idx&-idx)
        res += BIT[idx];
    return res;
}

int main()
{
    int n,q,k;
    cin >> n >> q >> k;

    for(int i=1;i<=n;i++){
        cin >> A[i];
        update(i,A[i]);
    }

    while(q--)
    {
        int a;
        cin >> a;

        if(a == 1){
            int p,val;
            cin >> p >> val;
            update(p,val); // add val to index p
        }else if(a == 2){
            int start,end;
            cin >> start >> end;
            cout << query(end) - query(start-1) << "\n"; // range sum from [start,end]
        }
    }

    return 0;
}


/*
    Testcase to check:
    5 4 1
    1 2 3 4 5
    1 1 2
    2 1 2
    1 3 4
    2 1 5

    Output:
    5
    21
*/
