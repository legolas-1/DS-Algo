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
const int maxn = 1e6+4;
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
    Disjoint Set Union is very simple to implement
    but is a very powerful data structure
    we can join two disjoint set in O(logn) and
    find their parent node in O(log*n)
*/

int A[maxn];
int size[maxn];

void init(int n){                 // initilize all values , all nodes are parent of themselves
    for(int i=1;i<=maxn;i++){
        A[i] = i;
        size[i] = 1;
    }
}

int find(int node){                // finding node of parent
    while(A[node] != node){
        A[node] = A[A[node]];
        node = A[node];
    }
    return node;
}

void join(int node1,int node2){ // combining two set together
    int node1par = find(node1);
    int node2par = find(node2);

    if(node1par == node2par)
        return ;

    if(size[node1par] > size[node2par]){
        A[node2par] = A[node1par];
        size[node1par] += size[node2par];
    }
    else{
        A[node1par] = A[node2par];
        size[node2par] += size[node1par];
    }
}

bool equal(int node1,int node2){
    if(find(node1) == find(node2)){
        return true;
    }else{
        return false;
    }
}

int main()
{
    fast_io();

    init(maxn);
    int query;
    cin >> query;

    while(query--){
        int type;
        cin >> type;
        if(type == 1){
            int first,second;
            cin >> first >> second;
            join(first,second);
        }else if(type == 2){
            int first,second;
            cin >> first >> second;
            cout << equal(first,second) << "\n";
        }
    }

    return 0;
}

/*
    Testcase to check:
    9
    1 1 2
    1 2 3
    1 3 4
    1 5 6
    1 6 7
    1 7 8
    2 1 5
    1 1 5
    2 1 5

    Output:
    0
    1
*/
